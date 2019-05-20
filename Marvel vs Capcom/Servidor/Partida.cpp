#include "Partida.h"
#include <iostream>
void Partida::IniciarPartida() {
	listaJugadores = listaEspera;
	listaEspera.clear();
	partidaIniciada = true;
	modelo->inicializar();
	ActualizarModelo();
	modelo->getEquipoNro(0)->getJugadorActivo()->setPosX(120);
	modelo->getEquipoNro(0)->getJugadorActivo()->setPosY(931);
	modelo->getEquipoNro(1)->getJugadorActivo()->setPosX(780);
	modelo->getEquipoNro(1)->getJugadorActivo()->setPosY(931);
}
ModeloEstado  Partida::GetModeloEstado(){
	ModeloEstado unModelo;
	unModelo = modelo->GetModelEstado();
	unModelo.activoEquipo1 = GetTitularJugando(0).numeroJugador;
	unModelo.activoEquipo2 = GetTitularJugando(1).numeroJugador;
	return unModelo;
}
void Partida::ActualizarModelo() {
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		if (it->titular == true) {
			modelo->getEquipoNro(it->equipo)->setJugadorActivo(it->numeroJugador);
		}
	}

}
void Partida::SetComando(int equipo, int comando){
	if((comando < 8 )&& (comando >= 0) && (equipo == 1)){
		cout << "Equipo: " << equipo<< endl;
		cout << "Comando: " << comando<< endl;
		controlador->SetComando(equipo, comando);
		//modelo->update();
	}
	cout << "Pos X: " << modelo->getEquipoNro(1)->getJugadorActivo()->getPosX() << endl;
}
void Partida::SetModelo(Model* model) {
	modelo = model;
	controlador =  new Controller();
	controlador->SetModel(modelo);
}
Model * Partida::GetModelo(){
	return modelo;
}
Controller * Partida::GetControlador(){
	return controlador;
}
bool Partida::EquipoCompleto() {
	if (listaEspera.size() == maximoJugadores) {
		return true;
	}
	return false;
}
list<ClienteConectado> Partida::GetListaJugadores() {
	return listaJugadores;
}
list<ClienteConectado> Partida::GetListaEspera() {
	return listaEspera;
}
list<ClienteConectado> Partida::GetListaJugadores(int equipo) {
	ClienteConectado unCliente;
	list<ClienteConectado>::iterator it;
	list<ClienteConectado> listaTmp;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		if (it->equipo == equipo) {
			listaTmp.push_back(*it);
		}
	}
	return listaTmp;
}
void Partida::FinalizarPartida() {
	partidaFinalizada = true;
}
bool Partida::Iniciada() {
	return partidaIniciada;
}
bool Partida::Finalizada() {
	return partidaFinalizada;
}
void Partida::SetMaximoJugadores(int max) {
	maximoJugadores = max;
}
void Partida::EliminarJugador(string nombre) {
	list<ClienteConectado>::iterator it;
	it = listaJugadores.begin();
	bool encontrado = false;
	while ((it != listaJugadores.end()) && !encontrado) {
		if (it->nombre == nombre) {
			listaJugadores.erase(it);
			encontrado = true;
		}
		it++;
	}
}
void Partida::EliminarDesconectado(string nombre) {
	list<ClienteConectado>::iterator it;
	it = listaDesconectados.begin();
	bool encontrado = false;
	while ((it != listaDesconectados.end()) && !encontrado) {
		if (it->nombre == nombre) {
			listaDesconectados.erase(it);
			encontrado = true;
		}
		it++;
	}
}
void Partida::JugadorDesconectado(string nombre) {
	ClienteConectado unCliente;
	unCliente = GetClienteJugando(nombre);
	if (unCliente.titular) {
		if (TieneSuplente(unCliente.equipo)) {
			//Suplente ocupa el lugar del titular
			JuegaSuplente(unCliente.equipo);
		} else {
			partidaFinalizada = true;
		}
	}
	//Borra de lista de jugadores
	EliminarJugador(nombre);
	// Agrego a la lista de desconectados
	listaDesconectados.push_back(unCliente);

}
void Partida::JuegaTitular(int equipo, ClienteConectado reconectado) {
	list<ClienteConectado>::iterator it;
	it = listaJugadores.begin();
	bool encontrado = false;
	while ((it != listaJugadores.end()) && !encontrado) {
		if ((it->equipo == equipo) && it->titular) {
			encontrado = true;
			it->titular = false;
		}
		it++;
	}
	ActualizarModelo();
}
bool Partida::TieneSuplente(int equipo) {
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		if ((it->equipo == equipo) && (!it->titular)) {
			return true;
		}
	}
	return false;
}
// Cuando se eliminar un juegador juega el suplente.
void Partida::JuegaSuplente(int equipo) {
	list<ClienteConectado>::iterator it;
	it = listaJugadores.begin();
	bool encontrado = false;
	while ((it != listaJugadores.end()) && !encontrado) {
		if ((it->equipo == equipo) && !it->titular) {
			encontrado = true;
			it->titular = true;
		}
		it++;
	}
	ActualizarModelo();
}
void Partida::AgregarCliente(ClienteConectado * cliente) {
	if (!partidaIniciada) {
		int cantidad = listaEspera.size();
		if (cantidad < 2) {
			cliente->titular = true;
		} else {
			cliente->titular = false;
		}
		// Seleccion de equipos
		cantidad++;
		if (cantidad % 2 == 0) {
			cliente->numeroJugador = cantEquipo0;
			cliente->equipo = 0;
			cantEquipo0++;
		} else {
			cliente->numeroJugador = cantEquipo1;
			cliente->equipo = 1;
			cantEquipo1++;
		}
		listaEspera.push_back(*cliente);
	} else {
		// Equipo 0 se usa para verificar que no es un Cliente reconectado.
		if (EsClienteDesconectado(cliente->nombre)) {
			//Recupero el equipo para el cliente reconectado.
			ClienteConectado unClienteDesconectado;
			unClienteDesconectado = GetClienteDesconectado(cliente->nombre);
			cliente->equipo = unClienteDesconectado.equipo;
			//Es cliente reconectado?
			if (unClienteDesconectado.titular) {
				// El cliente reconectado era titular
				JuegaTitular(unClienteDesconectado.equipo, *cliente);
				cliente->titular = true;
				//Agrego a la lista de jugadores
				listaJugadores.push_back(*cliente);
			} else {
				//El cliente era suplente.
				cliente->titular = false;
				listaJugadores.push_back(*cliente);
			}
			//Elimino de la lista de desconectados
			EliminarDesconectado(cliente->nombre);
		}
	}
}
ClienteConectado Partida::GetClienteJugando(string nombre) {
	ClienteConectado unCliente;
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		if (it->nombre == nombre) {
			unCliente = *it;
		}
	}
	return unCliente;
}
ClienteConectado Partida::GetTitularJugando(int equipo) {
	ClienteConectado unCliente;
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		if ((it->titular) && (it->equipo == equipo)) {
			unCliente = *it;
		}
	}
	return unCliente;
}
ClienteConectado Partida::GetClienteEspera(string nombre) {
	ClienteConectado unCliente;
	list<ClienteConectado>::iterator it;
	for (it = listaEspera.begin(); it != listaEspera.end(); it++) {
		if (it->nombre == nombre) {
			unCliente = *it;
		}
	}
	return unCliente;
}

ClienteConectado Partida::GetClienteDesconectado(string nombre) {
	ClienteConectado unCliente;
	list<ClienteConectado>::iterator it;
	for (it = listaDesconectados.begin(); it != listaDesconectados.end();
			it++) {
		if (it->nombre == nombre) {
			unCliente = *it;
		}
	}
	return unCliente;
}
bool Partida::EsClienteDesconectado(string nombre) {
	ClienteConectado unCliente;
	list<ClienteConectado>::iterator it;
	for (it = listaDesconectados.begin(); it != listaDesconectados.end();
			it++) {
		if (it->nombre == nombre) {
			return true;
		}
	}
	return false;
}
int Partida::GetCantidadJugando() {
	return listaJugadores.size();
}
int Partida::GetCantidadJugando(int equipo) {
	int contador = 0;
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		// Seleccion de titularidad
		if (it->equipo == equipo) {
			contador++;
		}
	}
	return contador;
}
int Partida::GetCantidadDesconectados() {
	return listaDesconectados.size();
}
int Partida::GetCantidadEspera() {
	return listaEspera.size();
}

