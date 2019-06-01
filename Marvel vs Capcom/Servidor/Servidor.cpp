/*
 * GameServer.cpp
 *
 *  Created on: 9 may. 2019
 *      Author: delpinor
 */
#include "Servidor.h"
using namespace std;
pthread_mutex_t mutex_server;
Partida miPartida;

// Hilo de control de partida. Finalizacion, inicio, etc.
void * controlPartida(void *) {

	while (1) {
		if (miPartida.FinalizadaSeleccionPersonajes() && !miPartida.Iniciada()) {//if (miPartida.EquipoCompleto()) {
			miPartida.IniciarPartida();
		}
	}
}

void * controlSeleccionPersonajes(void *) {
	cout << "SERVIDOR - controlSeleccionPersonajes: INICIO de ciclo" << " | " << TimeHelper::getStringLocalTimeNow() << endl;
	while (1) {
		if (miPartida.EquipoCompleto() && !miPartida.FinalizadaSeleccionPersonajes()) {

			if(!miPartida.EstaHabilitadoEnvioPersonajes()){
				cout << "SERVIDOR - controlSeleccionPersonajes: Ingresó en 1er IF | "<< TimeHelper::getStringLocalTimeNow() << endl;
				pthread_mutex_lock(&mutex_server);
				miPartida.HabilitarEnvioPersonajes();
				pthread_mutex_unlock(&mutex_server);
				cout << "SERVIDOR - controlSeleccionPersonajes: Ejecutado 1er IF | "<< TimeHelper::getStringLocalTimeNow() << endl;
			}
			else if(miPartida.EstaEnviadaDataPersonajes() && !miPartida.IniciadaSeleccionPersonajes()){
				cout << "SERVIDOR - controlSeleccionPersonajes: Ingresó en 2do IF | "<< TimeHelper::getStringLocalTimeNow() << endl;
				pthread_mutex_lock(&mutex_server);
				miPartida.IniciarSeleccionPersonajes();
				pthread_mutex_unlock(&mutex_server);
				cout << "SERVIDOR - controlSeleccionPersonajes: Ejecutado 2do IF | "<< TimeHelper::getStringLocalTimeNow() << endl;
			}
			else if(miPartida.IniciadaSeleccionPersonajes() && miPartida.PersonajesSeleccionCompleta()){
				cout << "SERVIDOR - controlSeleccionPersonajes: Ingresó en 3er IF | "<< TimeHelper::getStringLocalTimeNow() << endl;
				pthread_mutex_lock(&mutex_server);
				miPartida.SetPersonajes();
				miPartida.FinalizarSeleccionPersonajes();
				pthread_mutex_unlock(&mutex_server);
				cout << "SERVIDOR - controlSeleccionPersonajes: Ejecutado 3er IF | "<< TimeHelper::getStringLocalTimeNow() << endl;
			}
		}
	}
	cout << "SERVIDOR - controlSeleccionPersonajes: FIN de ciclo" << " | " << TimeHelper::getStringLocalTimeNow() << endl;
}

//Hilo de loggeo de informacion
void * loggeoPartida(void *) {
	while (1) {
		cout << "Inicio partida: "
				<< (miPartida.Iniciada() == true ? "Iniciada" : "No iniciada")
				<< endl;
		cout << "Final partida: "
				<< (miPartida.Finalizada() == true ?
						"Finalizada" : "No finalizada") << endl;
		cout << "Cantidad jugadores: " << miPartida.GetCantidadJugando()
				<< endl;
		cout << "Cantidad en espera: " << miPartida.GetCantidadEspera() << endl;
		cout << "Cantidad en desconectados: "
				<< miPartida.GetCantidadDesconectados() << endl;
		cout << "Jugadores:" << endl;

		list<ClienteConectado> lista = miPartida.GetListaJugadores();
		list<ClienteConectado>::iterator it;
		for (it = lista.begin(); it != lista.end(); it++) {
			cout << "Socket: " << it->socket << endl;
			cout << "Nombre: " << it->nombre << endl;
			cout << "Numero de Jugador: " << it->numeroJugador << endl;
			cout << "Equipo: " << it->equipo << endl;
			cout << "Titular: "
					<< (it->titular == true ? "Es titular" : "Es suplente")
					<< endl;
			cout << "------------------------" << endl;
			cout << "------------------------" << endl;
		}
		if (miPartida.Finalizada()) {
			cout << "Partida finalizada!" << it->nombre << endl;
			pthread_exit(NULL);

		}

		sleep(1);
	}

}

// Hilo de envio a Clientes conectados
void * enviarDatos(void * datos) {
	int sock = ((DatosHiloServidor*) datos)->sock;
	string usuario = ((DatosHiloServidor*) datos)->usuario;

	bool corriendo = true;
	while (corriendo) {
		////------->Mensaje de conexión
		cout << "SERVIDOR - enviarDatos: PING | "<< usuario << " " << TimeHelper::getStringLocalTimeNow() << endl;
		IDMENSAJE idPing = PING;
		if (send(sock, &idPing, sizeof(idPing), 0) == -1) {
			cout << "Jugador " << usuario << " desconectado..." << endl;
			miPartida.JugadorDesconectado(usuario);
			// Cierro los sockets
			shutdown(sock, SHUT_RDWR);
			close(sock);
			pthread_exit(NULL);
			corriendo = false;
		}
		cout << "SERVIDOR - enviarDatos: PING ENVIADO | "<< usuario << " " << TimeHelper::getStringLocalTimeNow() << endl;

		//------->Mensaje de Equipo
		IDMENSAJE idEquipo = EQUIPO;
		cout << "SERVIDOR - enviarDatos: EQUIPO | "<< usuario << " " << TimeHelper::getStringLocalTimeNow() << endl;
		ClienteEquipo unEquipo;
		pthread_mutex_lock(&mutex_server);
		if(!miPartida.IniciadaSeleccionPersonajes()){//if(!miPartida.Iniciada()){
			unEquipo.equipo = miPartida.GetClienteEspera(usuario).equipo;
			unEquipo.titular = miPartida.GetClienteEspera(usuario).titular ;
			unEquipo.nroJugador = miPartida.GetClienteEspera(usuario).numeroJugadorJuego;
		}else{
			unEquipo.equipo = miPartida.GetClienteJugando(usuario).equipo;
			unEquipo.titular = miPartida.GetClienteJugando(usuario).titular ;
			unEquipo.nroJugador = miPartida.GetClienteJugando(usuario).numeroJugadorJuego;
		}
		pthread_mutex_unlock(&mutex_server);
		send(sock, &idEquipo, sizeof(idEquipo), 0);
		send(sock, &unEquipo, sizeof(unEquipo),0);
		cout << "SERVIDOR - enviarDatos: EQUIPO ENVIADO | "<< usuario << " " << TimeHelper::getStringLocalTimeNow() << endl;

		//------->Envio de Info de Selección de Personajes
		if(miPartida.EstaHabilitadoEnvioPersonajes() && !miPartida.IniciadaSeleccionPersonajes()){
			cout << "SERVIDOR - enviarDatos: DATAPERSONAJES | "<< usuario << " " << TimeHelper::getStringLocalTimeNow() << endl;
			IDMENSAJE idModelo = DATAPERSONAJES;
			bool enviar = false;
			ModeloPersonajes unModelo;

			pthread_mutex_lock(&mutex_server);
			ClienteConectado cliente = miPartida.GetClienteEspera(usuario);
			if(!cliente.dataPersonajesEnviada){
				unModelo = miPartida.GetModeloPersonajes();
				enviar = true;
			}
			pthread_mutex_unlock(&mutex_server);
			if(enviar){
				send(sock, &idModelo, sizeof(idModelo), 0);
				send(sock, &unModelo, sizeof(unModelo), 0);

				pthread_mutex_lock(&mutex_server);
				miPartida.SetDataPersonajesEnviada(usuario);
				pthread_mutex_unlock(&mutex_server);
				cout << "SERVIDOR - enviarDatos: DATAPERSONAJES ENVIADO | "<< usuario << " " << TimeHelper::getStringLocalTimeNow() << endl;
			}
		}

		//------->Envio de Info de Selección de Personajes
		if (miPartida.IniciadaSeleccionPersonajes() && !miPartida.FinalizadaSeleccionPersonajes()) {
			cout << "SERVIDOR - enviarDatos: MODELOSELECCION | "<< usuario << " " << TimeHelper::getStringLocalTimeNow() << endl;
			IDMENSAJE idModelo = MODELOSELECCION;

			pthread_mutex_lock(&mutex_server);
			ModeloSeleccion unModelo = miPartida.GetModeloSeleccion();
			pthread_mutex_unlock(&mutex_server);

			send(sock, &idModelo, sizeof(idModelo), 0);
			send(sock, &unModelo, sizeof(unModelo), 0);
			cout << "SERVIDOR - enviarDatos: MODELOSELECCION ENVIADO | "<< usuario << " " << TimeHelper::getStringLocalTimeNow() << endl;
		}

		//------->Envio de Jugador
		if (miPartida.Iniciada()) {
			IDMENSAJE idModelo = MODELO;
			pthread_mutex_lock(&mutex_server);
			ModeloEstado unModelo = miPartida.GetModeloEstado();
			pthread_mutex_unlock(&mutex_server);
			send(sock, &idModelo, sizeof(idModelo), 0);
			send(sock, &unModelo, sizeof(unModelo), 0);
		}
		usleep(1000);
	}
}

//Escuchar mensajes de los clientes
void * recibirDatos(void * datos) {

	int sock = ((DatosHiloServidor*) datos)->sock;
	string usuario = ((DatosHiloServidor*) datos)->usuario;

	//Datos cliente
	ClienteConectado unCliente;
	unCliente.socket = sock;
	unCliente.tid = pthread_self();
	unCliente.nombre = usuario;

	//Completo datos cliente
	pthread_mutex_lock(&mutex_server);
	miPartida.AgregarCliente(&unCliente);
	pthread_mutex_unlock(&mutex_server);

	//-------->Loop de escucha
	bool corriendo = true;
	while (corriendo) {
		IDMENSAJE idMsg;
		recv(unCliente.socket, &idMsg, sizeof(idMsg), 0);
		if (idMsg == MENSAJE) {
			Mensaje unMensaje;
			recv(sock, &unMensaje, sizeof(unMensaje), 0);
			cout << " Mensaje: " << unMensaje.mensaje << endl;
		}

		if ((idMsg == COMANDO) && (miPartida.Iniciada())) {
			ComandoAlServidor unComando;
			recv(unCliente.socket, &unComando, sizeof(unComando), 0);
			pthread_mutex_lock(&mutex_server);
			miPartida.SetComando(unCliente.equipo, unComando.comando);
			pthread_mutex_unlock(&mutex_server);
			cout << "Comando recibido: " << unComando.comando << endl;
			cout << "*****************************************************" << endl;

		}

		if ((idMsg == DATASELECCION) && (miPartida.IniciadaSeleccionPersonajes())) {
			DataSeleccionAlServidor data;
			recv(unCliente.socket, &data, sizeof(data), 0);
			pthread_mutex_lock(&mutex_server);
			miPartida.HandleEventSeleccionPersonajes(unCliente.nombre, &data);
			pthread_mutex_unlock(&mutex_server);
			cout << "Data Selección recibida: " << data.personajeId << endl;
		}
	}
}
void Servidor::LanzarHiloControlSeleccionPersonajes() {
	//Hilo de control
	pthread_t thread_control_seleccionPersonajes;
	pthread_create(&thread_control_seleccionPersonajes, NULL, controlSeleccionPersonajes, NULL);
	pthread_detach(thread_control_seleccionPersonajes);
}
void Servidor::LanzarHiloControl() {
	//Hilo de control
	pthread_t thread_control;
	pthread_create(&thread_control, NULL, controlPartida, NULL);
	pthread_detach(thread_control);
}
void Servidor::LanzarHiloLoggeo() {
	pthread_t pthread_log;
	//Hilo de loggeo
	pthread_create(&pthread_log, NULL, loggeoPartida, NULL);
	pthread_detach(pthread_log);
}
void Servidor::AceptarClientes(int maxClientes) {
	//Aceptar clientes
	struct sockaddr_in paramentrosCliente;
	unsigned int tamanho = sizeof(paramentrosCliente);
	bool corriendo = true;
	while (corriendo) {
		int socketComunicacion;
		socketComunicacion = accept(connServidor.socketConexion,
				(struct sockaddr *) &paramentrosCliente, &tamanho);

		//Primer mensaje recibido.
		JugadorLogin login;
		IDMENSAJE idMsg;
		recv(socketComunicacion, &idMsg, sizeof(idMsg), 0);
		if (idMsg == LOGIN) {
			recv(socketComunicacion, &login, sizeof(login), 0);
		}
		if ((miPartida.GetCantidadJugando() < maxClientes)
				|| miPartida.EsClienteDesconectado(login.usuario)) {

			// Datos para el thread
			DatosHiloServidor datos;
			datos.sock = socketComunicacion;
			datos.usuario = login.usuario;

			//Creo hilo de recepcion
			pthread_t hiloRecepcion;
			pthread_create(&hiloRecepcion, NULL, recibirDatos, (void*) &datos);
			pthread_detach(hiloRecepcion);

			//Creo un hilo de envio
			pthread_t hiloEnvio;
			pthread_create(&hiloEnvio, NULL, enviarDatos, (void*) &datos);
			pthread_detach(hiloEnvio);

		} else {
			Mensaje msg;
			// Puede ser otro tipo de mensaje....
			IDMENSAJE idMsg = MENSAJE;
			strcpy(msg.mensaje, "Partida completa!");
			send(socketComunicacion, &idMsg, sizeof(idMsg), 0);
			send(socketComunicacion, &msg, sizeof(msg), 0);

			shutdown(socketComunicacion, SHUT_RDWR);
			close(socketComunicacion);
		}

	}

	shutdown(connServidor.socketConexion, SHUT_RDWR);
	close(connServidor.socketConexion);

	shutdown(connServidor.socketComunicacion, SHUT_RDWR);
	close(connServidor.socketComunicacion);
}
void Servidor::SetModel(Model * model) {
	miPartida.SetModelo(model);
}
void Servidor::IniciarServidor(int maxClientes, char * puerto) {

	// Valores iniciales
	miPartida.SetMaximoJugadores(maxClientes);
	connServidor.IniciarConexion(puerto);
	LanzarHiloControl();
	LanzarHiloControlSeleccionPersonajes();
	//LanzarHiloLoggeo();
	AceptarClientes(maxClientes);

}


