#include "Partida.h"
#include <iostream>
void Partida::IniciarPartida() {
	listaJugadores = listaEspera;
	listaEspera.clear();
	partidaIniciada = true;
	ActualizarModelo();
}
ModeloEstado  Partida::GetModeloEstado(){
	ModeloEstado unModeloEstado;

	unModeloEstado.jugadoresEquipo1.posX = modelo->getEquipoNro(0)->getJugadorActivo()->getPosX();
	unModeloEstado.jugadoresEquipo1.posY = modelo->getEquipoNro(0)->getJugadorActivo()->getPosY();

	unModeloEstado.jugadoresEquipo2.posX = modelo->getEquipoNro(1)->getJugadorActivo()->getPosX();
	unModeloEstado.jugadoresEquipo2.posY = modelo->getEquipoNro(1)->getJugadorActivo()->getPosY();


	return unModeloEstado;
}
void Partida::ActualizarModelo() {
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		if (it->titular == true) {
			modelo->getEquipoNro(it->equipo)->setJugadorActivo(1);
		}
	}

}
void Partida::SetModelo(Model* model) {
	modelo = model;
}
Model * Partida::GetModelo(){
	return modelo;
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
	//ActualizarModelo();

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
}
void Partida::AgregarCliente(ClienteConectado cliente) {
	if (!partidaIniciada) {
		int cantidad = listaEspera.size();
		if (cantidad < 2) {
			cliente.titular = true;
		} else {
			cliente.titular = false;
		}
		// Seleccion de equipos
		cantidad++;
		if (cantidad % 2 == 0) {
			cliente.equipo = 0;
		} else {
			cliente.equipo = 1;
		}
		listaEspera.push_back(cliente);
	} else {
		// Equipo 0 se usa para verificar que no es un Cliente reconectado.
		if (EsClienteDesconectado(cliente.nombre)) {
			//Recupero el equipo para el cliente reconectado.
			ClienteConectado unClienteDesconectado;
			unClienteDesconectado = GetClienteDesconectado(cliente.nombre);
			cliente.equipo = unClienteDesconectado.equipo;
			//Es cliente reconectado?
			if (unClienteDesconectado.titular) {
				// El cliente reconectado era titular
				JuegaTitular(unClienteDesconectado.equipo, cliente);
				cliente.titular = true;
				//Agrego a la lista de jugadores
				listaJugadores.push_back(cliente);
			} else {
				//El cliente era suplente.
				cliente.titular = false;
				listaJugadores.push_back(cliente);
			}
			//Elimino de la lista de desconectados
			EliminarDesconectado(cliente.nombre);
			ActualizarModelo();
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

