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
		if (miPartida.EquipoCompleto()) {
			miPartida.IniciarPartida();
		}
	}
}

//Hilo de loggeo de informacion
void * loggeoPartida(void *) {
	while (1) {
//		system("clear");
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
		IDMENSAJE idPing = PING;
		int errorSock = send(sock, &idPing, sizeof(idPing), MSG_DONTWAIT | MSG_CONFIRM );
		if (errorSock < 0) {
			cout << "Jugador " << usuario << " desconectado... ##################################################################################" << endl;
			miPartida.JugadorDesconectado(usuario);
			// Cierro los sockets
			shutdown(sock, SHUT_RDWR);
			close(sock);
			pthread_exit(NULL);
			corriendo = false;
		}

		//------->Mensaje de Equipo
		IDMENSAJE idEquipo = EQUIPO;
		ClienteEquipo unEquipo;
		unEquipo.equipo = 99;
		pthread_mutex_lock(&mutex_server);
		if(!miPartida.Iniciada()){
			if (miPartida.existeJugador(usuario)){
				unEquipo.equipo = miPartida.GetClienteEspera(usuario).equipo;
				unEquipo.titular = miPartida.GetClienteEspera(usuario).titular;
			}
		}else{
			if (miPartida.existeJugador(usuario)){
				unEquipo.equipo = miPartida.GetClienteJugando(usuario).equipo;
				unEquipo.titular = miPartida.GetClienteJugando(usuario).titular;
			}
		}
		pthread_mutex_unlock(&mutex_server);
		if (unEquipo.equipo != 99){
			send(sock, &idEquipo, sizeof(idEquipo), 0);
			send(sock, &unEquipo, sizeof(unEquipo),0);
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
	cout << "Hilo de RECIBIR DATOS creado, enviará datos con soket: "<<unCliente.socket<< endl;

	//Completo datos cliente
	pthread_mutex_lock(&mutex_server);
	miPartida.AgregarCliente(&unCliente);
	pthread_mutex_unlock(&mutex_server);
	cout << "Por entrar a while del hilo." << endl;
	//-------->Loop de escucha
	bool corriendo = true;
	while (corriendo) {
		if(miPartida.EsClienteDesconectadoBySock(unCliente.socket)){
			cout << "Cliente desconectado!!!########################## Hilo termminado" << endl;
			corriendo = false;
			break;
		}

		IDMENSAJE idMsg;
		recv(unCliente.socket, &idMsg, sizeof(idMsg), 0);
//		perror("Error recibiendo tipo de mensaje");
//		cout << "Tipo mensaje recibido: " << idMsg << "por socket: "<<unCliente.socket<< endl;
		if (idMsg == MENSAJE) {
			Mensaje unMensaje;
			recv(sock, &unMensaje, sizeof(unMensaje), 0);
			cout << " Mensaje: " << unMensaje.mensaje << endl;
		}

		if ((idMsg == COMANDO) && (miPartida.Iniciada())) {
			ComandoAlServidor unComando;
			recv(unCliente.socket, &unComando, sizeof(unComando), 0);
//			perror("Error recibiendo COMANDO de mensaje");
			pthread_mutex_lock(&mutex_server);
			miPartida.SetComando(unCliente.equipo, unComando.comando);
			pthread_mutex_unlock(&mutex_server);
//			cout << "Comando recibido: " << unComando.comando << "por socket: "<<unCliente.socket<< endl;
//			cout << "*****************************************************" << endl;

		}
	}
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
		socketComunicacion = accept(connServidor.socketConexion,(struct sockaddr *) &paramentrosCliente, &tamanho);
	    struct timeval tv;
		tv.tv_sec = 2;
		setsockopt(socketComunicacion, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv,  sizeof tv);
		cout << "Se aceptó una conexión nueva" << endl;
		//Primer mensaje recibido.
		JugadorLogin login;
		IDMENSAJE idMsg;
		recv(socketComunicacion, &idMsg, sizeof(idMsg), 0);
		if (idMsg == LOGIN) {
			recv(socketComunicacion, &login, sizeof(login), 0);
		}
		if(!miPartida.Iniciada() || miPartida.EsClienteDesconectado(login.usuario)){

			cout << "Recibiendo al nuevo cliente: " << login.usuario << endl;
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
			IDMENSAJE idMsg = COMPLETO;
			send(socketComunicacion, &idMsg, sizeof(idMsg), 0);

			shutdown(socketComunicacion, SHUT_RDWR);
			close(socketComunicacion);

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
	LanzarHiloLoggeo();
	AceptarClientes(maxClientes);

}


