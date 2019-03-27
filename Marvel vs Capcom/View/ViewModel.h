#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "View_Jugador.h"
#include "../Model/Model.h"
#include "View_Pantalla.h"

class ViewModel {
public:
	ViewModel(Model* model, SDL_Renderer* gRenderer, SDL_Rect* camara,
			LTexture * texturaPantalla, LTexture texturaJugador[]);
	virtual ~ViewModel();
	void render();
	bool hayAlgunJugadorActivoEnEspera();
protected:

private:
	View_Jugador* viewJugadores;
	View_Pantalla viewPantalla;
	SDL_Rect* camara;
	SDL_Renderer* gRenderer;
	int cantidadjugadores;
};

#endif // VIEWMODEL_H
