#ifndef MODEL_JUGADOR_H_
#define MODEL_JUGADOR_H_
#include <SDL2/SDL.h>
#include "../Model/LTexture.h"
#include "../Model/Estado.h"
#include "../Model/Activo.h"
#include "../Model/Inactivo.h"
#include "../Model/Agachado.h"
#include "../Model/CambiandoPersonaje.h"
#define VENOM 0x01
#define CAPAMERICA 0x00

class Jugador {
private:
	 //int ANCHO_JUGADOR = 90;
	 //int ALTO_JUGADOR = 120;
	 std:: string nombre;
	 std:: string pathImagen;
	 int height;
	 int width;
	 int zindex;
	static const int VELOCIDAD_JUGADOR = 1;

	SDL_Rect mCollider;

	CambiandoPersonaje cambiandoPersonaje;
	Activo activo;
	Inactivo inactivo;
	Agachado agachado;
	SDL_RendererFlip direccion;
	int personaje;
public:
	Estado* estado;

	Jugador();
	Jugador(int &ancho, int &alto, int &zind,std::string &nom,std::string &pathImagen);
	int get_alto();
	int get_ancho();
	int get_zindex();
	std::string getNombre();
	std::string getPath();


	//void move();
	void move(Jugador* jugadorRival, SDL_Rect* camara);
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
	void Parar();
	void cambiarPersonaje();
	void aumentarVelocidadX();
	void aumentarVelocidadY();
	void Saltar();
	bool estaActivo();
	bool estaAgachado();
	bool estaCambiandoPersonaje();
	void detenerVelocidad();
	void activar();
	void desactivar();
	void setDireccion(SDL_RendererFlip direccion);
	bool collide(SDL_Rect * camara);
	bool collideDerecha(SDL_Rect * camara);
	bool collideIzquierda(SDL_Rect * camara);
	SDL_RendererFlip getDireccion();
	void updateDirection(Jugador &oponente);
	void updateAceleracion(int ac);
	std::string datosString();
	int Personaje();
	void setPersonaje(int);
	std::string getPathImagen();
	void aumentarVelocidadX(int vel);
	void aumentarVelocidadY(int vel);
	bool isFueraDePantalla();
	bool movimientoDerecha();
	bool movimientoIzquierda();

};
#endif
