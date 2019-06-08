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

// Hilo Conexion
void * hilo_conexionServer(void * datosConexion) {
	HiloConexion* p = (HiloConexion*) datosConexion;
	while (1) {
		p->ping = false;
		sleep(1);
		if (!p->ping && miPartida.Iniciada()) {
			//shutdown(p->sock, SHUT_RDWR);
			//close(p->sock);
			pthread_mutex_lock(&mutex_server);
			cout << "Falla en la comunicacion con el cliente: " << p->sock	<< endl;
			miPartida.JugadorDesconectado(p->usuario);
			pthread_mutex_unlock(&mutex_server);
			pthread_exit(NULL);
			break;
		}
	}
}
void * updateModelo(void *) {
	cout << "Hilo UpdateModelo corriendo." << endl;
	bool corriendo = true;
	while (corriendo) {
		if (miPartida.Iniciada()) {
			usleep(15000);
			miPartida.GetModelo()->update();
			miPartida.AjustarCamara();
		}
		if (miPartida.Finalizada())
			corriendo = false;
	}
}
// Hilo de control de partida. Finalizacion, inicio, etc.
void * controlPartida(void *) {

	while (1) {
		if (miPartida.FinalizadaSeleccionPersonajes() && !miPartida.Iniciada()) {//if (miPartida.EquipoCompleto()) {
			sleep(2);
			miPartida.IniciarPartida();
		}
		if (miPartida.Finalizada()) {
			miPartida.DetenerJugadores();
		}
		usleep(10);
	}
}

void * controlSeleccionPersonajes(void *) {
	cout << "SERVIDOR - controlSeleccionPersonajes: INICIO de ciclo" << " | "
			<< TimeHelper::getStringLocalTimeNow() << endl;
	while (1) {
		if (miPartida.EquipoCompleto()
				&& !miPartida.FinalizadaSeleccionPersonajes()) {

			if (!miPartida.EstaHabilitadoEnvioPersonajes()) {
				cout
						<< "SERVIDOR - controlSeleccionPersonajes: Ingresó en 1er IF | "
						<< TimeHelper::getStringLocalTimeNow() << endl;
				pthread_mutex_lock(&mutex_server);
				miPartida.HabilitarEnvioPersonajes();
				pthread_mutex_unlock(&mutex_server);
				cout
						<< "SERVIDOR - controlSeleccionPersonajes: Ejecutado 1er IF | "
						<< TimeHelper::getStringLocalTimeNow() << endl;
			} else if (miPartida.EstaEnviadaDataPersonajes()
					&& !miPartida.IniciadaSeleccionPersonajes()) {
				cout
						<< "SERVIDOR - controlSeleccionPersonajes: Ingresó en 2do IF | "
						<< TimeHelper::getStringLocalTimeNow() << endl;
				pthread_mutex_lock(&mutex_server);
				miPartida.IniciarSeleccionPersonajes();
				pthread_mutex_unlock(&mutex_server);
				cout
						<< "SERVIDOR - controlSeleccionPersonajes: Ejecutado 2do IF | "
						<< TimeHelper::getStringLocalTimeNow() << endl;
			} else if (miPartida.IniciadaSeleccionPersonajes()
					&& miPartida.PersonajesSeleccionCompleta()) {
				cout
						<< "SERVIDOR - controlSeleccionPersonajes: Ingresó en 3er IF | "
						<< TimeHelper::getStringLocalTimeNow() << endl;
				pthread_mutex_lock(&mutex_server);
				miPartida.SetPersonajes();
				miPartida.FinalizarSeleccionPersonajes();
				pthread_mutex_unlock(&mutex_server);
				cout
						<< "SERVIDOR - controlSeleccionPersonajes: Ejecutado 3er IF | "
						<< TimeHelper::getStringLocalTimeNow() << endl;
			}
		}
		//	cout << "Personajes seleccion compelta: " << miPartida.IniciadaSeleccionPersonajes() << endl;

	}
	cout << "SERVIDOR - controlSeleccionPersonajes: FIN de ciclo" << " | "
			<< TimeHelper::getStringLocalTimeNow() << endl;
}

//Hilo de loggeo de informacion
void * loggeoPartida(void *) {
	while (1) {
		system("clear");
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
	bool avisoJuegoIniciado = false;
	while (corriendo) {
		if (miPartida.EsClienteDesconectadoBySock(sock)) {
			cout
					<< "Cliente desconectado!!!######### Hilo enviar datos termminado"
					<< endl;
			corriendo = false;
			pthread_exit(NULL);
			break;
		}
		//cout << "SERVIDOR - enviarDatos: PING ENVIADO | "<< usuario << " | " << TimeHelper::getStringLocalTimeNow() << endl;

		////------->Mensaje de conexión
		IDMENSAJE idPing = PING;
		send(sock, &idPing, sizeof(idPing), 0);

		//------->Mensaje de Equipo
		IDMENSAJE idEquipo = EQUIPO;
		//cout << "SERVIDOR - enviarDatos: EQUIPO | "<< usuario << " | " << TimeHelper::getStringLocalTimeNow() << endl;
		ClienteEquipo unEquipo;
		unEquipo.equipo = 99;
		pthread_mutex_lock(&mutex_server);
		if (!miPartida.Iniciada()) {
			if (miPartida.existeJugador(usuario)) {	//if(!miPartida.Iniciada()){
				unEquipo.equipo = miPartida.GetClienteEspera(usuario).equipo;
				unEquipo.titular = miPartida.GetClienteEspera(usuario).titular;
				unEquipo.nroJugador = miPartida.GetClienteEspera(usuario).numeroJugadorJuego;
				unEquipo.cantidadEquipo = miPartida.GetCantidadEnEspera(unEquipo.equipo);
			}
		} else {
			if (miPartida.existeJugador(usuario)) {
				unEquipo.equipo = miPartida.GetClienteJugando(usuario).equipo;
				unEquipo.titular = miPartida.GetClienteJugando(usuario).titular;
				unEquipo.nroJugador = miPartida.GetClienteJugando(usuario).numeroJugadorJuego;
				unEquipo.cantidadEquipo = miPartida.GetCantidadJugando(unEquipo.equipo);
			}
		}
		pthread_mutex_unlock(&mutex_server);
		if (unEquipo.equipo != 99) {
			send(sock, &idEquipo, sizeof(idEquipo), 0);
			send(sock, &unEquipo, sizeof(unEquipo), 0);
		}
		//cout << "SERVIDOR - enviarDatos: EQUIPO ENVIADO | "<< usuario << " | " << TimeHelper::getStringLocalTimeNow() << endl;

		//------->Envio de Info de Selección de Personajes
		if (miPartida.EstaHabilitadoEnvioPersonajes()
				&& !miPartida.IniciadaSeleccionPersonajes()) {

			IDMENSAJE idModelo = DATAPERSONAJES;
			bool enviar = false;
			ModeloPersonajes unModelo;

			pthread_mutex_lock(&mutex_server);
			ClienteConectado cliente = miPartida.GetClienteEspera(usuario);
			if (!cliente.dataPersonajesEnviada) {
				unModelo = miPartida.GetModeloPersonajes();
				enviar = true;
			}
			pthread_mutex_unlock(&mutex_server);
			if (enviar) {
				send(sock, &idModelo, sizeof(idModelo), 0);
				send(sock, &unModelo, sizeof(unModelo), 0);

				pthread_mutex_lock(&mutex_server);
				miPartida.SetDataPersonajesEnviada(usuario);
				pthread_mutex_unlock(&mutex_server);
				cout << "SERVIDOR - enviarDatos: DATAPERSONAJES ENVIADO | "
						<< usuario << " | "
						<< TimeHelper::getStringLocalTimeNow() << endl;
			}
		}

		//------->Envio de Info de Selección de Personajes
		if (miPartida.IniciadaSeleccionPersonajes() && !miPartida.FinalizadaSeleccionPersonajes()) {
			//cout << "SERVIDOR - enviarDatos: MODELOSELECCION | "<< usuario << " | " << TimeHelper::getStringLocalTimeNow() << endl;
			IDMENSAJE idModelo = MODELOSELECCION;

			pthread_mutex_lock(&mutex_server);
			ModeloSeleccion unModelo = miPartida.GetModeloSeleccion();
			pthread_mutex_unlock(&mutex_server);

			send(sock, &idModelo, sizeof(idModelo), 0);
			send(sock, &unModelo, sizeof(unModelo), 0);

		}
		//------->Envio de confirmacion de inicio de juego
		if (miPartida.Iniciada() && !avisoJuegoIniciado) {
			IDMENSAJE idModelo = JUEGOINICIADO;
			ModeloResultadoSeleccionPersonaje unModelo = miPartida.getResultadoSeleccionPersonaje();
			send(sock, &idModelo, sizeof(idModelo), 0);
			send(sock, &unModelo, sizeof(unModelo), 0);
			avisoJuegoIniciado = true;
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
	cout << "Hilo de RECIBIR DATOS creado, enviará datos con soket: "
			<< unCliente.socket << endl;

	//Completo datos cliente
	pthread_mutex_lock(&mutex_server);
	miPartida.AgregarCliente(&unCliente);
	pthread_mutex_unlock(&mutex_server);
	cout << "Por entrar a while del hilo." << endl;

	//Conexion
	HiloConexion datosCone;
	datosCone.sock = unCliente.socket;
	datosCone.ping = false;
	datosCone.usuario = unCliente.nombre;
	pthread_t hiloConexion;

	pthread_create(&hiloConexion, NULL, hilo_conexionServer,
			(void*) &datosCone);
	pthread_detach(hiloConexion);

	//-------->Loop de escucha
	bool corriendo = true;
	cout << "Por entrar a while del hilo." << endl;
	while (corriendo) {
		if (miPartida.EsClienteDesconectadoBySock(unCliente.socket)) {
			cout << "Cliente desconectado!!!Hilo escucha: FIN" << endl;
			corriendo = false;
			pthread_exit(NULL);
			break;
		}

		IDMENSAJE idMsg;
		int errorRecv = recv(unCliente.socket, &idMsg, sizeof(idMsg),
				MSG_NOSIGNAL);
		if (errorRecv > 0) {
			if (idMsg == PING) {
				pthread_mutex_lock(&mutex_server);
				datosCone.ping = true;
//				cout << "Ping de socket: " << datosCone.sock << endl;
				pthread_mutex_unlock(&mutex_server);
			}

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
//				cout << "Comando recibido: " << unComando.comando << "por socket: "<<unCliente.socket<< endl;
//				cout << "*****************************************************" << endl;

			}
			if ((idMsg == DATASELECCION)
					&& (miPartida.IniciadaSeleccionPersonajes())) {
				DataSeleccionAlServidor data;
				recv(unCliente.socket, &data, sizeof(data), 0);
				pthread_mutex_lock(&mutex_server);
				miPartida.HandleEventSeleccionPersonajes(unCliente.nombre, &data);
				pthread_mutex_unlock(&mutex_server);
				//cout << "Data Selección recibida: " << data.personajeId << endl;
				//cout << "Confirmado: " << data.confirmado << endl;

			}
		}
	}
}
void Servidor::LanzarHiloControlSeleccionPersonajes() {
	//Hilo de control
	pthread_t thread_control_seleccionPersonajes;
	pthread_create(&thread_control_seleccionPersonajes, NULL,
			controlSeleccionPersonajes, NULL);
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

void Servidor::LanzarHiloUpdateModelo() {
	//Hilo de control
	pthread_t thread_update_modelo;
	pthread_create(&thread_update_modelo, NULL, updateModelo, NULL);
	pthread_detach(thread_update_modelo);
}

int Servidor::calcular_num_personajes(int orden_jugador) {
	//si hay dos jugadores , cada uno debe sereccionar 2 pesonajes
	if (this->num_jugadores == 2) {
		return 2;
	} else {
		if (this->num_jugadores == 3) {
			if (orden_jugador == 1) {
				return 2;
			} else {
				return 1;
			}
			//si hay 4 jugadores el cada uno elije un personaje
		} else {
			return 1;
		}
	}
}

void Servidor::AceptarClientes(int maxClientes) {

	int num_orden_cliente = 1;
	int num_personajes;
	//Aceptar clientes
	struct sockaddr_in paramentrosCliente;
	unsigned int tamanho = sizeof(paramentrosCliente);
	bool corriendo = true;
	while (corriendo) {
		int socketComunicacion;
		socketComunicacion = accept(connServidor.socketConexion,
				(struct sockaddr *) &paramentrosCliente, &tamanho);

		cout << "Se aceptó una conexión nueva" << endl;
		//Primer mensaje recibido.
		JugadorLogin login;
		IDMENSAJE idMsg;
		int numError = recv(socketComunicacion, &idMsg, sizeof(idMsg), 0);
		if (idMsg == LOGIN && numError > 0) {
			recv(socketComunicacion, &login, sizeof(login), 0);
		}
		if (!miPartida.Iniciada()
				|| miPartida.EsClienteDesconectado(login.usuario)) {

			cout << "Recibiendo al nuevo cliente: " << login.usuario << endl;
			// Datos para el thread
			DatosHiloServidor datos;
			datos.sock = socketComunicacion;
			if (!miPartida.Iniciada())
				datos.usuario = miPartida.validarNombreUsuario(login.usuario);
			else
				datos.usuario = login.usuario;

			//Creo un hilo de envio
			pthread_t hiloEnvio;
			pthread_create(&hiloEnvio, NULL, enviarDatos, (void*) &datos);
			pthread_detach(hiloEnvio);

			//Creo hilo de recepcion
			pthread_t hiloRecepcion;
			pthread_create(&hiloRecepcion, NULL, recibirDatos, (void*) &datos);
			pthread_detach(hiloRecepcion);

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
	LanzarHiloControlSeleccionPersonajes();
	LanzarHiloLoggeo();
	LanzarHiloUpdateModelo();
	AceptarClientes(maxClientes);

}



