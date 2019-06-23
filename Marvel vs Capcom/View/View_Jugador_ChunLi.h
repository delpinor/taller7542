#ifndef VIEW_JUGADOR_CHUNLI_H_
#define VIEW_JUGADOR_CHUNLI_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"

class View_Jugador_ChunLi: public View_Jugador {
public:
	View_Jugador_ChunLi();
	void initialize(Jugador *model, LTexture * texturaJugador);

protected:
	//variable que uso para ajusatr la animacion

	void getSpritesAnimacion();
	void getSpritesCaminar();
	void getSpritesSaltar();
	void getSpritesAgachar();
	void getSpritesCambioPersonaje();
	void getSpritesPatadaFuerte();
	void getSpritesPatadaDebil();
	void getSpritesPatadaDebilSaltando();
	void getSpritesPatadaFuerteSaltando();
	void getSpritesPatadaDebilAgachado();
	void getSpritesPatadaFuerteAgachado();
	void getSpritesPiniaDebil();

};

#endif
