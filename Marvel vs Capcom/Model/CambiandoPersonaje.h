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
	void moveVertical();
	bool estaActivo();
	bool estaAgachado();
	bool estaCambiandoPersonaje();
	bool isFueraDePantalla();
	//métodos para cliente
	void setEstaActivo(bool estaActivo);
	void setEstaAgachado(bool estaAgachado);
	void setEstaFueraDePantalla(bool estaEstaFueraDePantalla);
	void setEstaCambiandoPersonaje(bool estaEstaCambiandoPersonaje);
};

#endif /* MODEL_CAMBIANDOPERSONAJE_H_ */
