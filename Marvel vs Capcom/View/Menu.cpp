#include "Menu.h"

int PosicionesDemasJugadores;
 Menu::Menu() {

	ModeloSeleccionPersonaje personaje;
	ModeloSeleccion modelo;
	personaje.personajeId=P_VENOM;
	personaje.jugadorId=1;
	personaje.confirmado=false;
	ModeloSeleccionPersonaje personaje2;
	personaje2.personajeId=P_CHUNLI;
	personaje2.jugadorId=4;
	personaje2.confirmado=false;
	modelo.data.push_back(personaje);
	modelo.data.push_back(personaje2);

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
							{std::list<ModeloSeleccionPersonaje>::iterator it;
									for (it = modelo.data.begin(); it != modelo.data.end(); it++)  {
										if  (it->jugadorId==1){
											if (it->personajeId-1 > 0)
											it->personajeId--;
										}
									}}
							//necesito aumentar un contador para el seleccionado aca
							break;
						case SDLK_RIGHT:
							{std::list<ModeloSeleccionPersonaje>::iterator it;
							for (it = modelo.data.begin(); it != modelo.data.end(); it++)  {
								if  (it->jugadorId==1){
									if ((it->personajeId-1) < (modelo.data.size()-1))
									it->personajeId++;
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
