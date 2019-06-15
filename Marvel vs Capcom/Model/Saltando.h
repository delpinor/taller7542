/*
 * Saltando.h
 *
 *  Created on: 13 jun. 2019
 *      Author: maciel
 */

#ifndef MODEL_SALTANDO_H_
#define MODEL_SALTANDO_H_

#include "Estado.h"

class Saltando: public Estado {
public:
	Saltando();
	bool comenzoSalto = false;
	 void move();
	 void moveVertical();
	 bool estaActivo();
	 bool estaAgachado();
	 bool estaCambiandoPersonaje();
	 bool estaSaltando();
	 bool isFueraDePantalla();
	//métodos para el cliente
	 void setEstaActivo(bool estaActivo);
	 void setEstaAgachado(bool estaAgachado);
	 void setEstaFueraDePantalla(bool estaEstaFueraDePantalla);
	 void setEstaCambiandoPersonaje(bool estaEstaCambiandoPersonaje);
	 void setEstaSaltando(bool saltando);
	virtual ~Saltando();
};

#endif /* MODEL_SALTANDO_H_ */
