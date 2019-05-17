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
		cout << "adentro del while de escucha." << endl;
		p->recibirModeloDelServidor();
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
		p->getVista()->render();
		usleep(25000);
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
			modelo.jugadoresEquipo1.isActivo);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaActivo(
			modelo.jugadoresEquipo1.isAgachado);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaActivo(
			modelo.jugadoresEquipo1.isCambiandoPersonaje);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setPosX(
			modelo.jugadoresEquipo1.posX);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setPosY(
			modelo.jugadoresEquipo1.posY);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setVelocidadX(
			modelo.jugadoresEquipo1.velX);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setVelocidadY(
			modelo.jugadoresEquipo1.velY);

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
//	cout << "por enviar el comando: "<< comando.comando << endl;
	int error = 0;
	IDMENSAJE com = COMANDO;
	int tam_mensaje = sizeof(ComandoAlServidor);
	error = this->getConexion()->enviar_mensaje(
			this->getConexion()->getSocketCliente(), &com, sizeof(com));
	// manejar errores de conexion
	error = this->getConexion()->enviar_mensaje(
			this->getConexion()->getSocketCliente(), &comando, tam_mensaje);
	// manejar errores de conexions
}
int Cliente::recibirModeloDelServidor() {
	IDMENSAJE idMsg;
	cout << "adentro de recibirModeloDelServidor()." << endl;
	recv(this->getConexion()->getSocketCliente(), &idMsg,
			sizeof(idMsg), 0);
//	this->conexion->recibir_mensaje(this->getConexion()->getSocketCliente(),
//			&idMsg, sizeof(idMsg));
	cout << "tipo mensaje recibido: " << idMsg << endl;
	if (idMsg == MENSAJE) {
		Mensaje unMensaje;
		recv(this->getConexion()->getSocketCliente(), &unMensaje,
				sizeof(unMensaje), 0);


//				pthread_mutex_lock(&mutexx);
//		cout << " Mensaje: " << unMensaje.mensaje << endl;
//				pthread_mutex_unlock(&mutexx);
	}
	// Aca se esta bloqueando, no esta recibiendo el modelo..
	if (idMsg == MODELO) {
		ModeloEstado unModelo;
		cout << "socket cliente: " << this->getConexion()->getSocketCliente() << endl;
		recv(this->getConexion()->getSocketCliente(), &unModelo,
				sizeof(unModelo), 0);
		cout << "Modelo recibido!!!!: " << idMsg << endl;
		pthread_mutex_lock(&mutexx);
		this->PushModeloEnCola(unModelo);
		cout << "Modelo recibido" << endl;
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
	pthread_create(&thid_hilo_render, NULL, hilo_render, this);
	pthread_detach(thid_hilo_render);
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

