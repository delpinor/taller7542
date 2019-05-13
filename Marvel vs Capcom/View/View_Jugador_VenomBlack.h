#ifndef VIEW_JUGADOR_VENOMBLACK_H_
#define VIEW_JUGADOR_VENOMBLACK_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"
//#define CANTSPRITECLIPCAMINA 10
//#define MINFRAMECAMINA 0
//#define MAXFRAMECAMINA 9
//#define CANTSPRITECLIPSALTA 6
//#define MINFRAMESALTA 0
//#define MAXFRAMESALTA 5
//#define CANTSPRITEANIMACION 7
//#define MINFRAMEANIMACION 0
//#define MAXFRAMEANIMACION 6

class View_Jugador_VenomBlack: public View_Jugador {
public:
	View_Jugador_VenomBlack();
	void initialize(Jugador * model,
		LTexture * texturaJugador);

//	SDL_Rect gSpriteCaminar[ CANTSPRITECLIPCAMINA];
//	SDL_Rect gSpriteCambiarPersonaje[1];
//	SDL_Rect gSpriteSaltar[ CANTSPRITECLIPSALTA];
//	SDL_Rect gSpriteAgachar[ 1];
//	SDL_Rect gSpriteGolpear[ 1];
//	SDL_Rect gSpriteAnimacion[CANTSPRITEANIMACION];
	~View_Jugador_VenomBlack();

private:
//	int contador=0;
	void getSpritesAnimacion();
	void getSpritesCaminar();
	void getSpritesSaltar();
	void getSpritesAgachar();
	void getSpritesCambioPersonaje();
//	void render(int camX, int camY, SDL_Renderer * gRenderer);

};

#endif
