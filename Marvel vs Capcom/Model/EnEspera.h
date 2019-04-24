#ifndef ENESPERA_H
#define ENESPERA_H
#include "Estado.h"
class EnEspera: public Estado {
public:
	EnEspera();
	virtual ~EnEspera();
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
#endif // ENESPERA_H
