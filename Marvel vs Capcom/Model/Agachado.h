#ifndef AGACHADO_H
#define AGACHADO_H
#include "Estado.h"
class Agachado: public Estado {
public:
	Agachado();
	virtual ~Agachado();
	void move();
	bool estaActivo();
	bool estaAgachado();
	bool estaEnEspera();
	void acelerar();
	bool isFueraDePantalla();
	bool estaCambiandoPersonaje();
protected:
private:
};
#endif // AGACHADO_H
