#ifndef VIEW_JUGADOR_CAPAMERICA_H_
#define VIEW_JUGADOR_CAPAMERICA_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"
#define CANTSPRITECLIP 6
#define MINFRAMECAMINA 0
#define MAXFRAMECAMINA 12
#define CANTSPRITECLIPSALTA 7
#define MINFRAMESALTA 0
#define MAXFRAMESALTA 12

class View_Jugador_CapAmerica: public View_Jugador {
public:
	View_Jugador_CapAmerica();
	void initialize(Jugador *model,
		LTexture * texturaJugador);

	SDL_Rect gSpriteCaminar[ MAXFRAMECAMINA];
	SDL_Rect gSpriteCambiarPersonaje[1];
	SDL_Rect gSpriteSaltar[ CANTSPRITECLIPSALTA];
	SDL_Rect gSpriteAgachar[1];
	SDL_Rect gSpriteGolpear[ CANTSPRITECLIP];
private:
	void getSpritesCaminar();
	void getSpritesSaltar();
	void getSpritesAgachar();
	void getSpritesCambioPersonaje();
	void render(int camX, int camY, SDL_Renderer * gRenderer);
};

#endif
