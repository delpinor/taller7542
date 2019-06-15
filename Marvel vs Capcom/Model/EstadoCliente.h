/*
 * EstadoCliente.h
 *
 *  Created on: 11 may. 2019
 *      Author: maciel
 */

#ifndef MODEL_ESTADOCLIENTE_H_
#define MODEL_ESTADOCLIENTE_H_

#include "Estado.h"

class EstadoCliente: public Estado {
private:

public:
	EstadoCliente();
	void move();
	void moveVertical();
	bool estaActivo();
	bool estaAgachado();
	bool estaCambiandoPersonaje();
	bool estaSaltando();
	//métodos para cliente
	bool isFueraDePantalla();
	void setEstaActivo(bool estaActivo);
	void setEstaAgachado(bool estaAgachado);
	void setEstaFueraDePantalla(bool estaEstaFueraDePantalla);
	void setEstaCambiandoPersonaje(bool estaEstaCambiandoPersonaje);
	void setEstaSaltando(bool estaSaltando);
	~EstadoCliente();
};

#endif /* MODEL_ESTADOCLIENTE_H_ */
