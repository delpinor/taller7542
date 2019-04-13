#include "View.h"
#include <SDL2/SDL.h>

#define MARGEN 0
//#define CAMARAPOSICIONINICIALX (((ANCHO_NIVEL)/2)-((ANCHO_VENTANA)/2))
//#define CAMARAPOSICIONINICIALY (((ALTO_NIVEL)/2)-((ALTO_VENTANA)/2))

View::View(Model* model) {
	this->alto_Pantalla=model->get_alto_Pantalla();
	this->ancho_Pantalla=model->get_ancho_Pantalla();
	if (!this->inicializar(model)) {
		Logger::Log(LOGGER_NIVEL::ERROR, "View::View", "Erro al inicializar la vista.");
	} else {
		this->loadMedia(model);
		this->model = model;

		int CAMARAPOSICIONINICIALX =ANCHO_NIVEL/2-ancho_Pantalla/2;
		int CAMARAPOSICIONINICIALY =ALTO_NIVEL/2-alto_Pantalla/2;

		this->camaraStatic = {CAMARAPOSICIONINICIALX,CAMARAPOSICIONINICIALY, ancho_Pantalla, alto_Pantalla};
		this->camara = &(this->camaraStatic);
		this->model->setCamara(this->camara);
		this->viewModel = new ViewModel(this->model, this->gRenderer,this->camara, this->texturas);

	}

}

View::~View() {
	delete this->viewModel;
	this->close();
}

void View::ajustarCamara() {

	for (int i = 0; i < 2; ++i) {

	this->camara->x = (model->getEquipoNro(i)->getJugadorActivo()->getPosX() + 12 / 2)
			- ancho_Pantalla / 2;
	this->camara->y = (model->getEquipoNro(i)->getJugadorActivo()->getPosY() + 12 / 2)
			- alto_Pantalla / 2;
	}
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
	pantalla->refrescarPosicion(camara);
	this->viewModel->render();
	SDL_RenderPresent(this->gRenderer);

}

bool View::inicializar(Model *model) {
	bool exito = true;

	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		Logger::Log(LOGGER_NIVEL::ERROR, "View::Inicializar", SDL_GetError());
		exito = false;
	} else {
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			Logger::Log(LOGGER_NIVEL::ERROR, "View::Inicializar", SDL_GetError());

		}

		//Create window
		this->window = SDL_CreateWindow(
				"Taller de Programacion - Marvel vs Capcom",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ancho_Pantalla,
				alto_Pantalla, SDL_WINDOW_SHOWN);
		if (this->window == NULL) {
			Logger::Log(LOGGER_NIVEL::ERROR, "View::Inicializar::", SDL_GetError());
			exito = false;
		} else {
			//Create vsynced renderer for this->window
			this->gRenderer = SDL_CreateRenderer(this->window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (this->gRenderer == NULL) {
				Logger::Log(LOGGER_NIVEL::ERROR, "View::Inicializar::", SDL_GetError());
				exito = false;
			} else {
				pantalla = new FondoParallax(window, gRenderer, model->GetPathFondoParallax(1), model->GetPathFondoParallax(2), model->GetPathFondoParallax(3));

				//Initialize renderer color
				SDL_SetRenderDrawColor(this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					Logger::Log(LOGGER_NIVEL::ERROR, "View::Inicializar::", SDL_GetError());
					exito = false;
				}
			}
		}
	}


return exito;
}

//Mejoara, la asignacion de imagenes sigue harcodeada
void View::loadMedia(Model *model) {

	//texturas[0].loadFromFile("Images/Captain America.gif", gRenderer);
	//texturas[1].loadFromFile("Images/Venom.png", gRenderer);
	texturas[0].loadFromFile(model->get_pathImagenJugador(0), gRenderer);
	texturas[1].loadFromFile(model->get_pathImagenJugador(1), gRenderer);
//	texturaCaptainAmerica.loadFromFile("Images/Captain America.gif", gRenderer);
//	texturaVenom.loadFromFile("Images/Venom.png", gRenderer);
//	texturaJugador = texturaCaptainAmerica;// sacar cuando resuelva como guardarlas en una coleccion

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

