/*
 * PinionAgachado.h
 *
 *  Created on: 22 jun. 2019
 *      Author: jorge
 */

#ifndef COMMAND_COMMANDCTRL_PINIONAGACHADO_H_
#define COMMAND_COMMANDCTRL_PINIONAGACHADO_H_
#include "../CommandCtrl.h"

class PinionAgachado: public CommandCtrl {
public:
	PinionAgachado(Model* model);

	void execute(int i);
	virtual ~PinionAgachado();
};

#endif /* COMMAND_COMMANDCTRL_PINIONAGACHADO_H_ */
