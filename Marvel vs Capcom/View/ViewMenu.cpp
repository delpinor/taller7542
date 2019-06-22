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

		this->sonido_cursor= new EfectoSonido(1);
		this->sonido_selection= new EfectoSonido(1);
		this->sonido_cursor->init();
		this->sonido_cursor->loadMedia("../Sonidos/selection.wav");
		this->sonido_selection->loadMedia("../Sonidos/selection_confirm.wav");


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
	texturaFondoLogin.loadFromFile("Images/fondologin.gif", gRenderer, 0,
			0);
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
		if (!gTextTexture.loadFromRenderedText(TextoTitulo,
				textColor, gRenderer, gFont2)) {
			printf("Failed to render text texture!\n");
			success = false;
		}

		if (!gTextTexture2.loadFromRenderedText(TextoMensaje,
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

	gTextTexture2.render(4, 250, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
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

}

void ViewMenu::handleEvent(bool *quit, int *personajeSelecionadoId,
		bool *confirmado) {
	actualizarTitulo("SELECCION DE PERSONAJE JUGADOR: " + std::to_string(this->nroJugadorLocal));
	actualizarMensaje("Elija personaje y presione la tecla ESPACIO");

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

				this->sonido_selection->reproducir_sonido();

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
				this->sonido_cursor->reproducir_sonido();
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
				this->sonido_cursor->reproducir_sonido();
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
	cout << "================================================================================"<< endl;
	for (int i = 0; i < unModelo.cantidadData; i++) {
		cout << "MODELOSELECCION " << endl;
		cout << "MODELOSELECCION se recibe confirmado: 		|" << modelo.data[i].confirmado << endl;
		cout << "MODELOSELECCION se recibe jugadorId: 		|" << modelo.data[i].jugadorId << endl;
		cout << "MODELOSELECCION se recibe personajeId: 	|" << modelo.data[i].personajeId << endl;
		cout << "MODELOSELECCION se recibe numeroJugador: 	|" << modelo.data[i].numeroJugador << endl;
		cout << "MODELOSELECCION se recibe equipo:			|" << modelo.data[i].equipo << endl;
		cout << "MODELOSELECCION se recibe cantidadData: 	|"  << modelo.cantidadData << endl;

		ModeloPersonajeVistaSeleccion unModeloPersonaje;
		unModeloPersonaje.confirmado = modelo.data[i].confirmado;
		unModeloPersonaje.jugadorId = modelo.data[i].jugadorId;
		unModeloPersonaje.personajeId = modelo.data[i].personajeId;
		unModeloPersonaje.numeroJugador = modelo.data[i].numeroJugador;
		unModeloPersonaje.equipo = modelo.data[i].equipo;

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

list<ModeloPersonajeVistaSeleccion> ViewMenu::getDataSeleccionada(){
	return this->modelo.data;
}


int ViewMenu::getNombre_usuario(std::string &nombre)
{
	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;
	//The current input text.
	std::string inputText = " ";
	SDL_Color textColor = { 250, 50, 50 };

	gInputTextTexture.loadFromRenderedText(inputText.c_str(), textColor,
			gRenderer, gFont);
	gPromptTextTexture.loadFromRenderedText("Ingrese Nombre: ", textColor, gRenderer,
			gFont);
	//Enable text input
	SDL_StartTextInput();
	//While application is running
	while ((!quit)) {
		//The rerender text flag
		bool renderText = false;

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit
			if (e.type == SDL_QUIT) {
				//quit = true;
			}

			//Special key input
			else if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_RETURN && inputText.length() > 0 && inputText != " ") {
					quit = true;
				}
				//Handle backspace
				if (e.key.keysym.sym == SDLK_BACKSPACE
						&& inputText.length() > 0) {
					//lop off character
					inputText.pop_back();
					renderText = true;
				}
				//Handle copy
				else if (e.key.keysym.sym
						== SDLK_c&& SDL_GetModState() & KMOD_CTRL) {
					SDL_SetClipboardText(inputText.c_str());
				}
				//Handle paste
				else if (e.key.keysym.sym
						== SDLK_v&& SDL_GetModState() & KMOD_CTRL) {
					inputText = SDL_GetClipboardText();
					renderText = true;
				}
			}
			//Special text input event
			else if (e.type == SDL_TEXTINPUT) {
				//Not copy or pasting
				if (!((e.text.text[0] == 'c' || e.text.text[0] == 'C')
						&& (e.text.text[0] == 'v' || e.text.text[0] == 'V')
						&& SDL_GetModState() & KMOD_CTRL)) {
					//Append character
					inputText += e.text.text;
					renderText = true;
				}
			}
		}

		//Rerender text if needed
		if (renderText) {
			//Text is not empty
			if (inputText != "") {
				//Render new text
				gInputTextTexture.loadFromRenderedText(inputText.c_str(),
						textColor, gRenderer, gFont);
			}
			//Text is empty
			else {
				//Render space texture
				gInputTextTexture.loadFromRenderedText(" ", textColor,
						gRenderer, gFont);
			}
		}

		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

		SDL_RenderClear(gRenderer);

		framealpha += (10);
		//fondo
		texturaFondoLogin.render(0, 0, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
		//logo
		texturaLogo.render(((SCREEN_WIDTH)/2)-150, ((SCREEN_HEIGHT)/2)-83, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
		//Render text textures
		gPromptTextTexture.render((SCREEN_WIDTH)/2 - gPromptTextTexture.getWidth()/2 , ((SCREEN_HEIGHT)/2)+ 130, NULL, 0.0, NULL, SDL_FLIP_NONE,
				gRenderer);
		gPromptTextTexture.setAlpha(framealpha);

		 textColor.r = 0;
		 textColor.g = 0;
		 textColor.b = 0;
		gInputTextTexture.render((SCREEN_WIDTH)/2 - gInputTextTexture.getWidth()/2, ((SCREEN_HEIGHT)/2)+ 130+ gPromptTextTexture.getHeight(), NULL, 0.0, NULL, SDL_FLIP_NONE,
				gRenderer);
		gInputTextTexture.setAlpha(framealpha*10);


		//Update screen
		SDL_RenderPresent(gRenderer);
	}

	//Disable text input
	SDL_StopTextInput();
	nombre = inputText;
	return  0;

}


void ViewMenu::actualizarTitulo(std::string texto) {
	SDL_Color textColor = { 250, 250, 250 };
	gTextTexture.loadFromRenderedText(texto,
				textColor, gRenderer, gFont2);
}

void ViewMenu::actualizarMensaje(std::string texto) {
	SDL_Color textColor = { 250, 250, 250 };
	gTextTexture2.loadFromRenderedText(texto,
				textColor, gRenderer, gFont2);
}
