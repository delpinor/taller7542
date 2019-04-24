#ifndef ACTIVO_H
#define ACTIVO_H

#include "Estado.h"
#include <SDL2/SDL.h>
class Activo: public Estado {
public:
	Activo();
	virtual ~Activo();
	void move();
	bool estaActivo();
	bool estaAgachado();
	bool estaEnEspera();
	bool isFueraDePantalla();
	bool estaCambiandoPersonaje();
protected:

private:

};

#endif // ACTIVO_H
