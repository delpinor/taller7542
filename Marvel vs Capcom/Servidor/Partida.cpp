#include "Partida.h"
#include <iostream>
#define DURACIONMENSAJE 3
void Partida::IniciarPartida() {
	//listaJugadores = listaEspera;
	//listaEspera.clear();
	modelo->inicializar();
	IniciarBatalla();
	cout << "Esperando confimacion de carga de los clientes..." << endl;
	while(!ClientesCargados()){
		usleep(10);
	}
	cout << "Carga de clientes complete. Inicia la partida..." << endl;
	partidaIniciada = true;

}
void Partida::IniciarBatalla(){
	this->IniciarTitularidadClientes();
	ActualizarModelo();
	this->IniciarPosiciones();
	this->IniciarCamara();
	this->roundActual++;
	cout << "Iniciando Batalla " << this->roundActual << endl;
	this->cronometro = this->tiempoRound;
	this->modelo->InicializarVidas();
	this->roundCorriendo = true;
}
void Partida::IniciarPosiciones(){
	modelo->getEquipoNro(0)->getJugadorActivo()->setPosX(120 - 80);
	modelo->getEquipoNro(0)->getJugadorActivo()->setPosY(931);
	modelo->getEquipoNro(1)->getJugadorActivo()->setPosX(780 - 80);
	modelo->getEquipoNro(1)->getJugadorActivo()->setPosY(931);
}
void Partida::IniciarCamara(){
	int CAMARAPOSICIONINICIALX = ANCHO_NIVEL / 2 - modelo->ancho_Pantalla / 2;
	int CAMARAPOSICIONINICIALY = ALTO_NIVEL / 2 - modelo->alto_Pantalla / 2;
	camaraStatic = {CAMARAPOSICIONINICIALX,CAMARAPOSICIONINICIALY, modelo->ancho_Pantalla, modelo->alto_Pantalla};
	camara = &(camaraStatic);
	modelo->setCamara(this->camara);
	//	modelo->inicializarPosicionesEquipos();
	AjustarCamara();
}
bool Partida::ClientesCargados(){
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		if (!it->cargaCompleta) {
			return false;
		}
	}
	return true;
}
void Partida::IniciarTitularidadClientes(){
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		if (it->titularEquipo) {
			it->titular = true;
		}else{
			it->titular = false;
		}
	}
}
void Partida::AjustarCamara() {
	// Este codigo se puede mejorar.
	int posXJugador1 = modelo->getEquipoNro(0)->getJugadorActivo()->getPosX();
	int posYJugador1 = modelo->getEquipoNro(0)->getJugadorActivo()->getPosY();
	int posXJugador2 = modelo->getEquipoNro(1)->getJugadorActivo()->getPosX();
	int posYJugador2 = modelo->getEquipoNro(1)->getJugadorActivo()->getPosY();
	//
	int anchoJugador1 =
			modelo->getEquipoNro(0)->getJugadorActivo()->get_ancho();

	int anchoJugador2 =
			modelo->getEquipoNro(1)->getJugadorActivo()->get_ancho();

	//Chequeo que los jugadores no se salgan del escenario
	if (posXJugador1 + anchoJugador1 > ANCHO_NIVEL)
		modelo->getEquipoNro(0)->getJugadorActivo()->setPosX(
				ANCHO_NIVEL - anchoJugador1);

	if (posXJugador2 + anchoJugador2 > ANCHO_NIVEL)
		modelo->getEquipoNro(1)->getJugadorActivo()->setPosX(
				ANCHO_NIVEL - anchoJugador2);

	if (posXJugador1 < 0) {
		modelo->getEquipoNro(0)->getJugadorActivo()->setPosX(0);
		posXJugador1 = 0;
	}
	if (posXJugador2 < 0) {
		modelo->getEquipoNro(1)->getJugadorActivo()->setPosX(0);
		posXJugador2 = 0;
	}

	//Muevo la cámara si algún jugador se está saliendo de ella
	if (posXJugador1 + anchoJugador1 > this->camara->x + this->camara->w)
		this->camara->x +=
				modelo->getEquipoNro(0)->getJugadorActivo()->estado->getVelX();
	else if (posXJugador1 < this->camara->x)
		this->camara->x = posXJugador1;

	if (posXJugador2 + anchoJugador2 > this->camara->x + this->camara->w)
		this->camara->x +=
				modelo->getEquipoNro(1)->getJugadorActivo()->estado->getVelX();
	else if (posXJugador2 < this->camara->x)
		this->camara->x = posXJugador2;

	//Keep the this->camara->in bounds
	if (this->camara->x < 0) {
		this->camara->x = 0;
	}
	if (this->camara->y < 0) {
		this->camara->y = 0;
	}
	if (this->camara->x > ANCHO_NIVEL - this->camara->w) {
		this->camara->x = ANCHO_NIVEL - this->camara->w;
	}
	if (this->camara->y > ALTO_NIVEL - this->camara->h) {
		this->camara->y = ALTO_NIVEL - this->camara->h;
	}
}

ModeloEstado Partida::GetModeloEstado() {
	ModeloEstado unModelo;
	unModelo = modelo->GetModelEstado();
	//	unModelo.activoEquipo1 = GetTitularJugando(0).numeroJugador;
	//	unModelo.activoEquipo2 = GetTitularJugando(1).numeroJugador;
	unModelo.activoEquipo1 = modelo->equipos[0]->nroJugadorActivo;
	unModelo.activoEquipo2 = modelo->equipos[1]->nroJugadorActivo;
	return unModelo;
}
ModeloInGame Partida::GetModeloGame(){
	ModeloInGame unModelo;
	unModelo = modelo->GetModeloInGame();

	if(tiempoRound < (cronometro+DURACIONMENSAJE)){
		unModelo.tipoMensaje = READY;
		std::string msg = "Ronda " + std::to_string(roundActual);
		strcpy(unModelo.mensaje, msg.c_str());


	}else{
		unModelo.tipoMensaje = NINGUNO;
	}
	return unModelo;
}
ModeloPersonajes Partida::GetModeloPersonajes(){
	ModeloPersonajes unModelo;
	list<int> idsPersonajes = this->modelo->GetIdsPersonajes();

	unModelo.cantidadPersonajes = idsPersonajes.size();

	int contador = 0;
	std::list<int>::iterator itpersonajes;
	for (itpersonajes = idsPersonajes.begin(); itpersonajes != idsPersonajes.end(); itpersonajes++) {
		unModelo.idsPersonajes[contador] = *itpersonajes;
		cout << "PARTIDA - GetModeloPersonajes:  | Valor de i "<< contador << " | Personaje" << *itpersonajes << " | " << TimeHelper::getStringLocalTimeNow() << endl;
		contador++;
	}

	return unModelo;
}
ModeloSeleccion  Partida::GetModeloSeleccion(){
	cout << "===============================CLIENTE - GetModeloSeleccion: | " << TimeHelper::getStringLocalTimeNow() << "===============================" << endl;
	ModeloSeleccion unModelo;
	unModelo.seleccionFinalizada = FinalizadaSeleccionPersonajes();
	unModelo.cantidadData = listaJugadores.size();
	list<ClienteConectado>::iterator it;
	int contador = 0;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {

		//cout << "CLIENTE - GetModeloSeleccion: INICIADO | "<< it->nombre << " | " << TimeHelper::getStringLocalTimeNow() << endl;

		ModeloSeleccionPersonaje unModeloSeleccionPersonaje;
		unModeloSeleccionPersonaje.jugadorId = it->numeroJugadorJuego;
		unModeloSeleccionPersonaje.numeroJugador = it->numeroJugador;
		unModeloSeleccionPersonaje.equipo = it->equipo;


		unModeloSeleccionPersonaje.personajeId = it->personajeId;
		unModeloSeleccionPersonaje.confirmado =  it->personajeConfirmado;
		if(PersonajesSeleccionCompletaTitular() && it->cantidadPersonajes == 2){
			unModeloSeleccionPersonaje.personajeId = it->personajeIdSuplente;
			unModeloSeleccionPersonaje.confirmado = it->personajeConfirmadoSuplente;
		}

		unModelo.data[contador] = unModeloSeleccionPersonaje;
		contador++;
		//cout << "CLIENTE - GetModeloSeleccion: FINALIZADO | "<< it->nombre << " | " << TimeHelper::getStringLocalTimeNow() << endl;
	}

	cout << "Despues de correr" << endl;
	for (int i =0; i < unModelo.cantidadData; i++) {

		cout << "| JugadorId: " << unModelo.data[i].jugadorId
				<< " | Equipo: " << unModelo.data[i].equipo
				<< " | Numero Jugador: " << unModelo.data[i].numeroJugador
				<< " | Persoaje ID: " << unModelo.data[i].personajeId
				<< " | Confirmado: " << unModelo.data[i].confirmado
				<< endl;
	};

	cout << "===============================CLIENTE - GetModeloSeleccion EJECUTADO| " << TimeHelper::getStringLocalTimeNow() << "===============================" << endl;
	//cout << "CLIENTE - GetModeloSeleccion EJECUTADO | " << TimeHelper::getStringLocalTimeNow() << endl;
	return unModelo;
}
void  Partida::SetJugadoresPersonajeInicial(){

	list<ClienteConectado>::iterator it;
	list<int> idsPersonajes = this->modelo->GetIdsPersonajes();
	int contador = 1;
	int cantidadPersonajes = idsPersonajes.size();

	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		ModeloSeleccionPersonaje unModeloSeleccionPersonaje;

		int cantidadEquipo = this->GetCantidadJugando(it->equipo);
		if(cantidadEquipo == 2){
			it->cantidadPersonajes = 1;
		}
		else{
			it->cantidadPersonajes = 2;
		}

		list<int>::iterator itInt = idsPersonajes.begin();
		if(contador <= cantidadPersonajes){
			advance(itInt, contador -1);
			it->personajeId = *itInt;
		}
		else{
			advance(itInt, cantidadPersonajes -1);
			it->personajeId = *itInt;
		}
		contador = contador + 1;
	}
}
void Partida::ActualizarModelo() {
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		if (it->titular == true) {
			modelo->getEquipoNro(it->equipo)->setJugadorActivo(
					it->numeroJugador);
		}
	}

}
void Partida::SwapTitularSuplente(int equipo) {
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		if (it->equipo == equipo) {
			if (!it->titular) {
				it->titular = true;
			} else {
				it->titular = false;
			}
		}
	}
}
void Partida::SetComando(int equipo, int comando) {
	if (comando != 99) {
		if (comando == CAMBIAR_PERSONAJE) {
			if (TieneSuplente(equipo)) {
				SwapTitularSuplente(equipo);
			}
		}
		controlador->SetComando(equipo, comando);

	}

	//	modelo->update();
	//	AjustarCamara();

}
void Partida::SetModelo(Model* model) {
	modelo = model;
	controlador = new Controller();
	controlador->SetModel(modelo);

}
Model * Partida::GetModelo() {
	return modelo;
}
Controller * Partida::GetControlador() {
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
ClienteConectado * Partida::GetDesconectado(string nombre){
	ClienteConectado * unCliente;
	list<ClienteConectado>::iterator it;
	for (it = listaDesconectados.begin(); it != listaDesconectados.end();
			it++) {
		if (it->nombre == nombre) {
			unCliente = &(*it);
		}
	}
	return unCliente;
}
ClienteConectado * Partida::GetCliente(string nombre){
	ClienteConectado * unCliente;
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end();
			it++) {
		if (it->nombre == nombre) {
			unCliente = &(*it);
		}
	}
	return unCliente;
}
void Partida::JugadorDesconectado(string nombre) {
	ClienteConectado unCliente;
	unCliente = GetClienteJugando(nombre);

	//Borra de lista de jugadores
	EliminarJugador(nombre);

	//
//	unCliente.esperandoReconexion = true;

	// Lista desconectados
	listaDesconectados.push_back(unCliente);
	if (unCliente.titular) {
		if (TieneSuplente(unCliente.equipo)) {

			// No espera reconexion...
//			GetDesconectado(nombre)->esperandoReconexion = false;

			//Suplente ocupa el lugar del titular
			JuegaSuplente(unCliente.equipo);


		} else {
			partidaFinalizada = !jugadorReconectado(unCliente.equipo);
//			if(partidaFinalizada){
//				GetDesconectado(nombre)->esperandoReconexion = false;
//			}

		}
	}

}
void Partida::SwapPersonaje(int equipo){
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		if (it->equipo == equipo) {
			if (it->numeroJugador == 0) {
				it->numeroJugador = 1;
			} else {
				it->numeroJugador = 0;
			}
		}
	}
}
bool Partida::jugadorReconectado(int equipo) {
	int contador = 20;
	//Espero la cantidad de segundos indicado en la variable i
	for (int i = 0; i < contador; i++) {
		if(hayJugadorParaEquipo(equipo)){
			cout << "Jugador de equipo " << equipo << " se reconectó! La partida continú. "<< endl;
			return true;
		}
		cout << "Esperando que se reconecte en..." << contador - i << endl;
		sleep(2);
	}
	return false;
}

bool Partida::hayJugadorParaEquipo(int equipo) {
	ClienteConectado unCliente;
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		if (it->equipo == equipo)
			return true;
	}
	return false;
}
bool Partida::existeJugador(string nombre) {
	ClienteConectado unCliente;
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		if (it->nombre == nombre)
			return true;
	}
	return false;
}
int Partida::cantidadJugadoresConNombre(string nombre) {
	ClienteConectado unCliente;
	list<ClienteConectado>::iterator it;
	for (it = listaEspera.begin(); it != listaEspera.end(); it++) {
		if (it->nombre == nombre)
			return listaEspera.size();
	}
	return 0;
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
	//	ActualizarModelo();
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
void Partida::AgregarCliente(ClienteConectado * cliente) {
	if (!seleccionPersonajesIniciada && !EsClienteDesconectado(cliente->nombre)) {//if (!partidaIniciada) {
		int cantidad = listaEspera.size();
		if (cantidad < 2) {
			cliente->titular = true;
			cliente->titularEquipo = true;
		} else {
			cliente->titular = false;
			cliente->titularEquipo = false;
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
		cliente->numeroJugadorJuego = cantEquipo0 + cantEquipo1;

		cout << "PARTIDA - AgregarCliente: por agregar el cliente "<< cliente->nombre << " | "  << TimeHelper::getStringLocalTimeNow() << endl;
		listaEspera.push_back(*cliente);
		cout << "PARTIDA - AgregarCliente: la lista de espera tiene "<< listaEspera.size() << " | "  << TimeHelper::getStringLocalTimeNow() << endl;

	} else {
		cout << "PARTIDA - AgregarCliente: entro al else"<< cliente->nombre << " | "  << TimeHelper::getStringLocalTimeNow() << endl;

		// Equipo 0 se usa para verificar que no es un Cliente reconectado.
		if (EsClienteDesconectado(cliente->nombre)) {
			cout << "es un cliente desconectado " << endl;
			//Recupero el equipo para el cliente reconectado.
			ClienteConectado unClienteDesconectado;
			unClienteDesconectado = GetClienteDesconectado(cliente->nombre);
			cliente->equipo = unClienteDesconectado.equipo;
			cliente->personajeId = unClienteDesconectado.personajeId;
			cliente->personajeConfirmado = unClienteDesconectado.personajeConfirmado;
			cliente->numeroJugadorJuego = unClienteDesconectado.numeroJugadorJuego;
			cliente->dataPersonajesEnviada = unClienteDesconectado.dataPersonajesEnviada;
			cliente->numeroJugador = unClienteDesconectado.numeroJugador;
			cout << "Cliente reasignado a equipo: " << cliente->equipo
					<< " y a jugador: " << cliente->numeroJugador << endl;
			//Es cliente reconectado?
			if (!this->hayJugadorParaEquipo(cliente->equipo)){
				cliente->titular = true;
				cout << "Cliente reconectado pasa a ser TITULAR porque no había nadie de su equipo" << endl;
			}
			else if (unClienteDesconectado.numeroJugador
					== this->GetModelo()->equipos[unClienteDesconectado.equipo]->nroJugadorActivo) {
				// El cliente reconectado pasa a ser titular porque su personaje está peleando
				JuegaTitular(unClienteDesconectado.equipo, *cliente);
				cliente->titular = true;
				cout << "Cliente reconectado pasa a ser TITULAR porque estaba jugando su personaje" << endl;
			} else {
				//El cliente era suplente.
				cliente->titular = false;
				cout << "Cliente reconectado pasa a ser SUPLENTE porque NO estaba jugando su personaje" << endl;
			}
			//Agrego a la lista de jugadores
			listaJugadores.push_back(*cliente);
			cout << "Cliente reconectado agregado a listaJugadores" << endl;
			//Elimino de la lista de desconectados
			EliminarDesconectado(cliente->nombre);
			cout
			<< "Cliente reconectado eliminado de listaJugadoresDesconectados"
			<< endl;
		}
		else {
			//TODO rechazar cliente porque está lleno?
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
			cout << "Cliente desconectado con nombre: " << it->nombre << endl;
			cout << "Cliente reconectado con nombre: " << nombre << endl;
			return true;
		}
	}
	return false;
}
bool Partida::EsClienteDesconectadoBySock(int sock) {
	ClienteConectado unCliente;
	list<ClienteConectado>::iterator it;

	for (it = listaDesconectados.begin(); it != listaDesconectados.end();
			it++) {
		if (it->socket == sock) {
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
int Partida::GetCantidadEnEspera(int equipo) {
	int contador = 0;
	list<ClienteConectado>::iterator it;
	for (it = listaEspera.begin(); it != listaEspera.end(); it++) {
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

void Partida::IniciarSeleccionPersonajes(){
	listaJugadores = listaEspera;
	//	listaEspera.clear();
	this->SetJugadoresPersonajeInicial();
	this->seleccionPersonajesIniciada = true;
}
void Partida::DetenerJugadores(){
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		// Asigno a todos como suplentes para dejar de recibir comandos
		it->titular = false;
	}
}
string Partida::validarNombreUsuario(string nombreUsuario){
	cout << "nombre recibido: " << nombreUsuario << endl;
	int cantJugadoresConNombreIgual = this->cantidadJugadoresConNombre(nombreUsuario);
	std::ostringstream ss;
	ss << cantJugadoresConNombreIgual;
	if (cantJugadoresConNombreIgual > 0){
		cout << "nombre final: " << nombreUsuario + ss.str() << endl;
		return nombreUsuario + ss.str();
	}
	return nombreUsuario;
}

void Partida::FinalizarSeleccionPersonajes(){
	this->seleccionPersonajesFinalizada = true;
}

bool Partida::IniciadaSeleccionPersonajes(){
	return this->seleccionPersonajesIniciada;
}

bool Partida::FinalizadaSeleccionPersonajes(){
	return this->seleccionPersonajesFinalizada;
}

void Partida::HandleEventSeleccionPersonajes(string nombreJugador, DataSeleccionAlServidor *data){
	list<ClienteConectado>::iterator it;

	cout << "##########################INICIANDO Partida::HandleEventSeleccionPersonajes######################################33" << endl;
	cout << "Antes de iniciar" << endl;

	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {

		cout << "| Jugador: " << it->nombre
				<< " | Persoaje1Id: " << it->personajeId
				<< " | Persoaje2Id: " << it->personajeIdSuplente
				<< " | Persoaje1 Confirmado: " << it->personajeConfirmado
				<< " | Persoaje2 Confirmado: " << it->personajeConfirmadoSuplente
				<< " | Es Titular: " << it->titular
				<< endl;

		if(it->nombre == nombreJugador){
			if(PersonajesSeleccionCompletaTitular() && it->cantidadPersonajes == 2){
				it->personajeConfirmadoSuplente = data->confirmado;
				if (data->personajeId >= 0) {
					it->personajeIdSuplente = data->personajeId;
				}
			}else{
				it->personajeConfirmado = data->confirmado;
				if (data->personajeId >= 0) {
					it->personajeId = data->personajeId;
				}
				//Para que una vez confirmado, sea visible el puntero del segundo
				if(data->confirmado && it->cantidadPersonajes == 2){
					it->personajeIdSuplente = it->personajeId;
				}
			}
			//			it->personajeConfirmado = data->confirmado;
			//			if(data->personajeId >= 0){
			//				it->personajeId = data->personajeId;
			//			}
		}
	}

	cout << "Despues de correr" << endl;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {

		cout << "| Jugador: " << it->nombre
				<< " | Persoaje1Id: " << it->personajeId
				<< " | Persoaje2Id: " << it->personajeIdSuplente
				<< " | Persoaje1 Confirmado: " << it->personajeConfirmado
				<< " | Persoaje2 Confirmado: " << it->personajeConfirmadoSuplente
				<< " | Es Titular: " << it->titular
				<< endl;
	}
	cout << "##########################FIN Partida::HandleEventSeleccionPersonajes######################################33" << endl;
}

bool Partida::PersonajesSeleccionCompleta(){
	if(PersonajesSeleccionCompletaTitular() && PersonajesSeleccionCompletaSuplente()){
		return true;
	}
	else{
		return false;
	}

	//	list<ClienteConectado>::iterator it;
	//	int personajeIdNoValido = static_cast<int>(PERSONAJE::P_NA);
	//	unsigned int cantidadSeleccionada = 0;
	//
	//	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
	//
	//		if(it->personajeId != personajeIdNoValido && it->personajeConfirmado){
	//			cantidadSeleccionada++;
	//		}
	//	}
	//	if(listaJugadores.size() == cantidadSeleccionada){
	//		return true;
	//	}
	//	else{
	//		return false;
	//	}
}
bool Partida::PersonajesSeleccionCompletaTitular() {
	list<ClienteConectado>::iterator it;
	int personajeIdNoValido = static_cast<int>(PERSONAJE::P_NA);
	unsigned int cantidadSeleccionada = 0;

	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {

		if (it->titular && it->personajeId != personajeIdNoValido && it->personajeConfirmado) {
			cantidadSeleccionada++;
		}
	}
	if (2 == cantidadSeleccionada) {
		return true;
	} else {
		return false;
	}
}
bool Partida::PersonajesSeleccionCompletaSuplente() {
	list<ClienteConectado>::iterator it;
	int personajeIdNoValido = static_cast<int>(PERSONAJE::P_NA);
	unsigned int cantidadSeleccionada = 0;

	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {

		if(it->cantidadPersonajes == 2){
			if (it->personajeIdSuplente != personajeIdNoValido	&& it->personajeConfirmadoSuplente) {
				cantidadSeleccionada++;
			}
		}
		else{
			if (!it->titular && it->personajeId != personajeIdNoValido	&& it->personajeConfirmado) {
				cantidadSeleccionada++;
			}
		}
		//if (it->personajeId != personajeIdNoValido	&& it->personajeConfirmadoSuplente) {
	}
	if (2 == cantidadSeleccionada) {
		return true;
	} else {
		return false;
	}
}
void Partida::SetPersonajes(){
	list<ClienteConectado>::iterator it;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		if(it->cantidadPersonajes == 2){
			this->modelo->set_equipos_with_jugador(it->equipo, 0, it->personajeId);
			this->modelo->set_equipos_with_jugador(it->equipo, 1, it->personajeIdSuplente);
		}
		else{
			this->modelo->set_equipos_with_jugador(it->equipo, it->numeroJugador, it->personajeId);
		}
	}
	cout << "PARTIDA - SetPersonajes: Finalizo el seteo de los Personajes en el modelo | " << TimeHelper::getStringLocalTimeNow() << endl;
}

bool Partida::EstaHabilitadoEnvioPersonajes(){
	return this->habilitadoEnvioPersonajes;
}

void Partida::HabilitarEnvioPersonajes(){
	this->habilitadoEnvioPersonajes = true;
}


bool Partida::EstaEnviadaDataPersonajes(){
	list<ClienteConectado>::iterator it;
	int contadorEnviado = 0;

	for (it = listaEspera.begin(); it != listaEspera.end(); it++) {
		if(it->dataPersonajesEnviada){
			contadorEnviado++;
		}
	}
	if(contadorEnviado == listaEspera.size()){
		return true;
	}
	else{
		return false;
	}
}

void Partida::SetDataPersonajesEnviada(string nombre){
	list<ClienteConectado>::iterator it;
	for (it = listaEspera.begin(); it != listaEspera.end(); it++) {
		if(it->nombre == nombre){
			it->dataPersonajesEnviada = true;
		}
	}
}
ModeloResultadoSeleccionPersonaje Partida::getResultadoSeleccionPersonaje(){

	ModeloResultadoSeleccionPersonaje unModelo;
	list<ClienteConectado>::iterator it;
	int contador = 0;
	for (it = listaJugadores.begin(); it != listaJugadores.end(); it++) {
		ModeloResultadoSeleccionItem item;
		item.cantidadPersonajes = it->cantidadPersonajes;
		item.equipo = it->equipo;
		item.numeroJugador = it->numeroJugador;
		item.personaje1Id = it->personajeId;
		if(item.cantidadPersonajes == 2){
			item.personaje2Id = it->personajeIdSuplente;
		}
		unModelo.data[contador] = item;
		contador++;
	}
	unModelo.cantidadData = contador;

	return unModelo;
}

void Partida::SetConfiguracion(int tiempoBatalla, int cantidadBatallas, bool modoTest){
	this->cantidadRounds = cantidadBatallas;
	this->tiempoRound = tiempoBatalla;
	this->modoTest = modoTest;
}

void Partida::AvanzarTiempo(){
	if(this->cronometro > 0){
		this->cronometro--;
	}
	modelo->SetTiempoJuego(this->cronometro);
	cout
	<< "PARTIDA - Tiempo:   " << this->cronometro << " | "
	<< TimeHelper::getStringLocalTimeNow() << endl;
}


bool Partida::EstaEnEjecucionDeBatalla(){
	return this->roundCorriendo;
}

bool Partida::DebeFinalizarBatalla(){
	if(!this->EsModoTest() && (this->cronometro <= 0 || !this->modelo->EquiposEstanVivos())){
		return true;
	}
	else{
		return false;
	}
}
void Partida::FinalizarBatalla(){
	this->roundCorriendo = false;
}

bool Partida::HayBatallasPendientes(){
	if(this->roundActual < this->cantidadRounds){
		return true;
	}
	else{
		return false;
	}
}

int Partida::GetNroBatallaActual(){
	return this->roundActual;
}
bool Partida::EsModoTest(){
	return this->modoTest;
}
