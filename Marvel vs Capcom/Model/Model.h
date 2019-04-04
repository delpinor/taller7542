#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include "Model_Jugador.h"
#include "Equipo.h"
#include "../Command/Command.h"
#include <queue>

class Model {
public:
	Model();
	virtual ~Model();

	virtual void setCamara(SDL_Rect * camara);
	virtual void update();
	Equipo* getEquipoNro(int i);

	virtual void moverJuego();
	Equipo * equipos; //deberia ser un atributo privado

protected:

private:

	SDL_Rect * camara;

};

#endif // MODEL_H
