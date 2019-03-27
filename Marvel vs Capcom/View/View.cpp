#include "View.h"
#include <SDL2/SDL.h>

#define MARGEN 0
#define CAMARAPOSICIONINICIALX (((ANCHO_NIVEL)/2)-((ANCHO_VENTANA)/2))
#define CAMARAPOSICIONINICIALY (((ALTO_NIVEL)/2)-((ALTO_VENTANA)/2))

View::View(Model* model) {
	if (!this->inicializar()) {
		//error
	} else {
		this->loadMedia();
		this->model = model;
		this->camaraStatic = {CAMARAPOSICIONINICIALX,CAMARAPOSICIONINICIALY, ANCHO_VENTANA, ALTO_VENTANA};
		this->camara = &(this->camaraStatic);
		this->model->setCamara(this->camara);
		this->viewModel = new ViewModel(this->model, this->gRenderer,
				this->camara, &(this->texturaPantalla),
				this->texturas);
	}

}

View::~View() {
	delete this->viewModel;
	this->close();
}

void View::ajustarCamara() {

	this->camara->x = (model->getJugadorActivo()->getPosX() + 12 / 2)
			- ANCHO_VENTANA / 2;
	this->camara->y = (model->getJugadorActivo()->getPosY() + 12 / 2)
			- ALTO_VENTANA / 2;

	//Keep the this->camara->in bounds
	if (this->camara->x < 0) {
		this->camara->x = 0;
	}
	if (this->camara->y < 0) {
		this->camara->y = 0;
	}
	if (this->camara->x > ANCHO_NIVEL - this->camara->w) {
		this->camara->x = ANCHO_NIVEL - this->camara->w;
	}
	if (this->camara->y > ALTO_NIVEL - this->camara->h) {
		this->camara->y = ALTO_NIVEL - this->camara->h;
	}

}

void View::render() {
	this->ajustarCamara();
	SDL_SetRenderDrawColor(this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(this->gRenderer);

	this->viewModel->render();

	SDL_RenderPresent(this->gRenderer);

}

bool View::inicializar() {
	bool exito = true;

	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());

		exito = false;
	} else {
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");

		}

		//Create window
		this->window = SDL_CreateWindow(
				"Taller de Programacion - Marvel vs Capcom",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ANCHO_VENTANA,
				ALTO_VENTANA, SDL_WINDOW_SHOWN);
		if (this->window == NULL) {
			printf("Window could not be created! SDL Error: %s\n",
					SDL_GetError());

			exito = false;
		} else {
			//Create vsynced renderer for this->window
			this->gRenderer = SDL_CreateRenderer(this->window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (this->gRenderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n",
						SDL_GetError());

				exito = false;
			} else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					printf(
							"SDL_image could not initialize! SDL_image Error: %s\n",
							IMG_GetError());

					exito = false;
				}
			}
		}
	}

	return exito;
}

void View::loadMedia() {

	texturas[0].loadFromFile("Images/Captain America.gif", gRenderer);
	texturas[1].loadFromFile("Images/Venom.png", gRenderer);
//	texturaCaptainAmerica.loadFromFile("Images/Captain America.gif", gRenderer);
//	texturaVenom.loadFromFile("Images/Venom.png", gRenderer);
//	texturaJugador = texturaCaptainAmerica;// sacar cuando resuelva como guardarlas en una coleccion
	texturaPantalla.loadFromFile("Images/Background.gif", gRenderer);
}
void View::close() {

	//Destroy this->window}
	SDL_DestroyRenderer(this->gRenderer);
	SDL_DestroyWindow(this->window);

	this->gRenderer = NULL;
	this->window = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

}

