#include "Menu.h"

int PosicionesDemasJugadores;
 Menu::Menu() {

	ModeloSeleccionPersonaje personaje;
	ModeloSeleccion modelo;
	personaje.personajeId=P_CHUNLI;
	personaje.jugadorId=1;
	personaje.confirmado=false;
	modelo.data.push_back(personaje);
	modelo.data.push_back(personaje);
	modelo.data.push_back(personaje);
	modelo.data.push_back(personaje);
	ViewMenu view(&modelo);
///esto me tiene que llegar del server
	//	ViewMenu view(CantidadDeJugadores);
	if (!view.inicializar()) {
		printf("Failed to initialize!\n");
	} else {
		//Load media
		if (!view.loadMedia() || !view.loadText()) {
			printf("Failed to load media!\n");
		} else {
			//Main loop flag
			bool quit = false;///reemplazar quit por la seleccion de un jugador

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit) {
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0) {
					//User requests quit
					if (e.type == SDL_QUIT) {
						quit = true;
					}
					//User presses a key
					else if (e.type == SDL_KEYDOWN) {
						//Select surfaces based on key press
						switch (e.key.keysym.sym) {
						case SDLK_RETURN:
							quit = true;
							break;

						case SDLK_LEFT:
							view.personajeAnterior();

							//necesito aumentar un contador para el seleccionado aca
							break;
						case SDLK_RIGHT:
							view.personajeSiguiente();
							//necesito disminuir un contador para el seleccionado aca
							break;

						default:
							//	0 =  P_NAP ; // no se si hace falta mandarle al server que no paso nada...
							break;
						}
					}
				}
				//aca le mando al server la posicion actual de este cliente
				PosicionesDemasJugadores;//=server.getposiciones(); aca guardo las posiciones de los otros jugadores que recibo del server
				//view.setPosiciones(PosicionesDemasJugadores);
				view.render();

			}
			//aca pongo el mensaje al servidor para que  guarde el seleccionado en el server
			//server.finSeleccion();
		}
	}

	//Free resources and close SDL
	view.close();
}
