#ifndef VIEW_JUGADOR_CHUNLIBLACK_H_
#define VIEW_JUGADOR_CHUNLIBLACK_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador_ChunLi.h"

class View_Jugador_ChunLiBlack: public View_Jugador_ChunLi {
public:
	View_Jugador_ChunLiBlack();
	void initialize(Jugador *model, LTexture * texturaJugador);


};

#endif
