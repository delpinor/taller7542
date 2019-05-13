#ifndef VIEW_JUGADOR_CAPAMERICABLACK_H_
#define VIEW_JUGADOR_CAPAMERICABLACK_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"

class View_Jugador_CapAmericaBlack: public View_Jugador {
public:
	View_Jugador_CapAmericaBlack();
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
