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
	void getSpriteByGolpe(SDL_Rect* currentClip, int &frame, TIPO_GOLPE tipoGolpe);
	Jugador *jugador;
	int getZIndex();
	SDL_Rect * gSpriteCaminar;
	SDL_Rect * gSpriteCambiarPersonaje;
	SDL_Rect  *gSpriteSaltar;
	SDL_Rect  *gSpriteAgachar;
	SDL_Rect  *gSpriteGolpear;
	SDL_Rect  *gSpriteAnimacion;
	SDL_Rect  *gSpritePatadon;
	SDL_Rect  *gSpritePatada;
	SDL_Rect  *gSpritePatadaSaltando;
	SDL_Rect  *gSpritePatadonSaltando;
	SDL_Rect  *gSpritePatadaAgachado;
	SDL_Rect  *gSpritePatadonAgachado;
	SDL_Rect  *gSpritePinia;
	SDL_Rect  *gSpritePinion;
	SDL_Rect  *gSpritePiniaSaltando;
	SDL_Rect  *gSpritePinionSaltando;
	SDL_Rect  *gSpritePiniaAgachado;
	SDL_Rect  *gSpritePinionAgachado;

	SDL_Rect * gSprite;
	int contador = 0;

	int CANTSPRITECLIP;
	int CANTSPRITECLIPCAMINA;
	int MINFRAMECAMINA;
	int MAXFRAMECAMINA;
	int FACTORCAMINA;
	int CANTSPRITECLIPSALTA;
	int MINFRAMESALTA;
	int MAXFRAMESALTA;
	int FACTORSALTA;
	int CANTSPRITEANIMACION;
	int MINFRAMEANIMACION;
	int MAXFRAMEANIMACION;
	int FACTORANIMACION;
	int CANTSPRITECLIPPATADON;
	int MINFRAMEPATADON;
	int MAXFRAMEPATADON;
	int FACTORPATADON;
	int CANTSPRITECLIPPATADA;
	int MINFRAMEPATADA;
	int MAXFRAMEPATADA;
	int FACTORPATADA;
	int CANTSPRITECLIPPATADASALTANDO;
	int MAXFRAMEPATADASALTANDO;
	int MINFRAMEPATADASALTANDO;
	int FACTORPATADASALTANDO;
	int CANTSPRITECLIPPATADONSALTANDO;
	int MINFRAMEPATADONSALTANDO;
	int MAXFRAMEPATADONSALTANDO;
	int FACTORPATADONSALTANDO;
	int CANTSPRITECLIPPINIA;
	int MINFRAMEPINIA;
	int MAXFRAMEPINIA;
	int FACTORPINIA;
	int CANTSPRITECLIPPINION;
	int MINFRAMEPINION;
	int MAXFRAMEPINION;
	int FACTORPINION;
	int CANTSPRITECLIPPINIASALTANDO;
	int MINFRAMEPINIASALTANDO;
	int MAXFRAMEPINIASALTANDO;
	int FACTORPINIASALTANDO;
	int CANTSPRITECLIPPINIONSALTANDO;
	int MINFRAMEPINIONSALTANDO;
	int MAXFRAMEPINIONSALTANDO;
	int FACTORPINIONSALTANDO;

	int maxFrame;
	int factor;

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
