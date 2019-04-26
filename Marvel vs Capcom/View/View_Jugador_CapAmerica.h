#ifndef VIEW_JUGADOR_CAPAMERICA_H_
#define VIEW_JUGADOR_CAPAMERICA_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"
#define CANTSPRITECLIP 6
#define CANTSPRITECLIPCAMINA 12
#define MINFRAMECAMINA 0
#define MAXFRAMECAMINA 11
#define CANTSPRITECLIPSALTA 7
#define MINFRAMESALTA 0
#define MAXFRAMESALTA 6
#define CANTSPRITEANIMACION 6
#define MINFRAMEANIMACION 0
#define MAXFRAMEANIMACION 5

class View_Jugador_CapAmerica: public View_Jugador {
public:
	View_Jugador_CapAmerica();
	void initialize(Jugador *model,
		LTexture * texturaJugador);

	SDL_Rect gSpriteCaminar[ CANTSPRITECLIPCAMINA];
	SDL_Rect gSpriteCambiarPersonaje[1];
	SDL_Rect gSpriteSaltar[ CANTSPRITECLIPSALTA];
	SDL_Rect gSpriteAgachar[1];
	SDL_Rect gSpriteGolpear[ CANTSPRITECLIP];
	SDL_Rect gSpriteAnimacion[CANTSPRITEANIMACION];
private:
	//variable que uso para ajusatr la animacion
	int contador=0;

	void getSpritesAnimacion();
	void getSpritesCaminar();
	void getSpritesSaltar();
	void getSpritesAgachar();
	void getSpritesCambioPersonaje();
	void render(int camX, int camY, SDL_Renderer * gRenderer);
};

#endif
