/*
 * ConexionCliente.h
 *
 *  Created on: 30 abr. 2019
 *      Author: delpinor
 */
#ifndef CONEXIONCLIENTE_H_
#define CONEXIONCLIENTE_H_
#define SOCKET_NO_VALIDO -1


#include <iostream>
#include "EstructuraDatos.h"
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class Conexion{
	private:
		int socketCliente;
		bool falloConexion;
		struct sockaddr_in direcionServidor;
		char * _ip;
		char * _puerto;

	public:
		Conexion();
		int Reconectar();
		int conectarConServidor(char * ip, char * puerto);
		void Cerrar();
		int prepararSocketServidor();
		int aceptarConexionCliente();
		int enviar_mensaje(int socket, void* mensaje, int tam_mensaje);
		int recibir_mensaje(int socket, void* mensaje, int tam_mensaje);
		int recibirMensajeDelServidor();
		int getSocketCliente();
		void close_socket(int socket);
		bool falloLaConexion();

};




#endif /* CONEXIONCLIENTE_H_ */
