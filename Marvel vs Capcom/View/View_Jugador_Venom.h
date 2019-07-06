#ifndef VIEW_JUGADOR_VENOM_H_
#define VIEW_JUGADOR_VENOM_H_
#include <SDL2/SDL.h>
#include "../View/View_Jugador.h"

class View_Jugador_Venom: public View_Jugador {
public:
	View_Jugador_Venom();
	void initialize(Jugador * model,
		LTexture * texturaJugador);




	void reproducir_sonido_salto();
	void reproducir_sonido_cambio();
	void reproducir_sonido_ataque_pu();
	void reproducir_sonido_defensa();
	void reproducir_sonido_ataque_patada();
	void reproducir_sonido_recibir_danio();
	void reproducir_sonido_poder();
		void reproducir_sonido_agarre();

		EfectoSonido *sonido_poder;
		EfectoSonido *sonido_agarre;


	EfectoSonido *sonido_danio;
	EfectoSonido *sonido_ataque_patada;
	EfectoSonido *sonido_salto;
	EfectoSonido *sonido_ataque_pu; // sonido ataque puño
	EfectoSonido *sonido_defensa;
	EfectoSonido *sonido_cambio;

protected:

	void getSpritesAnimacion();
	void getSpritesCaminar();
	void getSpritesSaltar();
	void getSpritesAgachar();
	void getSpritesCambioPersonaje();
	//Parado
	void getSpritesPiniaDebil();
	void getSpritesPiniaFuerte();
	void getSpritesPatadaDebil();
	void getSpritesPatadaFuerte();
	void getSpritesDefensa();
	//Agachado
	void getSpritesPiniaDebilAgachado();
	void getSpritesPiniaFuerteAgachado();
	void getSpritesPatadaDebilAgachado();
	void getSpritesPatadaFuerteAgachado();
	void getSpritesDefensaAgachado();
	//Saltando
	void getSpritesPiniaDebilSaltando();
	void getSpritesPiniaFuerteSaltando();
	void getSpritesPatadaDebilSaltando();
	void getSpritesPatadaFuerteSaltando();
	void getSpritesDefensaSaltando();
	//Daño
	void getSpritesRecibirDanio();
	//Poder
	void getSpritesPoder();
	void getSpritesLanzarPoder();
	//Volando
	void getSpritesVolando();
	//Lanzar
	//void getSpritesArrojando();
	void getSpritesLanzarJugador();
	//Tomado
	void getSpritesTomado();

};

#endif
