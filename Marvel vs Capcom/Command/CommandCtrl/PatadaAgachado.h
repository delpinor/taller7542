/*
 * PatadaAgachado.h
 *
 *  Created on: 22 jun. 2019
 *      Author: jorge
 */

#ifndef COMMAND_COMMANDCTRL_PATADAAGACHADO_H_
#define COMMAND_COMMANDCTRL_PATADAAGACHADO_H_

#include "../CommandCtrl.h"


class PatadaAgachado: public CommandCtrl  {
public:
	PatadaAgachado(Model* model);

	void execute(int i);
	virtual ~PatadaAgachado();
};

#endif /* COMMAND_COMMANDCTRL_PATADAAGACHADO_H_ */
