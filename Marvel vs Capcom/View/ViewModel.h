#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "../Model/Model.h"
#include "View_Pantalla.h"
#include "ViewEquipo.h"


using namespace std;
class ViewModel {
public:
	ViewModel(Model* model, SDL_Renderer* gRenderer, SDL_Rect* camara, LTexture* texturaJugador1, LTexture* texturaJugador2);
	virtual ~ViewModel();
	void render();
	bool hayAlgunJugadorActivoEnEspera();
protected:

private:
	ViewEquipo * viewEquipo[2];
	View_Pantalla viewPantalla;
	SDL_Rect* camara;
	SDL_Renderer* gRenderer;
	Model * model;

};

#endif // VIEWMODEL_H
