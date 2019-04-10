#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include "Model_Jugador.h"
#include "Equipo.h"
#include "../Command/Command.h"
#include <queue>
#include <map>


class Model {
public:// hay que pasar los parametros a pivados y generar los seters


	Equipo * equipos;

	SDL_Rect * camara;
	std:: map<int, Jugador> jugadoresEquipo1;
	//std:: map<int, Jugador> jugadoresEquipo2;

public:
	Model();
	// meétodo que crea y carga los personajes en un map
	void cargar_Jugadores (std::map< int, std::map<std::string, std::string> > &mapPersonajes);
	void set_equipos_with_jugador(int equipo,int nroJugadorEquipo, int jugador);
	std::string get_pathImagenJugador(int equipo, int indice_jugador);
	void inicializar();
	void cargar_Fondos(std::map<int, std::map<std::string, std::string> > &mapFondoPantalla);
	virtual ~Model();

	virtual void setCamara(SDL_Rect * camara);
	virtual void update();
	Equipo* getEquipoNro(int i);

	virtual void moverJuego();

};

#endif // MODEL_H
