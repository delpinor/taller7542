#ifndef MODEL_JUGADOR_H_
#define MODEL_JUGADOR_H_
#include <SDL2/SDL.h>
#include "../Model/LTexture.h"
#include "../Model/Estado.h"
#include "../Model/Activo.h"
#include "../Model/Inactivo.h"
#include "../Model/Agachado.h"
#include "../Model/Saltando.h"
#include "../Model/CambiandoPersonaje.h"
#include "../Model/EstadoCliente.h"
#include "../Model/TipoGolpe.h"
#include "../Model/Poder.h"
#define VENOM 0x01
#define CAPAMERICA 0x00

class Jugador {

private:
	 //int ANCHO_JUGADOR = 90;
	 //int ALTO_JUGADOR = 120;
	 std:: string nombre;
	 std:: string pathImagen;
	 int vidaJugador;
	 int height;
	 int width;
	 int zindex;
	 bool debeTerminarSalto = false;
	 bool iniciarGolpe = false;
	 int r = 255;
	 int g = 255;
	 int b = 255;
	static const int VELOCIDAD_JUGADOR = 1;

	SDL_Rect mCollider;

	CambiandoPersonaje cambiandoPersonaje;
	Activo activo;
	Inactivo inactivo;
	Agachado agachado;
	Saltando saltando;
	SDL_RendererFlip direccion;
	int personaje;
	bool desconectado=false;
	TIPO_GOLPE tipoGolpe = NADA;
	bool inmortal;

public:
	Estado* estado;
//	EstadoCliente * estado;

	Jugador();
	int GetVida();
	void SetVida(int vida);
	void set_desconectado();
	void set_conectado();
	bool get_estado_desconexion();
	Jugador(int &ancho, int &alto, int &zind,std::string &nom,std::string &pathImagen, bool &inmortal);
	int get_alto();
	int get_ancho();
	int get_zindex();
	std::string getNombre();
	std::string getPath();
	void setColor(int,int,int);
	int getR();
	int getG();
	int getB();
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
	void Defensa();
	void Pinia(Jugador * rival);
	void Pinion(Jugador * rival);
	void Pinion_agachado(Jugador * rival);
	void Patada(Jugador * rival);
	void Patadon(Jugador * rival);
	void Patada_agachado(Jugador * rival);
	void Arrojar(Jugador * rival);
	void recibeDanio(int danio);
	bool estaActivo();
	bool estaAgachado();
	bool estaCambiandoPersonaje();
	bool estaSaltando();
	void detenerVelocidad();
	void activar();
	void desactivar();
	void terminarSalto();
	void setDireccion(SDL_RendererFlip direccion);
	bool collide(SDL_Rect * camara);
	bool collideConJugador(SDL_Rect * camara);
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
	bool isDebeTerminarSalto();
	void setDebeTerminarSalto(bool debeTerminarSalto);
	TIPO_GOLPE getTipoGolpe();
	void setTipoGolpe(TIPO_GOLPE tipoGolpe);
	bool isIniciarGolpe();
	void setIniciarGolpe(bool iniciarGolpe);
	bool murio();
	bool estaVivo();
	void inicializarVida();
	bool esInmortal();
	void jugadorVolando();
	void TirarPoder(Jugador * rival);
	Poder * mipoder;
	};
#endif
