#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "View_Jugador.h"
#include "View_Jugador_CapAmerica.h"
#include "View_Jugador_Venom.h"
#include "../Model/Model.h"
#include "View_Pantalla.h"
#include <vector>
#define maxCantJugadores 2

using namespace std;
class ViewModel {
public:
	ViewModel(Model* model, SDL_Renderer* gRenderer, SDL_Rect* camara,
			LTexture * texturaPantalla, LTexture texturaJugador[]);
	virtual ~ViewModel();
	void render();
	bool hayAlgunJugadorActivoEnEspera();
protected:

private:

	View_Jugador* viewJugadores[maxCantJugadores];
	View_Pantalla viewPantalla;
	SDL_Rect* camara;
	SDL_Renderer* gRenderer;
	int cantidadjugadores;
};

#endif // VIEWMODEL_H
