#ifndef VIEWMENU_H_
#define VIEWMENU_H_
#include "../Model/LTexture.h"

class ViewMenu {

public:
	int CantidadDeJugadores;
		int PosicionesDemasJugadores[4];
		SDL_Rect spidermanclip, chunliclip, cajpitanclip, venomclip, fondoclip;
		int npersonaje,framealpha;
		SDL_Renderer* gRenderer;
		SDL_Window* window;
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
		const int ANCHO_CUADRO = 118;
		const int ALTO_CUADRO = 40;

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
		LTexture texturaTextoSeleccionado;
		LTexture texturaTextoSeleccionadoCliente;
		TTF_Font *gFont = NULL;
		TTF_Font *gFont2 = NULL;
		int ancho_Pantalla, alto_Pantalla;

		enum PERSONAJE {
			P_NAP = -1,
			P_SPIDERMAN = 1,
			P_CHUN_LI = 2,
			P_CAPITAN_AMERICA = 3,
			P_VENOM = 4
		};
	void personajeSiguiente();
	void personajeAnterior();
	ViewMenu();
	virtual ~ViewMenu();
	bool inicializar();
	bool loadMedia();
	bool loadText();
	void close();
	void render();
};

#endif /* VIEWMENU_H_ */
