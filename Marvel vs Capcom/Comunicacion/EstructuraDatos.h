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

//Mensajes a clientes
enum TIPOLEYENDA{
	READY = 901, YOUWIN = 902, YOULOSE = 903, RESULTADOS = 904, NINGUNO = 910
};
//Enumera de cabecera
enum IDMENSAJE {
	PING = 100, JUGADOR = 2, MENSAJE = 3, LOGIN = 4, COMPLETO = 5, EQUIPO = 6, TITULAR = 7, MODELO = 8, COMANDO = 9,
	MODELOSELECCION = 10, DATASELECCION = 11, DATAPERSONAJES = 12, TEST = 13, JUEGOINICIADO = 14, SERVIDORMUERTO = 15,ACEPTADO = 16,
	INGAME = 17, JUEGOFINALIZADO = 18
};
struct JugadorLogin{
	char usuario[20];

};
//Estructuras de envio
struct PersonajeJugando{
	int vida;
};
struct ModeloInGame{
	int tiempo;
	char mensaje[200];
	TIPOLEYENDA tipoMensaje; //1 READY - 2 YOU WIN - 3 YOULOSE - 10 NINGUNO
	PersonajeJugando personajesEquipo0[2];
	PersonajeJugando personajesEquipo1[2];

};

struct JugadorCliente {
	int equipo;
	int posX;
	int posY;
	int velX;
	int velY;
	bool isActivo = false;
	bool isAgachado = false;
	bool isCambiandoPersonaje = false;
	bool isSaltando = false;
};

struct CamaraCliente {
	int posX;
	int posY;
};
struct ModeloEstado {
	int tiempo;
	int activoEquipo1;
	int activoEquipo2;
	struct JugadorCliente jugadoresEquipo1;
	struct JugadorCliente jugadoresEquipo2;
	struct CamaraCliente camara;
};
struct ModeloSeleccionPersonaje{
	int jugadorId;
	int personajeId;
	int equipo;
	bool confirmado;
	//0 o 1
	int numeroJugador;
};
struct ModeloSeleccion {
	bool seleccionFinalizada;
	int cantidadData;
	struct ModeloSeleccionPersonaje data[4];
};

struct ModeloPersonajes {
	int idsPersonajes[5];
	int cantidadPersonajes;
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
	int nroJugador;
	int cantidadEquipo;
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

struct ModeloTest{
	int nums[10];
	//std::string msj;
};
struct ModeloSeleccionTest {
	bool seleccionFinalizada;
	int cantidadData;
	struct ModeloSeleccionPersonaje data[4];
//	struct ModeloSeleccionPersonaje jugadorA;
//	struct ModeloSeleccionPersonaje jugadorB;
//	struct ModeloSeleccionPersonaje jugadorC;
//	struct ModeloSeleccionPersonaje jugadorD;
};
struct ModeloResultadoSeleccionItem{
	int cantidadPersonajes;
	int personaje1Id;
	int personaje2Id;
	int equipo;
	int numeroJugador;
};
struct ModeloResultadoSeleccionPersonaje{
	struct ModeloResultadoSeleccionItem data[4];
	int cantidadData;
};




#endif /* ESTRUCTURADATOS_H_ */
