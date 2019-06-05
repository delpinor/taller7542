#include "ViewMenu.h"
ViewMenu::ViewMenu(int i) {

	//npersonaje = 0;
	if (!this->inicializar()) {
		printf("ViewMenu: Failed to initialize!\n");
	} else {
		//Load media
		if (!this->loadMedia() || !this->loadText()) {
			printf("Failed to load media!\n");
		} else {

		}
	}
}

ViewMenu::~ViewMenu() {
	// TODO Auto-generated destructor stub
}

bool ViewMenu::loadMedia() {

	texturaChunLi.loadFromFile("Images/personajes.png", gRenderer,
			ANCHO_CUADRO_JUGADOR, ALTO_CUADRO_JUGADOR);
	texturaVenom.loadFromFile("Images/personajes.png", gRenderer,
			ANCHO_CUADRO_JUGADOR, ALTO_CUADRO_JUGADOR);
	texturaSpiderman.loadFromFile("Images/personajes.png", gRenderer,
			ANCHO_CUADRO_JUGADOR, ALTO_CUADRO_JUGADOR);
	texturaCapitan.loadFromFile("Images/personajes.png", gRenderer,
			ANCHO_CUADRO_JUGADOR, ALTO_CUADRO_JUGADOR);

	texturaLogo.loadFromFile("Images/logo.gif", gRenderer, ANCHO_CUADRO_JUGADOR,
			ALTO_CUADRO_JUGADOR);
	texturaMenuSelec.loadFromFile("Images/personajes.png", gRenderer,
			ANCHO_CUADRO_JUGADOR, ALTO_CUADRO_JUGADOR);

	texturaJugadorClienteSeleccionado1.loadFromFile("Images/seleccion.png",
			gRenderer, ANCHO_CUADRO_JUGADOR, ALTO_CUADRO_JUGADOR);
	texturaJugadorClienteSeleccionado2.loadFromFile("Images/seleccion.png",
			gRenderer, ANCHO_CUADRO_JUGADOR, ALTO_CUADRO_JUGADOR);
	texturaJugadorClienteSeleccionado3.loadFromFile("Images/seleccion.png",
			gRenderer, ANCHO_CUADRO_JUGADOR, ALTO_CUADRO_JUGADOR);
	texturaJugadorClienteSeleccionado4.loadFromFile("Images/seleccion.png",
			gRenderer, ANCHO_CUADRO_JUGADOR, ALTO_CUADRO_JUGADOR);
	texturaFondo.loadFromFile("Images/fondoc.png", gRenderer, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	return true;

}

bool ViewMenu::loadText() {
	//Loading success flag
	bool success = true;

	//Open the font

	gFont = TTF_OpenFont("Images/OpenSans-Bold.ttf", 35);
	if (gFont == NULL) {
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	gFont2 = TTF_OpenFont("Images/OpenSans-Bold.ttf", 20);
	if (gFont == NULL) {
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	} else {
		//Render text
		SDL_Color textColor = { 250, 250, 250 };
		if (!gTextTexture.loadFromRenderedText("SELECCION DE PERSONAJES",
				textColor, gRenderer, gFont2)) {
			printf("Failed to render text texture!\n");
			success = false;
		}

		if (!gTextTexture2.loadFromRenderedText("Presione ESPACIO para Confirmar",
				textColor, gRenderer, gFont2)) {
			printf("Failed to render text texture!\n");
			success = false;
		}
		SDL_Color textColor1 = { 250, 250, 250 };
		if (!texturaTextoSeleccionadoCliente1.loadFromRenderedText("1P",
				textColor, gRenderer, gFont)) {
			printf("Failed to render text texture!\n");
			success = false;
		}
		SDL_Color textColor2 = { 250, 250, 0 };
		if (!texturaTextoSeleccionadoCliente2.loadFromRenderedText("2P",
				textColor2, gRenderer, gFont)) {
			printf("Failed to render text texture!\n");
			success = false;
		}
		SDL_Color textColor3 = { 250, 0, 250 };
		if (!texturaTextoSeleccionadoCliente3.loadFromRenderedText("3P",
				textColor3, gRenderer, gFont)) {
			printf("Failed to render text texture!\n");
			success = false;
		}
		SDL_Color textColor4 = { 0, 250, 250 };
		if (!texturaTextoSeleccionadoCliente4.loadFromRenderedText("4P",
				textColor4, gRenderer, gFont)) {
			printf("Failed to render text texture!\n");
			success = false;
		}
	}

	return success;
}

void ViewMenu::render() {
	SDL_RenderClear(gRenderer);
	CantidadDeJugadores = modelo.cantidadData;
	//fondo
	texturaFondo.render(0, 0, &fondoclip, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	//logo
	texturaLogo.render(300, 300, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	//personajes
	int i = 0;
	std::list<int>::iterator itpersonajes;

	//cout << "VIEWMENU - render: | " << " | " << TimeHelper::getStringLocalTimeNow() << endl;
	//cout << "VIEWMENU - render: Cantidad de personajes  " << this->personajes.size()  << " | " << TimeHelper::getStringLocalTimeNow() << endl;

	for (itpersonajes = this->personajes.begin();
			itpersonajes != this->personajes.end(); itpersonajes++) { //recorro la lista que recibo
		//cout << "VIEWMENU - render: Personaje | "<< *itpersonajes << " | " << TimeHelper::getStringLocalTimeNow() << endl;
		if (*itpersonajes == P_SPIDERMAN)
			texturaSpiderman.render(
					((P_SPIDERMAN - 1) * ANCHO_CUADRO_JUGADOR) + POS_CUADROX,
					POS_CUADROY, &spidermanclip, 0.0, NULL, SDL_FLIP_NONE,
					gRenderer); //tengo que hacer un map del personaje al i para usar abajo
		if (*itpersonajes == P_CHUNLI)
			texturaChunLi.render(
					((P_CHUNLI - 1) * ANCHO_CUADRO_JUGADOR) + POS_CUADROX,
					POS_CUADROY, &chunliclip, 0.0, NULL, SDL_FLIP_NONE,
					gRenderer);
		if (*itpersonajes == P_CAPITAN_AMERICA)
			texturaCapitan.render(
					((P_CAPITAN_AMERICA - 1) * ANCHO_CUADRO_JUGADOR)
							+ POS_CUADROX, POS_CUADROY, &cajpitanclip, 0.0,
					NULL, SDL_FLIP_NONE, gRenderer);
		if (*itpersonajes == P_VENOM)
			texturaVenom.render(
					((P_VENOM - 1) * ANCHO_CUADRO_JUGADOR) + POS_CUADROX,
					POS_CUADROY, &venomclip, 0.0, NULL, SDL_FLIP_NONE,
					gRenderer);
		i++;
	}
	//titulo
	gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 4, NULL,
			0.0, NULL, SDL_FLIP_NONE, gRenderer);
	//mensaje de seleccion
	gTextTexture2.render(4, 250, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);

	framealpha += (25);

	texturaJugadorClienteSeleccionado1.setAlpha(framealpha);
	texturaJugadorClienteSeleccionado1.setColor(250, 250, 250);
	texturaJugadorClienteSeleccionado2.setAlpha(framealpha + 30);
	texturaJugadorClienteSeleccionado2.setColor(250, 250, 0);
	texturaJugadorClienteSeleccionado3.setAlpha(framealpha + 60);
	texturaJugadorClienteSeleccionado3.setColor(250, 0, 250);
	texturaJugadorClienteSeleccionado4.setAlpha(framealpha + 90);
	texturaJugadorClienteSeleccionado4.setColor(0, 250, 250);
	std::list<ModeloPersonajeVistaSeleccion>::iterator it;
	for (it = modelo.data.begin(); it != modelo.data.end(); it++) { //recorro la lista que recibo
		if (it->jugadorId == 1) {
			if (it->confirmado)
				texturaJugadorClienteSeleccionado1.setAlpha(100);
			texturaTextoSeleccionadoCliente1.render(
					((it->personajeId - 1) * ANCHO_CUADRO_JUGADOR) + 20,
					POS_CUADROY, NULL, 0.0,
					NULL, SDL_FLIP_NONE, gRenderer); //it->personajeId-1 reempazo con map(it->personajeId)
			texturaJugadorClienteSeleccionado1.render(
					((it->personajeId - 1) * ANCHO_CUADRO_JUGADOR)
							+ POS_CUADROX, POS_CUADROY,
					NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
		}
		if (it->jugadorId == 2) {
			if (it->confirmado)
				texturaJugadorClienteSeleccionado2.setAlpha(100);
			texturaTextoSeleccionadoCliente2.render(
					((it->personajeId - 1) * ANCHO_CUADRO_JUGADOR) + 20,
					POS_CUADROY + 26, NULL, 0.0,
					NULL, SDL_FLIP_NONE, gRenderer);
			texturaJugadorClienteSeleccionado2.render(
					((it->personajeId - 1) * ANCHO_CUADRO_JUGADOR)
							+ POS_CUADROX, POS_CUADROY,
					NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
		}
		if (it->jugadorId == 3) {
			if (it->confirmado)
				texturaJugadorClienteSeleccionado3.setAlpha(100);
			texturaTextoSeleccionadoCliente3.render(
					((it->personajeId - 1) * ANCHO_CUADRO_JUGADOR) + 20,
					POS_CUADROY + 52, NULL, 0.0,
					NULL, SDL_FLIP_NONE, gRenderer);
			texturaJugadorClienteSeleccionado3.render(
					((it->personajeId - 1) * ANCHO_CUADRO_JUGADOR)
							+ POS_CUADROX, POS_CUADROY,
					NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
		}
		if (it->jugadorId == 4) {
			if (it->confirmado)
				texturaJugadorClienteSeleccionado4.setAlpha(100);
			texturaTextoSeleccionadoCliente4.render(
					((it->personajeId - 1) * ANCHO_CUADRO_JUGADOR) + 20,
					POS_CUADROY + 78, NULL, 0.0,
					NULL, SDL_FLIP_NONE, gRenderer);
			texturaJugadorClienteSeleccionado4.render(
					((it->personajeId - 1) * ANCHO_CUADRO_JUGADOR)
							+ POS_CUADROX, POS_CUADROY,
					NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
		}
	}

	SDL_RenderPresent(gRenderer);
}

void ViewMenu::inicializarClips() {
	fondoclip.h = 460;
	fondoclip.w = 400;
	fondoclip.x = 0;
	fondoclip.y = 0;

	spidermanclip.h = ALTO_CUADRO_JUGADOR;
	spidermanclip.w = ANCHO_CUADRO_JUGADOR;
	spidermanclip.x = 160;
	spidermanclip.y = 485;

	chunliclip.h = ALTO_CUADRO_JUGADOR;
	chunliclip.w = ANCHO_CUADRO_JUGADOR;
	chunliclip.x = 170;
	chunliclip.y = 24;

	cajpitanclip.h = ALTO_CUADRO_JUGADOR;
	cajpitanclip.w = ANCHO_CUADRO_JUGADOR;
	cajpitanclip.x = 295;
	cajpitanclip.y = 485;

	venomclip.h = ALTO_CUADRO_JUGADOR;
	venomclip.w = ANCHO_CUADRO_JUGADOR;
	venomclip.x = 562;
	venomclip.y = 485;
}

bool ViewMenu::inicializar() {

	this->inicializarClips();
	bool exito = true;

	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		exito = false;
	} else {
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			SDL_GetError();

		}

		//Create window
		window = SDL_CreateWindow("Taller de Programacion - Marvel vs Capcom",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
				SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			SDL_GetError();
			exito = false;
		} else {
			//Create vsynced renderer for this->window
			gRenderer = SDL_CreateRenderer(window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL) {
				SDL_GetError();
				exito = false;
			} else {

				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {

					SDL_GetError();
					exito = false;
				}
				if (TTF_Init() == -1) {
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n",
					TTF_GetError());
					exito = false;
				}
			}
		}
	}

	return exito;
}

void ViewMenu::close() {
	//Deallocate surfaces
	//	for (int i = 0; i < 5; ++i) {
	//		SDL_FreeSurface(gKeyPressSurfaces[i]);
	//		gKeyPressSurfaces[i] = NULL;
	//	}

	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}

void ViewMenu::handleEvent(bool *quit, int *personajeSelecionadoId,
		bool *confirmado) {

	//cout << "VIEWMENU - handleEvent: Jugador | "<< this->nroJugadorLocal << " | " << TimeHelper::getStringLocalTimeNow() << endl;

	while (SDL_PollEvent(&this->e) != 0) {
		//User requests quit
		if (this->e.type == SDL_QUIT) {
			*quit = true;
		}
		//User presses a key


		if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
			switch (e.key.keysym.sym) {
			case SDLK_SPACE:{

				std::list<ModeloPersonajeVistaSeleccion>::iterator it;
				for (it = modelo.data.begin(); it != modelo.data.end(); it++) {
					if ((it->jugadorId == this->nroJugadorLocal)&& (!it->confirmado)) {
						cout << "Confirmo!!!!!!!: " << this->nroJugadorLocal<<  endl;
						*personajeSelecionadoId = it->personajeId;
						*confirmado = true;
						break;

					}

				}
				break;
			}
			case SDLK_a: {
				std::list<ModeloPersonajeVistaSeleccion>::iterator it;
				for (it = modelo.data.begin(); it != modelo.data.end(); it++) {

					if ((it->jugadorId == this->nroJugadorLocal)
							&& (!it->confirmado)) {
						if (it->personajeId - 1 > 0) {
							//it->personajeId--;
							*personajeSelecionadoId = it->personajeId - 1;
							cout << "VIEWMENU: Jugador Personaje | "
									<< it->personajeId
									<< TimeHelper::getStringLocalTimeNow()
									<< endl;
							cout << "VIEWMENU: personajeSeleccionadoId | "
									<< *personajeSelecionadoId
									<< TimeHelper::getStringLocalTimeNow()
									<< endl;
						}
					}

				}
			}
				//necesito aumentar un contador para el seleccionado aca
				break;
			case SDLK_d: {
				std::list<ModeloPersonajeVistaSeleccion>::iterator it;
				for (it = modelo.data.begin(); it != modelo.data.end(); it++) {

					if ((it->jugadorId == this->nroJugadorLocal)
							&& (!it->confirmado)) {
						if ((it->personajeId - 1)
								< (this->personajes.size() - 1)) {//(this->modelo.data.size() - 1)){
							//it->personajeId++;
							*personajeSelecionadoId = it->personajeId + 1;
						}
					}
				}
			}
				//necesito disminuir un contador para el seleccionado aca
				break;

			default:
				//	0 =  P_NAP ; // no se si hace falta mandarle al server que no paso nada...
				break;
			}
		}
	}
}

void ViewMenu::setModeloSeleccion(ModeloSeleccion modelo) {
	//cout << "Entró en setModeloSeleccion | "<< TimeHelper::getStringLocalTimeNow() << endl;

	ModeloVistaSeleccion unModelo;
	unModelo.cantidadData = modelo.cantidadData;
	unModelo.seleccionFinalizada = modelo.seleccionFinalizada;

	//cout << "Entró en setModeloSeleccion | CantidadData "<< modelo.cantidadData << " | " << TimeHelper::getStringLocalTimeNow() << endl;

	for (int i = 0; i < unModelo.cantidadData; i++) {

		ModeloPersonajeVistaSeleccion unModeloPersonaje;
		unModeloPersonaje.confirmado = modelo.data[i].confirmado;
		unModeloPersonaje.jugadorId = modelo.data[i].jugadorId;
		unModeloPersonaje.personajeId = modelo.data[i].personajeId;

		unModelo.data.push_back(unModeloPersonaje);
	}

	this->modelo = unModelo;
}

void ViewMenu::setPersonajes(ModeloPersonajes *personajes) {

	int idPersonajeNoValido = static_cast<int>(PERSONAJE::P_NA);

	for (int i = 0; i < personajes->cantidadPersonajes; i++) {
		if (personajes->idsPersonajes[i] != idPersonajeNoValido) {
			this->personajes.push_back(personajes->idsPersonajes[i]);
		}
	}
}

bool ViewMenu::hayPersonajes() {
	if (this->personajes.size() > 0) {
		return true;
	} else {
		return false;
	}
}

void ViewMenu::setNroJugadorLocal(int valor) {
	this->nroJugadorLocal = valor;
}
