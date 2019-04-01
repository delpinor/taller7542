#include "FondoParallax.h"
#include "../Logger/Logger.h"
#define ANCHO_IMAGEN 2618
#define ANCHO_VENTANA 800
#define ALTO_VENTANA 600
#define FONDO_Z1 "Images/fondo_piso.png"
#define FONDO_Z2 "Images/fondo_nubes.png"
#define FONDO_Z3 "Images/fondo_monta.png"
FondoParallax::FondoParallax(SDL_Window * ventana, SDL_Renderer * renderer,
		int ancho, int alto) {
	this->ventana = ventana;
	this->renderer = renderer;
	this->anchoPantalla = ancho;
	this->altoPantalla = alto;
	fondoZ1 = NULL;
	fondoZ2 = NULL;
	fondoZ3 = NULL;
	temp_surface = NULL;
	cargaInicial();
}
FondoParallax::~FondoParallax() {
	SDL_DestroyTexture(fondoZ1);
	SDL_DestroyTexture(fondoZ2);
	SDL_DestroyTexture(fondoZ3);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(ventana);
	SDL_Quit();

}
// Mueve los fondos de acuerdo a la posicion de la camara.
void FondoParallax::refrescar(SDL_Rect * cam) {
	SDL_RenderClear(renderer);
	if (cam->x > pos_x_anterior) {
		moverDerecha(1);
	}
	if (cam->x < pos_x_anterior) {
		moverIzquierda(1);
	}
	pos_x_anterior = cam->x;
	Logger::Log(NIVEL_LOGGER::DEBUG, "Parallax:Refrescar", "CámaraPosX:"+ std::to_string(cam->x));
	SDL_RenderCopy(renderer, fondoZ3, &rectZ3_Desde, &rectZ3_Hasta);
	SDL_RenderCopy(renderer, fondoZ2, &rectZ2_Desde, &rectZ2_Hasta);
	SDL_RenderCopy(renderer, fondoZ1, &rectZ1_Desde, &rectZ1_Hasta);
}
// Mover fondo a derecha * multiplicador de velocidad
void FondoParallax::moverDerecha(int velocidad) {
	if ((rectZ1_Desde.x + rectZ1_Desde.w) < ANCHO_IMAGEN) {
		rectZ3_Desde.x += 1 * velocidad;
		rectZ2_Desde.x += 3 * velocidad;
		rectZ1_Desde.x += 8 * velocidad;
	}

}
// Mover fondo a Izquierda * multiplicador de velocidad
void FondoParallax::moverIzquierda(int velocidad) {
	if (rectZ1_Desde.x > 0) {
		rectZ3_Desde.x -= 1 * velocidad;
		rectZ2_Desde.x -= 3 * velocidad;
		rectZ1_Desde.x -= 8 * velocidad;
	}
}
// Carga los fondos z1, z2 y z3
void FondoParallax::cargaInicial() {
	int w, h;
	float fh;

	// fondo Z3
	temp_surface = IMG_Load(FONDO_Z3);
	if (temp_surface == NULL) {
		Logger::Log(NIVEL_LOGGER::ERROR, "FondoParallax:CargaInicial",
				SDL_GetError());
	} else {
		fondoZ3 = SDL_CreateTextureFromSurface(renderer, temp_surface);
		if (fondoZ3 == NULL) {
			Logger::Log(NIVEL_LOGGER::ERROR, "FondoParallax:CargaInicial",
					SDL_GetError());
		} else {
			SDL_QueryTexture(fondoZ3, NULL, NULL, &w, &h);
			fh = (float) h;

			rectZ3_Hasta.w = anchoPantalla;
			rectZ3_Hasta.h = altoPantalla * 1.3;
			rectZ3_Hasta.x = 0;
			rectZ3_Hasta.y = -50;

			rectZ3_Desde.w = roundf(
					(float) anchoPantalla * ((fh / (float) rectZ3_Hasta.h)));
			rectZ3_Desde.h = h;
			rectZ3_Desde.x = 20;
			rectZ3_Desde.y = 0;
			Logger::Log(NIVEL_LOGGER::INFO, "FondoParallax:CargaInicial",
					"Carga fondo Z3: OK");
		}
	}
	// Fondo Z2
	temp_surface = IMG_Load(FONDO_Z2);
	if(temp_surface==NULL){
		Logger::Log(NIVEL_LOGGER::ERROR, "FondoParallax:CargaInicial", SDL_GetError());
	}else{
		fondoZ2 = SDL_CreateTextureFromSurface(renderer, temp_surface);
		if(fondoZ2 == NULL){
			Logger::Log(NIVEL_LOGGER::ERROR, "FondoParallax:CargaInicial", SDL_GetError());
		}else{
			SDL_QueryTexture(fondoZ2, NULL, NULL, &w, &h);
				fh = (float) h;

				rectZ2_Hasta.w = anchoPantalla;
				rectZ2_Hasta.h = altoPantalla;
				rectZ2_Hasta.x = 0;
				rectZ2_Hasta.y = 20;

				rectZ2_Desde.h = h;
				rectZ2_Desde.w = roundf(
						(float) anchoPantalla * ((fh / (float) rectZ2_Hasta.h)));
				rectZ2_Desde.x = 0;
				rectZ2_Desde.y = 20;
				Logger::Log(NIVEL_LOGGER::INFO, "FondoParallax:CargaInicial",
									"Carga fondo Z2: OK");
		}
	}
	// Fondo Z1
	temp_surface = IMG_Load(FONDO_Z1);
	if(temp_surface == NULL){
		Logger::Log(NIVEL_LOGGER::ERROR, "FondoParallax:CargaInicial", SDL_GetError());
	}else{
		fondoZ1 = SDL_CreateTextureFromSurface(renderer, temp_surface);
		if(fondoZ1 == NULL){
			Logger::Log(NIVEL_LOGGER::ERROR, "FondoParallax:CargaInicial", SDL_GetError());
		}else{
			SDL_QueryTexture(fondoZ1, NULL, NULL, &w, &h);
			fh = (float) h;

			rectZ1_Hasta.w = anchoPantalla;
			rectZ1_Hasta.h = altoPantalla * 0.8;
			rectZ1_Hasta.x = 0;
			rectZ1_Hasta.y = 130;

			rectZ1_Desde.h = h;
			rectZ1_Desde.w = roundf(
					(float) anchoPantalla * ((fh / (float) rectZ1_Hasta.h)));
			rectZ1_Desde.x = 0;
			rectZ1_Desde.y = 0;
			Logger::Log(NIVEL_LOGGER::INFO, "FondoParallax:CargaInicial",
												"Carga fondo Z1: OK");
		}
	}
	SDL_FreeSurface(temp_surface);
}
