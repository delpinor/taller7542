#ifndef ACTIVO_H
#define ACTIVO_H

#include "Estado.h"

#include <SDL2/SDL.h>
class Activo: public Estado {
public:
	Activo();
	virtual ~Activo();
	void move();
	void moveVertical();
	bool estaActivo();
	bool estaAgachado();
	bool isFueraDePantalla();
	bool estaCambiandoPersonaje();
	bool estaQuieto();
	//métodos para cliente
	void setEstaActivo(bool estaActivo);
	void setEstaAgachado(bool estaAgachado);
	void setEstaFueraDePantalla(bool estaEstaFueraDePantalla);
	void setEstaCambiandoPersonaje(bool estaEstaCambiandoPersonaje);
protected:

private:
	bool quieto=true;
};

#endif // ACTIVO_H
