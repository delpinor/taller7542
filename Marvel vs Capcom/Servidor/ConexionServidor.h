/*
 * ConexionServidor.h
 *
 *  Created on: 1 may. 2019
 *      Author: delpinor
 */

#ifndef CONEXIONSERVIDOR_H_
#define CONEXIONSERVIDOR_H_
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define SOCKET_NO_VALIDO -1
#define IP "192.168.0.71"
class ConexionServidor{
private:
	bool falloConexion;

public:
	int socketConexion = SOCKET_NO_VALIDO;
	int socketComunicacion = SOCKET_NO_VALIDO;
	void IniciarConexion(char * puerto);
	ConexionServidor();
	int GetSocketConexion();
	int GetSocketComunicacion();
	bool Fallo();
};


#endif /* CONEXIONSERVIDOR_H_ */
