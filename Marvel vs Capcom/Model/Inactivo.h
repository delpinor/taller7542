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
#endif // INACTIVO_H
