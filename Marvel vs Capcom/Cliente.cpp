/*
 * Cliente.cpp
 *
 *  Created on: 9 may. 2019
 *      Author: maciel
 */
#include "Cliente.h"

pthread_mutex_t mutexx;

// Estructura para enviar al hilo.
struct DatosHiloCliente {
	Model * model;
	int sock;
};

//hilos a lanzar por cada cliente

//éste hilo va a escuchar lo que el servidor envíe
//va a insertar lo el modelo que el servidor manda en una cola
//y va a guardar el tiempo en que recibió el ultimo mensaje para saber si sigue conectado al servidor
void * hilo_escucha(void * cliente) {
	cout << "HILO ESCUCHA lanzado." << endl;
	Cliente* p = (Cliente*) cliente;
	while (1) {
//		cout << "adentro del while de escucha." << endl;
		p->recibirModeloDelServidor();
		usleep(60);
		if (!p->ServidorVivo) {
			pthread_exit(0);
			break;
		}
	}
}
void * hilo_conexion(void * cliente) {
	Cliente* p = (Cliente*) cliente;
	while (1) {
		p->Ping = false;
		sleep(1);
		if (!p->Ping) {
			p->ServidorVivo = false;
			p->getConexion()->Cerrar();
			p->getVista()->CajaMensaje("Conexión", "Falla en la comunicación. Intentando reconectar...");
			while(!p->ServidorVivo){
				if (p->getConexion()->Reconectar() != -1) {
					JugadorLogin loginUsuario;
					IDMENSAJE idMsg = LOGIN;
					strcpy(loginUsuario.usuario, p->Usuario);
					send(p->getConexion()->getSocketCliente(), &idMsg, sizeof(idMsg), 0);
					send(p->getConexion()->getSocketCliente(), &loginUsuario,	sizeof(loginUsuario), 0);
					p->lanzarHilosDelJuego();
					p->LanzarHiloConexion();
					p->ServidorVivo = true;
					pthread_exit(0);
					break;
				}
			}
		}
	}
}

Cliente::Cliente(ViewMenu* vistaMenu, Conexion* conexion) {
	cout << "creando cliente." << endl;
	this->vistaMenu = vistaMenu;
	this->conexion = conexion;
}
//Cliente::Cliente(View* vista, Conexion* conexion) {
//	cout << "creando cliente." << endl;
//	this->vista = vista;
//	this->conexion = conexion;
//}

void Cliente::actualizarModelo(ModeloEstado modelo) {
	pthread_mutex_lock(&mutexx);

	this->getVista()->model->equipos[0]->setJugadorActivo(modelo.activoEquipo1);
	this->getVista()->model->equipos[1]->setJugadorActivo(modelo.activoEquipo2);

	this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaActivo(
			modelo.jugadoresEquipo1.isActivo);
	this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaActivo(
			modelo.jugadoresEquipo1.isAgachado);
	this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaActivo(
			modelo.jugadoresEquipo1.isCambiandoPersonaje);
	this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setPosX(
			modelo.jugadoresEquipo1.posX);
	this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setPosY(
			modelo.jugadoresEquipo1.posY);
	this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setVelocidadX(
			modelo.jugadoresEquipo1.velX);
	this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setVelocidadY(
			modelo.jugadoresEquipo1.velY);

	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaActivo(
			modelo.jugadoresEquipo2.isActivo);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaActivo(
			modelo.jugadoresEquipo2.isAgachado);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaActivo(
			modelo.jugadoresEquipo2.isCambiandoPersonaje);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setPosX(
			modelo.jugadoresEquipo2.posX);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setPosY(
			modelo.jugadoresEquipo2.posY);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setVelocidadX(
			modelo.jugadoresEquipo2.velX);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setVelocidadY(
			modelo.jugadoresEquipo2.velY);

	this->getVista()->getCamara()->x = modelo.camara.posX;
	this->getVista()->getCamara()->y = modelo.camara.posY;
	pthread_mutex_unlock(&mutexx);
}

bool Cliente:: esta_conectado(){

	return (this->ServidorVivo);
}

int Cliente::ConectarConServidor( char* hostname, char* puerto) {
	//IPServidor = ip;
	Puerto = puerto;
	cout << "conectando con servidor en ip: " << hostname << " y en puerto: "
			<< puerto << endl;
	int error = this->getConexion()->conectarConServidor(hostname, puerto);
	if (error == -1) {
		cout << "ERROR conectando con el servidor :(" << endl;
		return -1;
	}
	cout << "conectando con el servidor!!" << endl;
	return 0;
}

void Cliente::enviarComandoAServidor(ComandoAlServidor comando) {
	if (this->ServidorVivo){
		IDMENSAJE com = COMANDO;
		IDMENSAJE idCabecera = PING;
		send(this->getConexion()->getSocketCliente(), &idCabecera,sizeof(idCabecera), MSG_NOSIGNAL);
		send(this->getConexion()->getSocketCliente(), &com, sizeof(com), MSG_NOSIGNAL);
		send(this->getConexion()->getSocketCliente(), &comando,	sizeof(comando), MSG_NOSIGNAL);
	}
}
void Cliente::enviarDataSeleccionAServidor(DataSeleccionAlServidor data) {

	int error = 0;
	IDMENSAJE com = DATASELECCION;
	error = send(this->getConexion()->getSocketCliente(), &com, sizeof(com), MSG_NOSIGNAL);
	error = send(this->getConexion()->getSocketCliente(), &data, sizeof(data), MSG_NOSIGNAL);
}
int Cliente::recibirModeloDelServidor() {
	IDMENSAJE idMsg;
	int errorRecv = recv(this->getConexion()->getSocketCliente(), &idMsg,
			sizeof(idMsg), 0);
	if (errorRecv > 0) {
		//-------->Recibe PING
		if ((idMsg == PING)) {
			this->Ping = true;
			// Respondo el ping
		}
		//-------->Recibe EQUIPO
		if (idMsg == EQUIPO) {
			ClienteEquipo unClienteEquipo;
			recv(this->getConexion()->getSocketCliente(), &unClienteEquipo,
					sizeof(unClienteEquipo), 0);
			Titular = unClienteEquipo.titular;
			Equipo = unClienteEquipo.equipo;
		}

	//-------->Recibe COMPLETO
	if (idMsg == COMPLETO) {
		this->juegoCorriendo = false;
		this->getConexion()->Cerrar();
		this->getVista()->CajaMensaje("Equipos", "Juego iniciado. No hay lugar");
	}

		//-------->Recibe MODELO
		if (idMsg == MODELO) {
			ModeloEstado unModelo;
			recv(this->getConexion()->getSocketCliente(), &unModelo,
					sizeof(unModelo), 0);
			pthread_mutex_lock(&mutexx);
			//actualizarModelo(unModelo);
			//this->PushModeloEnCola(unModelo);
			this->getVista()->model->camara->x = unModelo.camara.posX;
			this->getVista()->model->camara->y = unModelo.camara.posY;

			if (this->getVista()->model->equipos[0]->nroJugadorActivo
					!= unModelo.activoEquipo1) {
				this->getVista()->model->equipos[0]->setJugadorActivo(
						unModelo.activoEquipo1);
			}
			if (this->getVista()->model->equipos[1]->nroJugadorActivo
					!= unModelo.activoEquipo2) {
				this->getVista()->model->equipos[1]->setJugadorActivo(
						unModelo.activoEquipo2);
			}
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setPosX(
					unModelo.jugadoresEquipo1.posX);
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setPosY(
					unModelo.jugadoresEquipo1.posY);
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setVelocidadX(
					unModelo.jugadoresEquipo1.velX);
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setVelocidadY(
					unModelo.jugadoresEquipo1.velY);
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaActivo(
					unModelo.jugadoresEquipo1.isActivo);
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaAgachado(
					unModelo.jugadoresEquipo1.isAgachado);
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaCambiandoPersonaje(
					unModelo.jugadoresEquipo1.isCambiandoPersonaje);

			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setPosX(
					unModelo.jugadoresEquipo2.posX);
			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setPosY(
					unModelo.jugadoresEquipo2.posY);
			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setVelocidadX(
					unModelo.jugadoresEquipo2.velX);
			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setVelocidadY(
					unModelo.jugadoresEquipo2.velY);
			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaActivo(
					unModelo.jugadoresEquipo2.isActivo);
			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaAgachado(
					unModelo.jugadoresEquipo2.isAgachado);
			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaCambiandoPersonaje(
					unModelo.jugadoresEquipo2.isCambiandoPersonaje);

			pthread_mutex_unlock(&mutexx);
		}
	}

	//-------->Recibe DATA PERSONAJES
	if (idMsg == DATAPERSONAJES) {
		//cout << "CLIENTE - recibirModeloDelServidor: Recibiendo DATAPERSONAJES | "<< TimeHelper::getStringLocalTimeNow() << endl;

		ModeloPersonajes unModelo;
		recv(this->getConexion()->getSocketCliente(), &unModelo,sizeof(unModelo), 0);
		pthread_mutex_lock(&mutexx);
		this->vistaMenu->setPersonajes(&unModelo);
		pthread_mutex_unlock(&mutexx);

		//cout << "CLIENTE - recibirModeloDelServidor: DATAPERSONAJES la lista de personajes tiene "<< unModelo.idsPersonajes.size() << " | "  << TimeHelper::getStringLocalTimeNow() << endl;
		//cout << "CLIENTE - recibirModeloDelServidor: DATAPERSONAJES Recibido | "<< TimeHelper::getStringLocalTimeNow() << endl;
	}

	//-------->Recibe MODELO SELECCION
	if (idMsg == MODELOSELECCION) {
		//cout << "CLIENTE - recibirModeloDelServidor: Recibiendo MODELOSELECCION | "<< TimeHelper::getStringLocalTimeNow() << endl;

		ModeloSeleccion unModelo;

		recv(this->getConexion()->getSocketCliente(), &unModelo,sizeof(unModelo), 0);

		pthread_mutex_lock(&mutexx);
		this->vistaMenu->setModeloSeleccion(unModelo);


		if(!this->EstaIniciadaSeleccionPersonaje()){
			//cout << "CLIENTE - recibirModeloDelServidor: Iniciando Seleccion Personaje | "<< TimeHelper::getStringLocalTimeNow() << endl;
			this->IniciarSeleccionPersonaje();
			//cout << "CLIENTE - recibirModeloDelServidor: Iniciando Seleccion Personaje HECHO | "<< TimeHelper::getStringLocalTimeNow() << endl;
		}
		pthread_mutex_unlock(&mutexx);

		//cout << "CLIENTE - recibirModeloDelServidor: MODELOSELECCION Recibido | "<< TimeHelper::getStringLocalTimeNow() << endl;
	}

	return NULL;

}
void Cliente::lanzarHilosDelJuego() {
	cout << "por lanzar hilos del cliente" << endl;
	pthread_t thid_hilo_escucha;
//	pthread_t thid_hilo_render;
	pthread_create(&thid_hilo_escucha, NULL, hilo_escucha, this);
	pthread_detach(thid_hilo_escucha);

	//pthread_create(&thid_hilo_render, NULL, hilo_render, this);
	//pthread_detach(thid_hilo_render);
}
void Cliente::LanzarHiloConexion() {
	pthread_t thid_hilo_conexion;
	pthread_create(&thid_hilo_conexion, NULL, hilo_conexion, this);
	pthread_detach(thid_hilo_conexion);
}
void Cliente::MenuDeSeleccion() {
}
std::queue<ModeloEstado> Cliente::getModeloCambios() {
	return this->ModeloCambios;
}
int Cliente::getTiepoUltimoMensajeRecibido() {
	return this->tiempoUltimoMensajeRecivido;
}
void Cliente::setTiempoUltimoMensajeRecibido(int tiempo) {
	this->tiempoUltimoMensajeRecivido = tiempo;
}

void Cliente::PushModeloEnCola(ModeloEstado modelo) {
	this->ModeloCambios.push(modelo);
}
ModeloEstado Cliente::PopModeloDeCola() {
	//lockear
	pthread_mutex_lock(&mutexx);
	ModeloEstado modelo = this->ModeloCambios.front();
	this->ModeloCambios.pop();
	pthread_mutex_unlock(&mutexx);
	return modelo;
}

Conexion * Cliente::getConexion() {
	return this->conexion;
}

void Cliente::setCenexion(Conexion* conexion) {
	this->conexion = conexion;
}
View * Cliente::getVista() {
	return this->vista;
}
void Cliente::setVista(View* vista) {
	this->vista = vista;
}

void Cliente::IniciarSeleccionPersonaje(){
	this->seleccionPersonajeIniciada = true;
}

void Cliente::FinalizarSeleccionPersonaje(){
	this->seleccionPersonajeFinalizada = true;
}

bool Cliente::EstaIniciadaSeleccionPersonaje(){
	return this->seleccionPersonajeIniciada;
}
bool Cliente::EstaFinalizadaSeleccionPersonaje(){
	return this->seleccionPersonajeFinalizada;
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}
