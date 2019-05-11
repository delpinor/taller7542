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
	bool activo = false;
	bool agachado = false;
	bool fueraDePantalla = false;
	bool cambiandoPersonaje = false;
public:
	EstadoCliente();
	void move();
	void moveVertical();
	bool estaActivo();
	bool estaAgachado();
	bool isFueraDePantalla();
	bool estaCambiandoPersonaje();
	void setEstaActivo(bool estaActivo);
	void setEstaAgachado(bool estaAgachado);
	void setEstaFueraDePantalla(bool estaEstaFueraDePantalla);
	void setEstaCambiandoPersonaje(bool estaEstaCambiandoPersonaje);
	~EstadoCliente();
};

#endif /* MODEL_ESTADOCLIENTE_H_ */
