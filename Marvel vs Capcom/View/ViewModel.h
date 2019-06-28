#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "../Model/Model.h"
#include "FondoParallax.h"
#include "View_Pantalla.h"
#include "ViewEquipo.h"


using namespace std;
class ViewModel {
public:
	ViewModel(Model* model, SDL_Renderer* gRenderer, SDL_Rect* camara, LTexture* texturaJugador1, LTexture* texturaJugador2);
	virtual ~ViewModel();
	void render();
	void render(int equipo, int zIndex);
	bool hayAlgunJugadorActivoEnEspera();
	void silenciar_juego();
protected:

private:
	ViewEquipo * viewEquipo[2];
	View_Pantalla viewPantalla;
	FondoParallax * fondoParallax;
	SDL_Rect* camara;
	SDL_Renderer* gRenderer;
	Model * model;

};

#endif // VIEWMODEL_H
