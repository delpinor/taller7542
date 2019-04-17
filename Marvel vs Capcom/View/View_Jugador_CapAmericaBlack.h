#ifndef VIEW_JUGADOR_SPIDERMAN_H_
#define VIEW_JUGADOR_SPIDERMAN_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"
#define CANTSPRITECLIP 6
#define MINFRAMECAMINA 0
#define MAXFRAMECAMINA 5
#define MINFRAMESALTA 0
#define MAXFRAMESALTA 6

class View_Jugador_CapAmericaBlack: public View_Jugador {
public:
	View_Jugador_CapAmericaBlack();
	void initialize(Jugador *model,
		LTexture * texturaJugador);

	SDL_Rect gSpriteCaminar[ MAXFRAMECAMINA];
	SDL_Rect gSpriteSaltar[ MAXFRAMESALTA];
	SDL_Rect gSpriteAgachar[ CANTSPRITECLIP];
	SDL_Rect gSpriteGolpear[ CANTSPRITECLIP];
private:
	void getSpritesCaminar();
	void getSpritesSaltar();
	void render(int camX, int camY, SDL_Renderer * gRenderer);
};

#endif
