#ifndef VIEW_JUGADOR_SPIDERMAN_H_
#define VIEW_JUGADOR_SPIDERMAN_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"
#define CANTSPRITECAMINA 12
#define MINFRAMECAMINA 0
#define MAXFRAMECAMINA 11
#define MINFRAMESALTA 0
#define CANTFRAMESALTA 10
#define MINFRAMESALTA 0
#define MAXFRAMESALTA 9

class View_Jugador_Spiderman: public View_Jugador {
public:
	View_Jugador_Spiderman();
	void initialize(Jugador *model,
		LTexture * texturaJugador);

	SDL_Rect gSpriteCaminar[ MAXFRAMECAMINA];
	SDL_Rect gSpriteCambiarPersonaje[1];
	SDL_Rect gSpriteSaltar[ CANTFRAMESALTA];
	SDL_Rect gSpriteAgachar[ CANTSPRITECLIP];
	SDL_Rect gSpriteGolpear[ CANTSPRITECLIP];
private:
	void getSpritesCaminar();
	void getSpritesSaltar();
	void getSpritesAgachar();
	void getSpritesCambioPersonaje();
	void render(int camX, int camY, SDL_Renderer * gRenderer);
};

#endif
