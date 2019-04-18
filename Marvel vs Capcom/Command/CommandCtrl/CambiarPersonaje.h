/*
 * CambiarJugador.h
 *
 *  Created on: 15 abr. 2019
 *      Author: maciel
 */

#include "../CommandCtrl.h"

#ifndef COMMAND_COMMANDCTRL_CAMBIARJUGADOR_H_
#define COMMAND_COMMANDCTRL_CAMBIARJUGADOR_H_

class CambiarPersonaje: public CommandCtrl {
public:
	CambiarPersonaje(Model* model);
	virtual ~CambiarPersonaje();
	void execute(int i);
};

#endif /* COMMAND_COMMANDCTRL_CAMBIARJUGADOR_H_ */
