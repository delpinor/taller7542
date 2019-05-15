#ifndef VIEW_JUGADOR_CAPAMERICABLACK_H_
#define VIEW_JUGADOR_CAPAMERICABLACK_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador_CapAmerica.h"

class View_Jugador_CapAmericaBlack: public View_Jugador_CapAmerica{
public:
	View_Jugador_CapAmericaBlack();
	void initialize(Jugador *model,
		LTexture * texturaJugador);
};

#endif
