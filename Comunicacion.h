/*
 * Comunicacion.h
 *
 *  Created on: Apr 29, 2019
 *      Author: jorge
 */

#ifndef COMUNICACION_H_
#define COMUNICACION_H_

#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define OK 0
#define ERROR -1

class Comunicacion {

public:
	int socket_servidor, socket_cliente;

	Comunicacion();
	int preparar_socket_servidor(const char* puerto_numero, int num_clientes_espera);
	int aceptar_cliente();
	int preparar_socket_cliente(char *nom_servidor, const char* puerto_num);
	int enviar_mensaje(int socket, char* mensaje, int tam_mensaje);
	int recibir_mensaje(int socket, char* mensaje, int tam_mensaje);
	int get_socket_cliente();
	int get_socket_servidor();
	void close_socket(int socket);
	virtual ~Comunicacion();
};

#endif /* COMUNICACION_H_ */
