#ifndef VIEW_JUGADOR_CAPAMERICA_H_
#define VIEW_JUGADOR_CAPAMERICA_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"

class View_Jugador_CapAmerica: public View_Jugador {
public:
	View_Jugador_CapAmerica();
	void initialize(Jugador *model, LTexture * texturaJugador);

private:
	//variable que uso para ajusatr la animacion

	void getSpritesAnimacion();
	void getSpritesCaminar();
	void getSpritesSaltar();
	void getSpritesAgachar();
	void getSpritesCambioPersonaje();
};

#endif
