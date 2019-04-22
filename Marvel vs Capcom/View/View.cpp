#include "View.h"
#include <SDL2/SDL.h>
#include <string>
#include "../Logger/Logger.h"

#define MARGEN 0
int posAnteriorX1, posAnteriorY1;
int posAnteriorX2, posAnteriorY2;


View::View(Model* model) {
	this->alto_Pantalla=model->get_alto_Pantalla();
		this->ancho_Pantalla=model->get_ancho_Pantalla();
		if (!this->inicializar(model)) {
			Logger::Log(LOGGER_NIVEL::ERROR, "View::View", "Erro al inicializar la vista.");
		} else {
			this->loadMedia(model);
			this->model = model;

			int CAMARAPOSICIONINICIALX =ANCHO_NIVEL/2-ancho_Pantalla/2;
			int CAMARAPOSICIONINICIALY =ALTO_NIVEL/2-alto_Pantalla/2;;

			this->camaraStatic = {CAMARAPOSICIONINICIALX,CAMARAPOSICIONINICIALY, ancho_Pantalla, alto_Pantalla};
			this->camara = &(this->camaraStatic);
			this->model->setCamara(this->camara);
			this->model->inicializarPosicionesEquipos();
			this->viewModel = new ViewModel(this->model, this->gRenderer, this->camara,	this->texturasEquipo1, this->texturasEquipo2);
			this->setElementoPersonaje(model);
		}

}

View::~View() {
	delete this->viewModel;
	this->close();
}

void View::ajustarCamara() {

	// Este codigo se puede mejorar.
	int posXJugador1 = model->getEquipoNro(0)->getJugadorActivo()->getPosX();
	int posYJugador1 = model->getEquipoNro(0)->getJugadorActivo()->getPosY();
	int posXJugador2 = model->getEquipoNro(1)->getJugadorActivo()->getPosX();
	int posYJugador2 = model->getEquipoNro(1)->getJugadorActivo()->getPosY();
	//
	int anchoJugador1 = model->getEquipoNro(0)->getJugadorActivo()->get_ancho();

	int anchoJugador2 = model->getEquipoNro(1)->getJugadorActivo()->get_ancho();

	//Chequeo que los jugadores no se salgan del escenario
	if (posXJugador1 + anchoJugador1 > ANCHO_NIVEL)
		model->getEquipoNro(0)->getJugadorActivo()->setPosX(
				ANCHO_NIVEL - anchoJugador1);

	if (posXJugador2 + anchoJugador2 > ANCHO_NIVEL)
		model->getEquipoNro(1)->getJugadorActivo()->setPosX(
				ANCHO_NIVEL - anchoJugador2);

	if (posXJugador1 < 0) {
		model->getEquipoNro(0)->getJugadorActivo()->setPosX(0);
		posXJugador1 = 0;
	}
	if (posXJugador2 < 0) {
		model->getEquipoNro(1)->getJugadorActivo()->setPosX(0);
		posXJugador2 = 0;
	}

	//Muevo la cámara si algún jugador se está saliendo de ella
	if (posXJugador1 + anchoJugador1 > this->camara->x + this->camara->w)
		this->camara->x +=
				model->getEquipoNro(0)->getJugadorActivo()->estado->getVelX();
	else if (posXJugador1 < this->camara->x)
		this->camara->x = posXJugador1;

	if (posXJugador2 + anchoJugador2 > this->camara->x + this->camara->w)
		this->camara->x +=
				model->getEquipoNro(1)->getJugadorActivo()->estado->getVelX();
	else if (posXJugador2 < this->camara->x)
		this->camara->x = posXJugador2;

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

	for (auto iter = this->mapElementosRenderizables.begin(); iter != this->mapElementosRenderizables.end(); ++iter) {
		for (unsigned int i = 0; i < (iter->second).size(); ++i) {
			if((iter->second)[i][MAP_ELEMENTOS_CLAVE_TIPO_ELEMENTO] == TIPO_ELEMENTO_FONDO){
				pantalla->render((iter->second)[i][MAP_ELEMENTOS_CLAVE_FONDOID]);
			}
			else
				if((iter->second)[i][MAP_ELEMENTOS_CLAVE_TIPO_ELEMENTO] == TIPO_ELEMENTO_PERSONAJE){
				this->viewModel->render((iter->second)[i][MAP_ELEMENTOS_CLAVE_EQUIPO], iter->first);
			}
		}
	}
	//this->viewModel->render();

	SDL_RenderPresent(this->gRenderer);
}

bool View::inicializar(Model *model) {
	bool exito = true;

	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		Logger::Log(LOGGER_NIVEL::ERROR, "View::Inicializar", SDL_GetError());
		exito = false;
	} else {
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			Logger::Log(LOGGER_NIVEL::ERROR, "View::Inicializar",
					SDL_GetError());

		}

		//Create window
		this->window = SDL_CreateWindow(
				"Taller de Programacion - Marvel vs Capcom",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				ancho_Pantalla, alto_Pantalla, SDL_WINDOW_SHOWN);
		if (this->window == NULL) {
			Logger::Log(LOGGER_NIVEL::ERROR, "View::Inicializar::",
					SDL_GetError());
			exito = false;
		} else {
			//Create vsynced renderer for this->window
			this->gRenderer = SDL_CreateRenderer(this->window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (this->gRenderer == NULL) {
				Logger::Log(LOGGER_NIVEL::ERROR, "View::Inicializar::",
						SDL_GetError());
				exito = false;
			} else {

				std::string pathZ1 = model->GetPathFondoParallaxByOrden(1);
				std::string pathZ2 = model->GetPathFondoParallaxByOrden(2);
				std::string pathZ3 = model->GetPathFondoParallaxByOrden(3);

				pantalla = new FondoParallax(window, gRenderer,
						pathZ1,
						pathZ2,
						pathZ3);

				if(pathZ1 != ""){
					this->setElementoFondo(model->GetZIndexFondoParallaxByOrden(1), 1);
				}
				if(pathZ2 != ""){
					this->setElementoFondo(model->GetZIndexFondoParallaxByOrden(2), 2);
				}
				if(pathZ3 != ""){
					this->setElementoFondo(model->GetZIndexFondoParallaxByOrden(3), 3);
				}

				//Initialize renderer color
				SDL_SetRenderDrawColor(this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					Logger::Log(LOGGER_NIVEL::ERROR, "View::Inicializar::",
							SDL_GetError());
					exito = false;
				}
			}
		}
	}

	return exito;
}

//Mejoara, la asignacion de imagenes sigue harcodeada
void View::loadMedia(Model *model) {

	string path = model->get_pathImagenJugador(0, 0);
	texturasEquipo1[0].loadFromFile(path, gRenderer, model->GetAnchoJugador(0, 0), model->GetAltoJugador(0, 0));
	path = model->get_pathImagenJugador(0, 1);
	texturasEquipo1[1].loadFromFile(path, gRenderer, model->GetAnchoJugador(0, 1), model->GetAltoJugador(0, 1));
	path = model->get_pathImagenJugador(1, 0);
	texturasEquipo2[0].loadFromFile(path, gRenderer, model->GetAnchoJugador(1, 0), model->GetAltoJugador(1, 0));
	path = model->get_pathImagenJugador(1, 1);
	texturasEquipo2[1].loadFromFile(path, gRenderer, model->GetAnchoJugador(1, 1), model->GetAltoJugador(1, 1));

}

void View::setElementoFondo(int pZIndex, int id){

	std::map<string, int > mapElemento;
	mapElemento[MAP_ELEMENTOS_CLAVE_TIPO_ELEMENTO] = TIPO_ELEMENTO_FONDO;
	mapElemento[MAP_ELEMENTOS_CLAVE_FONDOID] = id;

	int idElemento = this->mapElementosRenderizables[pZIndex].size() + 1;
	this->mapElementosRenderizables[pZIndex][idElemento] = mapElemento;
}

void View::setElementoPersonaje(Model* model){

	Equipo* equipo1 = model->getEquipoNro(0);
	Equipo* equipo2 = model->getEquipoNro(1);

	for(int i = 0; i < equipo1->getCantidadJugadores(); i = i + 1){
		Jugador* jugador = equipo1->jugadores[i];
		this->setElementoPersonaje(jugador->get_zindex(), 0);//, i);
	}

	for(unsigned int i = 0; i < equipo2->getCantidadJugadores(); i = i +1){
		Jugador* jugador = equipo2->jugadores[i];
		this->setElementoPersonaje(jugador->get_zindex(), 1);//, i);
	}
}

void View::setElementoPersonaje(int pZIndex, int equipo){//, int jugador){

	std::map<string, int > mapElemento;
	mapElemento[MAP_ELEMENTOS_CLAVE_TIPO_ELEMENTO] = TIPO_ELEMENTO_PERSONAJE;
	mapElemento[MAP_ELEMENTOS_CLAVE_EQUIPO] = equipo;

	int idElemento = this->mapElementosRenderizables[pZIndex].size() + 1;
	this->mapElementosRenderizables[pZIndex][idElemento] = mapElemento;
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

