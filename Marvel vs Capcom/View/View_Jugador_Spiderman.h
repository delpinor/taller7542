#ifndef VIEW_JUGADOR_SPIDERMAN_H_
#define VIEW_JUGADOR_SPIDERMAN_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"

class View_Jugador_Spiderman: public View_Jugador {
public:
	View_Jugador_Spiderman();
	void initialize(Jugador *model,
		LTexture * texturaJugador);

protected:
	void getSpritesAnimacion();
	void getSpritesCaminar();
	void getSpritesSaltar();
	void getSpritesAgachar();
	void getSpritesCambioPersonaje();

	void getSpritesPatadaDebil();
	void getSpritesPatadaDebilSaltando();
	void getSpritesPatadaDebilAgachado();


	void getSpritesPatadaFuerte();
	void getSpritesPatadaFuerteSaltando();
	void getSpritesPatadaFuerteAgachado();

	void getSpritesPiniaDebil();
	void getSpritesPiniaFuerte();

	void getSpritesPiniaDebilAgachado();
	void getSpritesPiniaFuerteAgachado();

	void getSpritesPiniaFuerteSaltando();
	void getSpritesPiniaDebilSaltando();

	void getSpritesDefensa();
	void getSpritesDefensaAgachado();
	void getSpritesDefensaSaltando();
	void getSpritesRecibirGolpe();

	void getSpritesLanzarJugador();
	void getSpritesJugadorLanzado();
	void getSpritesLanzarPoder();
	void getSpritesPoder();



};

#endif
