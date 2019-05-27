/*
 * EstructuraDatos.h
 *
 *  Created on: 5 may. 2019
 *      Author: delpinor
 */

#ifndef ESTRUCTURADATOS_H_
#define ESTRUCTURADATOS_H_

#include <iostream>
#include <list>
#include <map>
#include <iterator>

//Enumera de cabecera
enum IDMENSAJE {
	PING = 1, JUGADOR = 2, MENSAJE = 3, LOGIN = 4, SALIDA = 5, EQUIPO = 6, TITULAR = 7, MODELO = 8, COMANDO = 9, MODELOSELECCION = 10, DATASELECCION = 11, DATAPERSONAJES = 12
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
struct ModeloSeleccionPersonaje{
<<<<<<< Updated upstream
       int jugadorId;
       int personajeId;
       bool confirmado;
};
struct ModeloSeleccion {
       bool seleccionFinalizada;
       std::list<ModeloSeleccionPersonaje> data;
};

struct ModeloPersonajes {
	std::list<int> idsPersonajes;
=======
	int jugadorId;
	int personajeId;
	bool confirmado;
};
struct ModeloSeleccion {
	bool seleccionFinalizada;
	std::list<ModeloSeleccionPersonaje> data;
>>>>>>> Stashed changes
};
struct ComandoAlServidor{
	int comando;
};
struct Mensaje {
	char mensaje[300];
};
struct ClienteEquipo {
	int equipo;
	bool titular;
};
struct ClienteLogin{
	char usuario[50];
};
struct JugadorTitular{
	bool titular;
};
struct DataSeleccionAlServidor{
	int personajeId;
	bool confirmado;
};







#endif /* ESTRUCTURADATOS_H_ */
