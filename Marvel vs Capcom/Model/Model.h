#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include "Model_Jugador.h"
#include "../Command/Command.h"
#include <queue>

class Model {
public:
	Model();
	virtual ~Model();

	virtual Jugador* getJugadorNro(int i);
	virtual Jugador* getJugadorActivo();
	virtual void setCamara(SDL_Rect * camara);

	virtual void agregarCambio(Command* cambio);
	virtual void jugadorActivoAumentaVelocidadEnX();
	virtual void jugadorActivoAumentaVelocidadEnY();
	virtual void jugadorActivoSalta();
	virtual void jugadorActivoDisminuyeVelocidadEnX();
	virtual void jugadorActivoDisminuyeVelocidadEnY();
	virtual void jugadorActivoSeAgacha();
	virtual void update();
	virtual void moverJuego();
	int getCantidadJugadores();

protected:

private:
	Jugador* jugadores;
	SDL_Rect * camara;
	unsigned int nroJugadorActivo;
	std::queue<Command*> cambios;
};

#endif // MODEL_H
