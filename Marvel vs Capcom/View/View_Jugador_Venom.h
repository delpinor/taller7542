#ifndef VIEW_JUGADOR_VENOM_H_
#define VIEW_JUGADOR_VENOM_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"
#define CANTSPRITECLIP 10
#define MINFRAMECAMINA 0
#define MAXFRAMECAMINA 9
#define MINFRAMESALTA 0
#define MAXFRAMESALTA 6

class View_Jugador_Venom: public View_Jugador {
public:
	View_Jugador_Venom();
	void initialize(Jugador * model,
		LTexture * texturaJugador);

	SDL_Rect gSpriteCaminar[ MAXFRAMECAMINA];
	SDL_Rect gSpriteCambiarPersonaje[1];
	SDL_Rect gSpriteSaltar[ MAXFRAMESALTA];
	SDL_Rect gSpriteAgachar[ CANTSPRITECLIP];
	SDL_Rect gSpriteGolpear[ CANTSPRITECLIP];
	~View_Jugador_Venom();

private:
	void getSpritesCaminar();
	void getSpritesSaltar();
	void getSpritesAgachar();
	void getSpritesCambioPersonaje();
	void render(int camX, int camY, SDL_Renderer * gRenderer);

};

#endif
