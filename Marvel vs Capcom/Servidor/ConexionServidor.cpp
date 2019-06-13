/*
 * ConexionServidor.cpp
 *
 *  Created on: 1 may. 2019
 *      Author: delpinor
 */
#include "ConexionServidor.h"
ConexionServidor::ConexionServidor(){
	falloConexion = false;

}
void ConexionServidor::IniciarConexion(char * puerto){
	struct sockaddr_in direccionServidor;
	//struct sockaddr_in direccionCliente;

	direccionServidor.sin_family = AF_INET;
	//direccionServidor.sin_addr.s_addr = inet_addr(IP);
	direccionServidor.sin_addr.s_addr = INADDR_ANY;
	direccionServidor.sin_port =  htons(atoi(puerto));
	//Creacion socker conexion
	if((socketConexion =  socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("Socket conexión");
		falloConexion = true;
		socketConexion =  SOCKET_NO_VALIDO;
	}
	//Socket reutilizable
	int opt = 1;
	if (setsockopt(socketConexion, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,	sizeof(opt)) < 0) {
		perror("Opciones de socket");
		falloConexion = true;
	}
	//Bind
	if(bind(socketConexion,(struct sockaddr *)&direccionServidor, sizeof(direccionServidor))< 0){
		perror("Bind");
		falloConexion = true;
		socketConexion =  SOCKET_NO_VALIDO;

	}
	//Esperando conexiones
	//Se levanta de un archivo la cantidad
	listen(socketConexion, 4);

}
int ConexionServidor::GetSocketComunicacion(){
	return socketComunicacion;
}
int ConexionServidor::GetSocketConexion(){
	return socketConexion;
}





