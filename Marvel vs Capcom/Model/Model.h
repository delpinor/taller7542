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
#include "../Logger/Logger.h"
#include "../Comunicacion/EstructuraDatos.h"
#include "../Helper/TimeHelper.h"

class Model {
public:// hay que pasar los parametros a pivados y generar los seters


	Equipo * equipos[2];

	SDL_Rect * camara;
	std:: map<int, Jugador> jugadores;
	std::map <int, std::string> fondos;
	int ancho_Pantalla, alto_Pantalla;
	std:: map<int, Jugador*> jugadoresEquipo1;
	//std:: map<int, Jugador> jugadoresEquipo2;

public:
	Model();
	// metodo que crea y carga los personajes en un map
	void cargar_Jugadores (std::map< int, std::map<std::string, std::string> > &mapPersonajes);
	void set_equipos_with_jugador(int equipo,int nroJugadorEquipo, int personajeId);
	std::string get_pathImagenJugador(int equipo, int indice_jugador);
	int GetAltoJugador(int equipo, int indice_jugador);
	int GetAnchoJugador(int equipo, int indice_jugador);
	void inicializar();
	void cargar_Fondos(std::map<int, std::map<std::string, std::string> > &mapFondoPantalla);
	std::string GetPathFondoParallax(int indice_Z);
	std::string GetPathFondoParallaxByOrden(int orden);
	int GetZIndexFondoParallaxByOrden(int orden);
	void cargar_Tam_Pantalla(int &ancho, int &alto);
	int get_alto_Pantalla();
	int get_ancho_Pantalla();

	void CargarFondos(std::map<int, std::map<std::string, std::string> > &mapFondoPantalla);
	virtual ~Model();

	virtual void setCamara(SDL_Rect * camara);
	void inicializarPosicionesEquipos();
	ModeloEstado GetModelEstado();
	virtual void update();
	virtual void updateCliente();
	Equipo* getEquipoNro(int i);

	virtual void moverJuego();
	virtual void moverJuegoCliente();

	std::list<int> GetIdsPersonajes();
};

#endif // MODEL_H
