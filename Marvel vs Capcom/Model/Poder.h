#ifndef PODER_H_
#define PODER_H_
#include <stdio.h>

class Poder {
public:
	Poder();
	int izquierda;
	int arriba;
	int derecha;
	int abajo;
	int sentido;
	void setPosInX(int x);
	void setPosInY(int y);
	void setActivo();
	void setInactivo();
	void move();
	void activarPoder(int x, int y ,int sentido);
	bool estaActivo();
	bool colision(int x , int y, int w, int h );
	bool activo = false;
	int getPosX();
	int getPosY();
	int getSentido();
	void setPosX(int x);
	void setPosY(int y);
	void setSentido(int z);
	};
#endif
