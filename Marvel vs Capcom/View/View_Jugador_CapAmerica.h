#ifndef VIEW_JUGADOR_CAPAMERICA_H_
#define VIEW_JUGADOR_CAPAMERICA_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"

class View_Jugador_CapAmerica: public View_Jugador {
public:
	View_Jugador_CapAmerica();
	void initialize(Jugador *model, LTexture * texturaJugador);

	void reproducir_sonido_salto();
	void reproducir_sonido_cambio();
	void reproducir_sonido_ataque_pu();
	void reproducir_sonido_defensa();
	EfectoSonido *sonido_salto;
	EfectoSonido *sonido_ataque_pu; // sonido ataque puño
	EfectoSonido *sonido_defensa;
	EfectoSonido *sonido_cambio;

protected:
	//variable que uso para ajusatr la animacion

	void getSpritesAnimacion();
	void getSpritesCaminar();
	void getSpritesSaltar();
	void getSpritesAgachar();
	void getSpritesCambioPersonaje();
	void getSpritesPatadaFuerte();
	void getSpritesPatadaDebil();
	void getSpritesPinaFuerte();
	void getSpritesPinaDebil();
	void getSpritesDefensa();
	void getSpritesPatadaFuerte_agachado();
	void getSpritesPatadaDebil_agachado();
	void getSpritesPinaFuerte_agachado();
	void getSpritesPinaDebil_agachado();
	void getSpritesDefensa_agachado();
	void getSpritesDefensaAgachado();
	void getSpritesDefensaSaltando();
	void getSpritesPatadaDebilSaltando();
	void getSpritesPatadaFuerteSaltando();
	void getSpritesPinaFuerteSaltando();
	void getSpritesPinaDebilSaltando();

};

#endif
