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

#define IP "127.0.0.1"
#define PUERTO 11000



class Conexion{
	private:
		int socketCliente;
		int socketServidor;
		bool falloConexion;
	public:
		Conexion();
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
