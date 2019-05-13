#ifndef VIEW_JUGADOR_SPIDERMAN_H_
#define VIEW_JUGADOR_SPIDERMAN_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"

class View_Jugador_Spiderman: public View_Jugador {
public:
	View_Jugador_Spiderman();
	void initialize(Jugador *model,
		LTexture * texturaJugador);

private:
	void getSpritesAnimacion();
	void getSpritesCaminar();
	void getSpritesSaltar();
	void getSpritesAgachar();
	void getSpritesCambioPersonaje();
};

#endif
