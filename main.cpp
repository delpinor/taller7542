/*
 * main.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: jorge
 */
#include "Chat.h"
#include "Comunicacion.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include<cstdio>

// ./nombre_ejecutable server num_puerto
//./nombre_ejecutable client  localhost num_puerto
int main(int argc, char* argv[]) {
	int error, tam, num;

	char mensaje[300];
	Chat chat;
	if (argc < 3) {
		printf("ERROR: Faltan argumentos \n");
		return ERROR;
	}
	if (strcmp(argv[1], "server") == 0) {
		std::cout << "[main-server] Iniciando app modo SERVIDOR..."<< std::endl;
		error = chat.InitServidor(argv[2], 2);
		if (error == -1) {
			return ERROR;
		}
//		std::cout << "[main-server] Inicio a enviar mensajes"<< std::endl;
		chat.EnviarMensajesAClientes();

	} else if (strcmp(argv[1], "client") == 0) {
		std::cout << "[main-cliente] Iniciando app modo CLIENTE..."<< std::endl;
		error = chat.InitCliente(argv[2], argv[3]);
		if (error == -1) {
			std::cout << "[main-cliente] Error iniciando cliente"<< std::endl;
			return ERROR;
		} else {
			while (error >= 0) {
				std::cout << "[main-cliente] Escriba un mensaje para el servidor."<< std::endl;
				memset(mensaje, 0, sizeof(mensaje));
				fgets(mensaje, 300, stdin);

				tam = strlen(mensaje) - 1; //le resto el \0

				error = chat.enviarMensaje(mensaje,tam);
				if (error == -1)
					std::cout << "[main-cliente] Error enviando el mensaje: "<< mensaje << std::endl;
//				else
//					std::cout << "[main-cliente] Se envió correctamente el mensaje: "<< mensaje << std::endl;

				if (mensaje[0] == 'q'){
					std::cout << "[main-cliente] Un cliente ingresó 'q'. Se cerrará el socket."<< std::endl;
					chat.servidor.close_socket(chat.servidor.socket_cliente);
					return OK;
				}

			}

		}
	}
	return OK;

}
