#ifndef PODER_H_
#define PODER_H_

class Poder {
public:
	Poder(int x, int y ,int sentido);
	int izquierda;
	int arriba;
	int derecha;
	int abajo;
	int sentido;
	void setPosInX(int x);
	void setPosInY(int y);
	void move();
	bool colision(int x , int y, int w, int h );
	};
#endif
