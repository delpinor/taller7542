#ifndef MODEL_JUGADOR_H_
#define MODEL_JUGADOR_H_
#include <SDL2/SDL.h>
#include "../Model/LTexture.h"
#include "../Model/Estado.h"
#include "../Model/Activo.h"
#include "../Model/Inactivo.h"
#define VENOM 0x00
#define CAPAMERICA 0x01

class Jugador {
public:
	static const int ANCHO_JUGADOR = 90;
	static const int ALTO_JUGADOR = 120;
	static const int VELOCIDAD_JUGADOR = 1;
	Jugador();
	void move();
	int getPosX();
	int getPosY();
	int getVelX();
	int getVelY();
	void setPosX(int PosX);
	void setPosY(int PosY);
	void setPosInitX(int posX);
	void setPosInitY(int posY);
	void disminuirVelocidadY();
	void disminuirVelocidadX();
	void Agachar();
	void aumentarVelocidadX();
	void aumentarVelocidadY();
	void Saltar();
	bool estaActivo();
	void detenerVelocidad();
	void activar();
	void desactivar();
	void setDireccion(SDL_RendererFlip direccion);
	bool collide(SDL_Rect * camara);
	SDL_RendererFlip getDireccion();
	void updateDirection();
	void updateAceleracion(int ac);
	std::string datosString();
	int Personaje();
	void setPersonaje(int);
private:
	SDL_Rect mCollider;
	Estado* estado;
	Activo activo;
	Inactivo inactivo;
	SDL_RendererFlip direccion;
	int personaje;
};
#endif
