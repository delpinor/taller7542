#ifndef VIEW_JUGADOR_H_
#define VIEW_JUGADOR_H_
#include <SDL2/SDL.h>
#include "../Model/LTexture.h"
#include "../Model/Model_Jugador.h"
#include "../Logger/Logger.h"
#include "../EfectoSonido.h"
class View_Jugador { // @suppress("Class has a virtual method and non-virtual destructor")
public:

	View_Jugador(Jugador *model);
	View_Jugador();
	virtual void initialize(Jugador *model, LTexture * texturaJugador);
	void grisar_imagen();
	void desgrisar_imagen();
	void render(int camX, int camY, SDL_Renderer * gRenderer);
	Jugador *jugador;
	int getZIndex();
	SDL_Rect * gSpriteCaminar;
	SDL_Rect * gSpriteCambiarPersonaje;
	SDL_Rect  *gSpriteSaltar;
	SDL_Rect  *gSpriteAgachar;
	SDL_Rect  *gSpriteGolpear;
	SDL_Rect  *gSpriteAnimacion;
	SDL_Rect  *gSpritePatadadon;
	SDL_Rect  *gSpritePatadadebil;
	SDL_Rect  *gSpritePinaFuerte;
	SDL_Rect  *gSpritePinaDebil;
	SDL_Rect  *gSpriteDefensa;

	SDL_Rect  *gSpritePatadadon_agachado;
	SDL_Rect  *gSpritePatadadebil_agachado;
	SDL_Rect  *gSpritePinaFuerte_agachado;
	SDL_Rect  *gSpritePinaDebil_agachado;
	SDL_Rect  *gSpriteDefensa_agachado;

	SDL_Rect  *gSpritePatadadon_saltando;
	SDL_Rect  *gSpritePatadadebil_saltando;
	SDL_Rect  *gSpritePinaFuerte_saltando;
	SDL_Rect  *gSpritePinaDebil_saltando;
	SDL_Rect  *gSpriteDefensa_saltando;

	SDL_Rect * gSprite;
	int contador = 0;

	int CANTSPRITECLIP;
	int CANTSPRITECLIPCAMINA;
	int MINFRAMECAMINA;
	int MAXFRAMECAMINA;
	int CANTSPRITECLIPSALTA;
	int MINFRAMESALTA;
	int MAXFRAMESALTA;
	int CANTSPRITEANIMACION;
	int MINFRAMEANIMACION;
	int MAXFRAMEANIMACION;
	int CANTSPRITECLIPPATADON;
	int CANTSPRITECLIPPATADITA;
	int CANTSPRITEPINADEBIL;
	int CANTSPRITEPINAFUERTE;
	int CANTSPRITEDEFENSA;

	int CANTSPRITECLIPPATADON_agachado;
	int CANTSPRITECLIPPATADITA_agachado;
	int CANTSPRITEPINADEBIL_agachado;
	int CANTSPRITEPINAFUERTE_agachado;
	int CANTSPRITEDEFENSA_agachado;

	int CANTSPRITECLIPPATADON_saltando;
	int CANTSPRITECLIPPATADITA_saltando;
	int CANTSPRITEPINADEBIL_saltando;
	int CANTSPRITEPINAFUERTE_saltando;
	int CANTSPRITEDEFENSA_saltando;


	int MINFRAMEPATADON;
	int MAXFRAMEPATADON;
	int MINFRAMEPATADITA;
	int MAXFRAMEPATADITA;
	int MINFRAMEPINADEBIL;
	int MAXFRAMEPINADEBIL;
	int MINFRAMEPINAFUERTE;
	int MAXFRAMEPINAFUERTE;
	int MAXFRAMEDEFENSA;


	int MINFRAMEPATADON_agachado;
	int MAXFRAMEPATADON_agachado;
	int MINFRAMEPATADITA_agachado;
	int MAXFRAMEPATADITA_agachado;
	int MINFRAMEPINADEBIL_agachado;
	int MAXFRAMEPINADEBIL_agachado;
	int MINFRAMEPINAFUERTE_agachado;
	int MAXFRAMEPINAFUERTE_agachado;
	int MINFRAMEDEFENSA_agachado;
	int MAXFRAMEDEFENSA_agachado;

	int MINFRAMEPATADON_saltando;
	int MAXFRAMEPATADON_saltando;
	int MINFRAMEPATADITA_saltando;
	int MAXFRAMEPATADITA_saltando;
	int MINFRAMEPINADEBIL_saltando;
	int MAXFRAMEPINADEBIL_saltando;
	int MINFRAMEPINAFUERTE_saltando;
	int MAXFRAMEPINAFUERTE_saltando;
	int MINFRAMEDEFENSA_saltando;
	int MAXFRAMEDEFENSA_saltando;


	virtual void reproducir_sonido_salto(){};
	virtual void reproducir_sonido_cambio(){};
	virtual void reproducir_sonido_ataque_pu(){};
	virtual void reproducir_sonido_defensa(){};

protected:

	LTexture * texturaJugador;
	int frame = 0;
	SDL_RendererFlip direccion;
	void getSpritesCaminar();
	int zIndex;
};

#endif
