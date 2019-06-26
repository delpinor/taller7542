#include "FondoParallax.h"
#include "../Logger/Logger.h"
FondoParallax::FondoParallax(SDL_Window * ventana, SDL_Renderer * renderer,  std::string rutaZ1, std::string rutaZ2, std::string rutaZ3) {
	this->ventana = ventana;
	this->renderer = renderer;
	fondoZ1 = NULL;
	fondoZ2 = NULL;
	fondoZ3 = NULL;
	temp_surface = NULL;
	SDL_GetWindowSize(ventana, &anchoPantalla, &altoPantalla);

	cargaInicial(rutaZ1, rutaZ2, rutaZ3);
}

FondoParallax::~FondoParallax() {
	SDL_DestroyTexture(fondoZ1);
	SDL_DestroyTexture(fondoZ2);
	SDL_DestroyTexture(fondoZ3);
//	SDL_Quit();

}
// Mueve los fondos de acuerdo a la posicion de la camara.
void FondoParallax::refrescarPosicion(SDL_Rect * cam) {
	SDL_RenderClear(renderer);
	if (cam->x > pos_x_anterior) {
		moverDerecha(1);
		Logger::Log(LOGGER_NIVEL::DEBUG, "Parallax:Refrescar", "CámaraPosX:"+ std::to_string(cam->x));
	}
	if (cam->x < pos_x_anterior) {
		moverIzquierda(1);
		Logger::Log(LOGGER_NIVEL::DEBUG, "Parallax:Refrescar", "CámaraPosX:"+ std::to_string(cam->x));
	}
	pos_x_anterior = cam->x;
}
void FondoParallax::render(int fondoId){
	if(PantallaFija){
		SDL_Rect pos;
		pos.w = 1204;
		pos.h = 768;
		pos.x = 0;
		pos.y = 0;
		SDL_RenderCopy(renderer, fondoZ3, &pos, &pos);
	}else{
	if(fondoId == 1){
		SDL_RenderCopy(renderer, fondoZ1, &rectZ1_Desde, &rectZ1_Hasta);
	}
	if(fondoId == 2){
		SDL_RenderCopy(renderer, fondoZ2, &rectZ2_Desde, &rectZ2_Hasta);
	}
	if(fondoId == 3){
		SDL_RenderCopy(renderer, fondoZ3, &rectZ3_Desde, &rectZ3_Hasta);
	}

	}
}

// Mover fondo a derecha * multiplicador de velocidad
void FondoParallax::moverDerecha(int velocidad) {
	if ((rectZ1_Desde.x + rectZ1_Desde.w) < anchoPantallaZ1) {
		rectZ3_Desde.x += 1 * velocidad;
		rectZ2_Desde.x += 2 * velocidad;
		rectZ1_Desde.x += 3 * velocidad;
	}

}
// Mover fondo a Izquierda * multiplicador de velocidad
void FondoParallax::moverIzquierda(int velocidad) {
	if (rectZ1_Desde.x > 0) {
		rectZ3_Desde.x -= 1 * velocidad;
		rectZ2_Desde.x -= 2 * velocidad;
		rectZ1_Desde.x -= 3 * velocidad;
	}
}
// Carga los fondos z1, z2 y z3
void FondoParallax::cargaInicial( std::string rutaZ1, std::string rutaZ2, std::string rutaZ3) {
	int w, h;
	float fh;

	// fondo Z3
	temp_surface = IMG_Load(rutaZ3.c_str());
	if (temp_surface == NULL) {
		Logger::Log(LOGGER_NIVEL::ERROR, "FondoParallax:CargaInicial", SDL_GetError());
	} else {
		fondoZ3 = SDL_CreateTextureFromSurface(renderer, temp_surface);
		if (fondoZ3 == NULL) {
			Logger::Log(LOGGER_NIVEL::ERROR, "FondoParallax:CargaInicial",
					SDL_GetError());
		} else {
			SDL_QueryTexture(fondoZ3, NULL, NULL, &w, &h);
			fh = (float) h;

			rectZ3_Hasta.w = anchoPantalla;
			rectZ3_Hasta.h = altoPantalla*((altoPantalla/temp_surface->h) + 0.2);

			rectZ3_Hasta.x = 0;
			rectZ3_Hasta.y = -50;

			rectZ3_Desde.w = roundf((float) anchoPantalla * ((fh / (float) rectZ3_Hasta.h)));
			rectZ3_Desde.h = h;
			rectZ3_Desde.x = 20;
			rectZ3_Desde.y = 0;
			Logger::Log(LOGGER_NIVEL::INFO, "FondoParallax:CargaInicial",
					"Carga fondo Z3: OK");
		}
	}
	// Fondo Z2
	temp_surface = IMG_Load(rutaZ2.c_str());
	if(temp_surface==NULL){
		Logger::Log(LOGGER_NIVEL::ERROR, "FondoParallax:CargaInicial", SDL_GetError());
	}else{
		fondoZ2 = SDL_CreateTextureFromSurface(renderer, temp_surface);
		if(fondoZ2 == NULL){
			Logger::Log(LOGGER_NIVEL::ERROR, "FondoParallax:CargaInicial", SDL_GetError());
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
				rectZ2_Desde.y = 0;
				Logger::Log(LOGGER_NIVEL::INFO, "FondoParallax:CargaInicial",
									"Carga fondo Z2: OK");
		}
	}
	// Fondo Z1
	temp_surface = IMG_Load(rutaZ1.c_str());
	if(temp_surface == NULL){
		Logger::Log(LOGGER_NIVEL::ERROR, "FondoParallax:CargaInicial", SDL_GetError());
	}else{
		// Seteo ancho de la imagen Z1
		anchoPantallaZ1 = temp_surface->w;
		fondoZ1 = SDL_CreateTextureFromSurface(renderer, temp_surface);
		if(fondoZ1 == NULL){
			Logger::Log(LOGGER_NIVEL::ERROR, "FondoParallax:CargaInicial", SDL_GetError());
		}else{
			SDL_QueryTexture(fondoZ1, NULL, NULL, &w, &h);
			fh = (float) h;

			rectZ1_Hasta.w = anchoPantalla;
			rectZ1_Hasta.h = altoPantalla * 0.9;
			rectZ1_Hasta.x = 0;
			rectZ1_Hasta.y = 100;

			rectZ1_Desde.h = h;
			rectZ1_Desde.w = roundf((float) anchoPantalla * ((fh / (float) rectZ1_Hasta.h)));
			rectZ1_Desde.x = 0;
			rectZ1_Desde.y = 0;
			Logger::Log(LOGGER_NIVEL::INFO, "FondoParallax:CargaInicial",
												"Carga fondo Z1: OK");
		}
	}
	SDL_FreeSurface(temp_surface);
}
