#ifndef VIEW_JUGADOR_SPIDERMAN_H_
#define VIEW_JUGADOR_SPIDERMAN_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"
#define CANTSPRITECAMINA 12
#define MINFRAMECAMINA 0
#define MAXFRAMECAMINA 11
#define CANTFRAMESALTA 12
#define MINFRAMESALTA 0
#define MAXFRAMESALTA 11

class View_Jugador_Spiderman: public View_Jugador {
public:
	View_Jugador_Spiderman();
	void initialize(Jugador *model,
		LTexture * texturaJugador);

	SDL_Rect gSpriteCaminar[ CANTSPRITECAMINA];
	SDL_Rect gSpriteCambiarPersonaje[1];
	SDL_Rect gSpriteSaltar[ CANTFRAMESALTA];
	SDL_Rect gSpriteAgachar[ 1];
	SDL_Rect gSpriteGolpear[ CANTSPRITECLIP];
	SDL_Rect gSpriteAnimacion[12];
private:
	int contador=0;

		void getSpritesAnimacion();
	void getSpritesCaminar();
	void getSpritesSaltar();
	void getSpritesAgachar();
	void getSpritesCambioPersonaje();
	void render(int camX, int camY, SDL_Renderer * gRenderer);
};

#endif
