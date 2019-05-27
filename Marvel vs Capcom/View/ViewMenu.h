#ifndef VIEWMENU_H_
#define VIEWMENU_H_
#include "../Model/LTexture.h"
#include "../Comunicacion/EstructuraDatos.h"
#include "../Enums/Personajes.h"
#include <list>
#include <iterator>
class ViewMenu {

public:
		ViewMenu(ModeloSeleccion * modelo);
		int CantidadDeJugadores;
		SDL_Rect spidermanclip, chunliclip, cajpitanclip, venomclip, fondoclip;
		int npersonaje,framealpha;
		SDL_Renderer* gRenderer;
		SDL_Window* window;
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
		const int POS_CUADROX = 10;
		const int POS_CUADROY = 40;
		const int ANCHO_CUADRO_JUGADOR = 118;
		const int ALTO_CUADRO_JUGADOR = 215;
		LTexture texturaSpiderman;
		LTexture texturaChunLi;
		LTexture texturaCapitan;
		LTexture texturaVenom;
		LTexture texturaMenuSelec;
		LTexture texturaFondo;
		LTexture texturaLogo;
		LTexture texturaJugadorSeleccionado;
		LTexture texturaJugadorClienteSeleccionado;
		LTexture gTextTexture;
		LTexture gTextTexture2;
		LTexture texturaTextoSeleccionadoCliente1;
		LTexture texturaTextoSeleccionadoCliente2;
		LTexture texturaTextoSeleccionadoCliente3;
		LTexture texturaTextoSeleccionadoCliente4;
		TTF_Font *gFont = NULL;
		TTF_Font *gFont2 = NULL;
		int ancho_Pantalla, alto_Pantalla;
		ModeloSeleccion *  modelo;
	void personajeSiguiente();
	void personajeAnterior();
	virtual ~ViewMenu();
	bool inicializar();
	bool loadMedia();
	bool loadText();
	void close();
	void render();
};

#endif /* VIEWMENU_H_ */
