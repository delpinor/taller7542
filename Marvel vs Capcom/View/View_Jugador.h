#ifndef VIEW_JUGADOR_H_
#define VIEW_JUGADOR_H_
#include <SDL2/SDL.h>
#include "../Model/LTexture.h"
#include "../Model/Model_Jugador.h"
#define CANTSPRITECLIP 10
#define MINFRAMECAMINA 0
#define MAXFRAMECAMINA 9
class View_Jugador {
public:

	View_Jugador(Jugador *model);
	View_Jugador();
	virtual void initialize(Jugador *model, LTexture * texturaJugador);
	virtual void render(int camX, int camY, SDL_Renderer * gRenderer);
	Jugador *model;

protected:

	LTexture * texturaJugador;
	int frame = 0;
	SDL_RendererFlip direccion;
	void getSpritesCaminar();

};

#endif
