/*
 * CambiandoPersonaje.h
 *
 *  Created on: 18 abr. 2019
 *      Author: maciel
 */

#ifndef MODEL_CAMBIANDOPERSONAJE_H_
#define MODEL_CAMBIANDOPERSONAJE_H_

#include "Estado.h"

class CambiandoPersonaje: public Estado {
public:
	CambiandoPersonaje();
	virtual ~CambiandoPersonaje();
	void move();
	bool estaActivo();
	bool estaAgachado();
	bool estaCambiandoPersonaje();
	bool isFueraDePantalla();
};

#endif /* MODEL_CAMBIANDOPERSONAJE_H_ */
