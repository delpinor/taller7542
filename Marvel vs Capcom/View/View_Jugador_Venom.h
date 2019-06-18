#ifndef VIEW_JUGADOR_VENOM_H_
#define VIEW_JUGADOR_VENOM_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"

class View_Jugador_Venom: public View_Jugador {
public:
	View_Jugador_Venom();
	void initialize(Jugador * model,
		LTexture * texturaJugador);

	~View_Jugador_Venom();

protected:

	void getSpritesAnimacion();
	void getSpritesCaminar();
	void getSpritesSaltar();
	void getSpritesAgachar();
	void getSpritesCambioPersonaje();
	void getSpritesPatadaFuerte();

};

#endif
