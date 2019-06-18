#include "Show.h"
Show::Show(SDL_Renderer * gRen){
	gRenderer = gRen;
	gReady.loadFromFile("Images/ready_ok.png", gRenderer, 400, 300);
}
void Show::render(int tipo){
	if(tipo == 1){
		gReady.render(200, 200, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	}
}
Show::~Show(){
	gReady.free();
}
