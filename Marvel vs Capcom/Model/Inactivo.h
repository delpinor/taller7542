#ifndef INACTIVO_H
#define INACTIVO_H
#include "Estado.h"
class Inactivo: public Estado {
public:
	Inactivo();
	virtual ~Inactivo();
	void move();
	void moveVertical();
	bool estaActivo();
	bool estaAgachado();
	void acelerar();
	bool isFueraDePantalla();
	bool estaCambiandoPersonaje();
protected:
private:
};
#endif // INACTIVO_H
