#include "../Model/LTexture.h"
class Show{
private:
	LTexture gReady;
	LTexture gWin;
	LTexture gLose;
	SDL_Renderer * gRenderer;
public:
	Show();
	~Show();
	void render();
};
