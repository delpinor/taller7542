/*
 * main.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: jorge
 */

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
	Comunicacion com;
	if (argc < 3) {
		printf("ERROR: Faltan argumentos \n");
		return ERROR;
	}
	if (strcmp(argv[1], "server") == 0) {
		error = com.preparar_socket_servidor(argv[2], 2);
		if (error >= 0) {
			error = com.aceptar_cliente();
		}
		if (error < 0) {
			return ERROR;
		} else {
			while (error >= 0) {
				memset(mensaje, 0, sizeof(mensaje));
				error = com.recibir_mensaje(com.get_socket_cliente(),(char*) &tam, sizeof(int));

				printf("El tamaño de mensaje a recibir es : %d \n", tam);
				error = com.recibir_mensaje(com.get_socket_cliente(), mensaje,tam);
				printf("El mensaje  recibido es: %s \n", mensaje);
				if (mensaje[0] == 'q') {
					error = com.enviar_mensaje(com.get_socket_cliente(),(char*) &tam, sizeof(int));
					error = com.enviar_mensaje(com.get_socket_cliente(),mensaje, tam);
					com.close_socket(com.get_socket_servidor());
					return OK;
				}
				error = com.enviar_mensaje(com.get_socket_cliente(),(char*) &tam, sizeof(int));
				error = com.enviar_mensaje(com.get_socket_cliente(),mensaje, tam);

			}

			com.close_socket(com.get_socket_servidor());
		}

	} else if (strcmp(argv[1], "client") == 0) {

		error = com.preparar_socket_cliente(argv[2], argv[3]);
		if (error < 0) {
			return ERROR;
		} else {
			while (error >= 0) {
				memset(mensaje, 0, sizeof(mensaje));
				fgets(mensaje, 300, stdin);

				tam = strlen(mensaje) - 1; //le resto el \0

				error = com.enviar_mensaje(com.get_socket_cliente(),(char*) &tam, sizeof(int));
				error = com.enviar_mensaje(com.get_socket_cliente(), mensaje,tam);

				error = com.recibir_mensaje(com.get_socket_cliente(),(char*) &tam, sizeof(int));

				printf("El tamaño de mensaje a recibir es : %d \n", tam);
				error = com.recibir_mensaje(com.get_socket_cliente(), mensaje,tam);
				printf("El mensaje  recibido es: %s \n", mensaje);

				if (mensaje[0] == 'q'){
					com.close_socket(com.get_socket_cliente());
					return OK;
				}

			}

		}
	}
	return OK;

}
