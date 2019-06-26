#ifndef VIEW_H
#define VIEW_H

#include "ViewModel.h"
#include "../Model/Model.h"
#include <string>
#include <cstdlib>
#include <vector>
#include "FondoParallax.h"
#include "Timer.h"
#include "Barras.h"
#include "Show.h"

#define ANCHO_JUGADOR 146
#define ALTO_JUGADOR 146
#define ANCHO_NIVEL 1040
#define ALTO_NIVEL 1080
#define MAP_ELEMENTOS_CLAVE_TIPO_ELEMENTO "TipoElemento"
#define MAP_ELEMENTOS_CLAVE_FONDOID "FondoId"
#define MAP_ELEMENTOS_CLAVE_EQUIPO "Equipo"
#define TIPO_ELEMENTO_FONDO 1
#define TIPO_ELEMENTO_PERSONAJE 2

class View {
public:
	View(Model* model);
	void SetPosicionInicialJugadores();
	//void ajustarCamara();
	void render();
	void renderMensajes();
	void CajaMensaje(string titulo, string cuerpo);
	bool inicializar(Model *model);
	void loadMedia(Model *model);
	void setEstadoCliente();
	SDL_Rect* getCamara();
	void close();
	virtual ~View();

	Model* model;
	void silenciar_juego();
private:

	Jugador* jugadorAnterior;
	ViewModel* viewModel;
	SDL_Rect* camara;
	SDL_Rect camaraStatic;
	SDL_Renderer* gRenderer;
	SDL_Window* window;
	FondoParallax * pantalla;
	Timer * timerJuego;
	Barras * barrasVida;
	Show * leyendas;
	LTexture texturasEquipo1[2];
	LTexture texturasEquipo2[2];
	LTexture texturaCaptainAmerica;
	LTexture texturaVenom;
	LTexture texturaJugador;
	int ancho_Pantalla, alto_Pantalla;
	std::map<int, std::map<int, std::map<string, int > > >  mapElementosRenderizables;
	void setElementoFondo(int pZIndex, int id);
	void setElementoPersonaje(Model* model);
	void setElementoPersonaje(int pZIndex, int equipo);//, int jugador);


};

#endif // VIEW_H
