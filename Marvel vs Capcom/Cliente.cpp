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
	}
}

//éste hilo va a tomar cada elementos de la cola y va a actualizar el modelo
//y va a renderizar
void * hilo_render(void * cliente) {
	cout << "HILO RENDER lanzado." << endl;
	Cliente* p = (Cliente*) cliente;
	int tamModelo = NULL;
	while (1) {
		pthread_mutex_lock(&mutexx);
		tamModelo = p->getModeloCambios().size();
		pthread_mutex_unlock(&mutexx);
		if (tamModelo > 0) {
			ModeloEstado modelo = p->PopModeloDeCola();
			p->actualizarModelo(modelo);
		}
		//p->getVista()->render();
		//p->getVista()->model->update();
		//usleep(50);
	}
}

Cliente::Cliente(View* vista, Conexion* conexion) {
	cout << "creando cliente." << endl;
	this->vista = vista;
	this->conexion = conexion;
}

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

int Cliente::ConectarConServidor(char* ip, char* puerto) {
	cout << "conectando con servidor en ip: " << ip << " y en puerto: "
			<< puerto << endl;
	JugadorLogin jugLogin;
	int error = this->getConexion()->conectarConServidor(ip, puerto);
	if (error == -1) {
		cout << "ERROR conectando con el servidor :(" << endl;
		return -1;
	}
	cout << "conectando con el servidor!!" << endl;
	bool corriendo = true;
	int sockCliente = this->getConexion()->getSocketCliente();
	DatosHiloCliente datosCliente;
//	datosCliente.model = &model;
	datosCliente.sock = sockCliente;
	return 0;
}

void Cliente::enviarComandoAServidor(ComandoAlServidor comando) {
	int error = 0;
	IDMENSAJE com = COMANDO;
	int tam_mensaje = sizeof(ComandoAlServidor);
	error = send(this->getConexion()->getSocketCliente(), &com, sizeof(com),
	MSG_NOSIGNAL);
	error = send(this->getConexion()->getSocketCliente(), &comando,
			sizeof(comando), MSG_NOSIGNAL);

}
int Cliente::recibirModeloDelServidor() {
	IDMENSAJE idMsg;
	recv(this->getConexion()->getSocketCliente(), &idMsg, sizeof(idMsg), 0);
	//-------->Recibe EQUIPO
	if (idMsg == EQUIPO) {
		ClienteEquipo unClienteEquipo;
		recv(this->getConexion()->getSocketCliente(), &unClienteEquipo,
				sizeof(unClienteEquipo), 0);
		Titular = unClienteEquipo.titular;
		Equipo = unClienteEquipo.equipo;
	}

	//-------->Recibe MENSAJE
	if (idMsg == MENSAJE) {
		Mensaje unMensaje;
		recv(this->getConexion()->getSocketCliente(), &unMensaje,
				sizeof(unMensaje), 0);
	}

	//-------->Recibe MODELO
	if (idMsg == MODELO) {
		ModeloEstado unModelo;
		recv(this->getConexion()->getSocketCliente(), &unModelo,sizeof(unModelo), 0);
		pthread_mutex_lock(&mutexx);
		//actualizarModelo(unModelo);
		//this->PushModeloEnCola(unModelo);
		if(unModelo.jugadoresEquipo1.isCambiandoPersonaje){
			cout << "Equipo 1 cambiando personaje!!" << endl;
			//unModelo.jugadoresEquipo1.isActivo = true;
		}
		if(unModelo.jugadoresEquipo2.isCambiandoPersonaje){
					cout << "Equipo 2 cambiando personaje!!" << endl;
					//unModelo.jugadoresEquipo2.isActivo =  true;
				}
		this->getVista()->model->equipos[0]->setJugadorActivo(unModelo.activoEquipo1);
		this->getVista()->model->equipos[1]->setJugadorActivo(unModelo.activoEquipo2);

		this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setPosX(unModelo.jugadoresEquipo1.posX);
		this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setPosY(unModelo.jugadoresEquipo1.posY);
		this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setVelocidadX(unModelo.jugadoresEquipo1.velX);
		this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setVelocidadY(unModelo.jugadoresEquipo1.velY);
		this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaActivo(unModelo.jugadoresEquipo1.isActivo);
		this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaCambiandoPersonaje(unModelo.jugadoresEquipo1.isCambiandoPersonaje);
		if (unModelo.jugadoresEquipo1.isAgachado)
			this->getVista()->model->equipos[0]->getJugadorActivo()->Agachar();

		this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setPosX(unModelo.jugadoresEquipo2.posX);
		this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setPosY(unModelo.jugadoresEquipo2.posY);
		this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setVelocidadX(unModelo.jugadoresEquipo2.velX);
		this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setVelocidadY(unModelo.jugadoresEquipo2.velY);
		this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaActivo(unModelo.jugadoresEquipo2.isActivo);
		this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaCambiandoPersonaje(unModelo.jugadoresEquipo2.isCambiandoPersonaje);
		if (unModelo.jugadoresEquipo2.isAgachado)
					this->getVista()->model->equipos[1]->getJugadorActivo()->Agachar();

		pthread_mutex_unlock(&mutexx);
	}
	return NULL;
}
void Cliente::lanzarHilosDelJuego() {
	cout << "por lanzar hilos del cliente" << endl;
	pthread_t thid_hilo_escucha;
	pthread_t thid_hilo_render;
	pthread_create(&thid_hilo_escucha, NULL, hilo_escucha, this);
	pthread_detach(thid_hilo_escucha);
	//pthread_create(&thid_hilo_render, NULL, hilo_render, this);
	//pthread_detach(thid_hilo_render);
}
void Cliente::MenuDeSeleccion() {
	//TODO
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

Conexion* Cliente::getConexion() {
	return this->conexion;
}

void Cliente::setCenexion(Conexion* conexion) {
	this->conexion = conexion;
}
View* Cliente::getVista() {
	return this->vista;
}
void Cliente::setVista(View* vista) {
	this->vista = vista;
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

