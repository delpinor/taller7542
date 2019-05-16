/*
 * EstructuraDatos.h
 *
 *  Created on: 5 may. 2019
 *      Author: delpinor
 */

#ifndef ESTRUCTURADATOS_H_
#define ESTRUCTURADATOS_H_

//Enumera de cabecera
enum IDMENSAJE {
	PING = 1, JUGADOR = 2, MENSAJE = 3, LOGIN = 4, SALIDA = 5, EQUIPO = 6, TITULAR = 7, MODELO = 8, COMANDO = 9
};
struct JugadorLogin{
	char usuario[20];

};
//Estructuras de envio

struct JugadorCliente {
	int equipo;
	int posX;
	int posY;
	int velX;
	int velY;
	bool isActivo = false;
	bool isAgachado = false;
	bool isCambiandoPersonaje = false;
};
struct CamaraCliente {
	int posX;
	int posY;
};
struct ModeloEstado {
	int activoEquipo1;
	int activoEquipo2;
	struct JugadorCliente jugadoresEquipo1;
	struct JugadorCliente jugadoresEquipo2;
	struct CamaraCliente camara;
};
struct ComandoAlServidor{
	int comando;
};
struct Mensaje {
	char mensaje[300];
};
struct JugadorEquipo {
	int equipo;
	bool titular;
};
struct ClienteLogin{
	char usuario[50];
};
struct JugadorTitular{
	bool titular;
};






#endif /* ESTRUCTURADATOS_H_ */
