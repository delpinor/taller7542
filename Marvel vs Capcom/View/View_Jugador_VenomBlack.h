#ifndef VIEW_JUGADOR_VENOMBLACK_H_
#define VIEW_JUGADOR_VENOMBLACK_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador_Venom.h"

class View_Jugador_VenomBlack: public View_Jugador_Venom {
public:
	View_Jugador_VenomBlack();

	void initialize(Jugador * model,
		LTexture * texturaJugador);
	//virtual ~View_Jugador_VenomBlack();
};
#endif
