#ifndef VIEWMENU_H_
#define VIEWMENU_H_
#include "../Model/LTexture.h"
#include "../Comunicacion/EstructuraDatos.h"
#include "../Enums/Personajes.h"
#include <list>
#include <iterator>
#include "../Helper/TimeHelper.h"


struct ModeloPersonajeVistaSeleccion{
	int jugadorId;
	int personajeId;
	bool confirmado;
};
struct ModeloVistaSeleccion {
	bool seleccionFinalizada;
	int cantidadData;
	list<ModeloPersonajeVistaSeleccion> data;
};

class ViewMenu {


private:
	void inicializarClips();
	bool inicializar();
	bool loadMedia();
	bool loadText();
	SDL_Event e;
	ModeloVistaSeleccion modelo;
	std::list<int> personajes;
	int nroJugadorLocal;

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
	LTexture texturaJugadorClienteSeleccionado1;
	LTexture texturaJugadorClienteSeleccionado2;
	LTexture texturaJugadorClienteSeleccionado3;
	LTexture texturaJugadorClienteSeleccionado4;
	LTexture gTextTexture;
	LTexture gTextTexture2;
	LTexture texturaTextoSeleccionadoCliente1;
	LTexture texturaTextoSeleccionadoCliente2;
	LTexture texturaTextoSeleccionadoCliente3;
	LTexture texturaTextoSeleccionadoCliente4;
	TTF_Font *gFont = NULL;
	TTF_Font *gFont2 = NULL;
	int ancho_Pantalla, alto_Pantalla;
	void personajeSiguiente();
	void personajeAnterior();
public:
	ViewMenu(int i);
	void handleEvent(bool *quit, int *personajeSelecionadoId, bool *personajeEstaConfirmado);
	void close();
	void render();
	void setPersonajes(ModeloPersonajes *personajes);
	void setModeloSeleccion(ModeloSeleccion modelo);
	void setNroJugadorLocal(int valor);
	bool hayPersonajes();
	virtual ~ViewMenu();
};

#endif /* VIEWMENU_H_ */
