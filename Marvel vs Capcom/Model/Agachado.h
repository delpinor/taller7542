#ifndef AGACHADO_H
#define AGACHADO_H
#include "Estado.h"
class Agachado: public Estado {
public:
	Agachado();
	virtual ~Agachado();
	void move();
	void moveVertical();
	bool estaActivo();
	bool estaAgachado();
	void acelerar();
	bool isFueraDePantalla();
	bool estaCambiandoPersonaje();
	bool estaSaltando();
	//métodos para cliente
	void setEstaActivo(bool estaActivo);
	void setEstaAgachado(bool estaAgachado);
	void setEstaFueraDePantalla(bool estaEstaFueraDePantalla);
	void setEstaCambiandoPersonaje(bool estaEstaCambiandoPersonaje);
	void setEstaSaltando(bool estaSaltando);
protected:
private:
};
#endif // AGACHADO_H
