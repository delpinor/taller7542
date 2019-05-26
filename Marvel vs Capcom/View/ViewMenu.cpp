#include "ViewMenu.h"

ViewMenu::ViewMenu() {
	CantidadDeJugadores= 2;
	npersonaje=0;

	fondoclip.h = 460;
	fondoclip.w = 400;
	fondoclip.x = 0;
	fondoclip.y = 0;

	spidermanclip.h = 215;
	spidermanclip.w = 118;
	spidermanclip.x = 160;
	spidermanclip.y = 485;

	chunliclip.h = 215;
	chunliclip.w = 118;
	chunliclip.x = 170;
	chunliclip.y = 24;

	cajpitanclip.h = 215;
	cajpitanclip.w = 118;
	cajpitanclip.x = 295;
	cajpitanclip.y = 485;

	venomclip.h = 215;
	venomclip.w = 118;
	venomclip.x = 562;
	venomclip.y = 485;

}

ViewMenu::~ViewMenu() {
	// TODO Auto-generated destructor stub
}

bool ViewMenu::loadMedia() {

	texturaChunLi.loadFromFile("Images/personajes.png", gRenderer, 118, 215);
	texturaVenom.loadFromFile("Images/personajes.png", gRenderer, 118, 215);
	texturaSpiderman.loadFromFile("Images/personajes.png", gRenderer, 118, 215);
	texturaCapitan.loadFromFile("Images/personajes.png", gRenderer, 118, 215);

	texturaLogo.loadFromFile("Images/logo.gif", gRenderer, 118, 215);
	texturaMenuSelec.loadFromFile("Images/personajes.png", gRenderer, 118, 215);
	texturaJugadorSeleccionado.loadFromFile("Images/seleccion.png", gRenderer, 118,215);
	texturaJugadorClienteSeleccionado.loadFromFile("Images/seleccion.png", gRenderer, 118,215);
	texturaFondo.loadFromFile("Images/fondoc.png", gRenderer, SCREEN_WIDTH,SCREEN_HEIGHT);
	return true;

}

bool ViewMenu::loadText()
{
    //Loading success flag
    bool success = true;

    //Open the font

    gFont = TTF_OpenFont( "Images/OpenSans-Bold.ttf", 35 );
    if( gFont == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    gFont2 = TTF_OpenFont( "Images/OpenSans-Bold.ttf", 20 );
      if( gFont == NULL )
      {
          printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
          success = false;
      }
    else
    {
        //Render text
        SDL_Color textColor = { 250, 250, 250 };
        if( !gTextTexture.loadFromRenderedText( "SELECCION DE PERSONAJES", textColor ,gRenderer,gFont2) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
        if( !gTextTexture2.loadFromRenderedText( "Presione Enter para Confirmar", textColor ,gRenderer,gFont2) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
        if( !texturaTextoSeleccionado.loadFromRenderedText( "1P", textColor ,gRenderer,gFont) )
              {
                  printf( "Failed to render text texture!\n" );
                  success = false;
              }
        if( !texturaTextoSeleccionadoCliente.loadFromRenderedText( "2P", textColor ,gRenderer,gFont) )
                {
                    printf( "Failed to render text texture!\n" );
                    success = false;
                }
    }

    return success;
}



void ViewMenu::render() {

	SDL_RenderClear(gRenderer);
	//fondo
	texturaFondo.render(0, 0, &fondoclip, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	//logo
	texturaLogo.render(300, 300, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	//personajes
	for (int i = 0; i <= CantidadDeJugadores-1; ++i) { //recorro la lista que recibo
		if (i/*posvec(i).nombre*/ == P_SPIDERMAN-1)
			texturaSpiderman.render((i) * ANCHO_CUADRO,
					ALTO_CUADRO, &spidermanclip, 0.0, NULL, SDL_FLIP_NONE,
					gRenderer);
		if (i == P_CHUN_LI-1)
			texturaChunLi.render((i) * ANCHO_CUADRO, ALTO_CUADRO,
					&chunliclip, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
		if (i == P_CAPITAN_AMERICA-1)
			texturaCapitan.render((i) * ANCHO_CUADRO,
					ALTO_CUADRO, &cajpitanclip, 0.0, NULL, SDL_FLIP_NONE,
					gRenderer);
		if (i == P_VENOM-1)
			texturaVenom.render((i) * ANCHO_CUADRO, ALTO_CUADRO,
					&venomclip, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	}
	//titulo
	gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, 4 ,NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	//mensaje de seleccion
	gTextTexture2.render( 4, 250 ,NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	//cuadro de jugador seleccionado y texto
	framealpha+=30;
	if (( framealpha/ 100 >= 100)) framealpha = 0;
	texturaJugadorSeleccionado.setAlpha(framealpha);
	texturaJugadorSeleccionado.setColor(200,200,20);
	texturaTextoSeleccionado.render((npersonaje*ANCHO_CUADRO)+15, 200, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	texturaJugadorSeleccionado.render(npersonaje*ANCHO_CUADRO, ALTO_CUADRO, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	//cuadro de jugador seleccionado y texto de los clientes (tengo que hacer que recorra el vector de posiciones de clientes clientes
	texturaJugadorClienteSeleccionado.setAlpha(framealpha);
	texturaJugadorClienteSeleccionado.setColor(100,100,100);
	texturaJugadorClienteSeleccionado.render(0, ALTO_CUADRO, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);//reemplazar 0 por posiciones de otros jugadores

	SDL_RenderPresent(gRenderer);
}

bool ViewMenu::inicializar() {

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
				   if( TTF_Init() == -1 )
				                {
				                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
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

void ViewMenu::personajeSiguiente() {
	if (npersonaje < (CantidadDeJugadores-1))
		npersonaje+=1;
}

void ViewMenu::personajeAnterior() {
	if (npersonaje >0)
		npersonaje-=1;
}


