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
void * hilo_escucha(void * cliente){
	Cliente* p=(Cliente*) cliente;
	while(1){
		p->recibirModeloDelServidor();
	}
}

//éste hilo va a tomar cada elementos de la cola y va a actualizar el modelo
//y va a renderizar
void * hilo_render(void * cliente){
	Cliente* p=(Cliente*) cliente;
	while(1){
		usleep(25000);
	}
}

Cliente::Cliente() {
	// TODO Auto-generated constructor stub

}

void Cliente::ConectarConServidor(char* ip, char* puerto){
	JugadorLogin jugLogin;
	Conexion connCliente;
	this->setCenexion(connCliente);
	connCliente.conectarConServidor(ip,puerto);

	bool corriendo = true;
	int sockCliente = connCliente.getSocketCliente();
	DatosHiloCliente datosCliente;
//	datosCliente.model = &model;
	datosCliente.sock = sockCliente;
}

void Cliente::enviarComandoAServidor(ComandoAlServidor comando){
	int error = 0;
	IDMENSAJE com = COMANDO;
	int tam_mensaje = sizeof(ComandoAlServidor);
	error = this->getConexion().enviar_mensaje(this->conexion.getSocketCliente(),&com, sizeof(com));
	// manejar errores de conexion
	error = this->getConexion().enviar_mensaje(this->conexion.getSocketCliente(),&comando, tam_mensaje);
	// manejar errores de conexions
}
int Cliente::recibirModeloDelServidor() {
	IDMENSAJE idMsg;
	this->conexion.recibir_mensaje(this->conexion.getSocketCliente(), &idMsg,sizeof(idMsg));

	if (idMsg == MENSAJE) {
		Mensaje unMensaje;
		recv(this->getConexion().getSocketCliente(), &unMensaje, sizeof(unMensaje),0);
//				pthread_mutex_lock(&mutexx);
//		cout << " Mensaje: " << unMensaje.mensaje << endl;
//				pthread_mutex_unlock(&mutexx);
	}
	if (idMsg == MODELO) {
		ModeloEstado unModelo;
		recv(this->getConexion().getSocketCliente(), &unModelo, sizeof(unModelo), 0);
		pthread_mutex_lock(&mutexx);
		this->PushModeloEnCola(unModelo);
//		cout << " Mensaje: " << unMensaje.mensaje << endl;
		pthread_mutex_unlock(&mutexx);
	}
	return NULL;
}
void Cliente::lanzarHilosDelJuego(){
	pthread_t hiloEscuchaServidor;
	pthread_t hiloRender;
}
void Cliente::MenuDeSeleccion(){
	//TODO
}
std::queue<ModeloEstado> Cliente::getModeloCambios(){
	return this->ModeloCambios;
}
int Cliente::getTiepoUltimoMensajeRecibido(){
	return this->tiempoUltimoMensajeRecivido;
}
void Cliente::setTiempoUltimoMensajeRecibido(int tiempo){
	this->tiempoUltimoMensajeRecivido = tiempo;
}

void Cliente::PushModeloEnCola(ModeloEstado modelo){
	this->ModeloCambios.push(modelo);
}
ModeloEstado Cliente::PopModeloDeCola(){
	//lockear
	pthread_mutex_lock(&mutexx);
	ModeloEstado modelo = this->ModeloCambios.front();
	this->ModeloCambios.pop();
	pthread_mutex_unlock(&mutexx);
	return modelo;
}

Conexion Cliente::getConexion(){
	return this->conexion;
}

void Cliente::setCenexion(Conexion conexion){
	this->conexion = conexion;
}
View Cliente::getVista(){
	return this->vista;
}
void Cliente::setVista(View vista){
	this->vista = vista;
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

