#ifndef VIEW_PANTALLA_H_
#define VIEW_PANTALLA_H_

#include <SDL2/SDL.h>
#include "../Model/LTexture.h"

class View_Pantalla {
public:
	View_Pantalla();

	void initialize(SDL_Renderer * gRenderer, LTexture * texturaPantalla);

	void render(SDL_Rect * camara, SDL_Renderer * gRenderer);

private:
	LTexture * texturaPantalla;
};

#endif
