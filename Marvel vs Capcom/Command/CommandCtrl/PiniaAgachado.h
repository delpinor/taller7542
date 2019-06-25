/*
 * PiniaAgachado.h
 *
 *  Created on: 24 jun. 2019
 *      Author: jorge
 */

#ifndef COMMAND_COMMANDCTRL_PINIAAGACHADO_H_
#define COMMAND_COMMANDCTRL_PINIAAGACHADO_H_
#include "../CommandCtrl.h"

class PiniaAgachado: public CommandCtrl {
public:
	PiniaAgachado(Model* model);

	void execute(int i);
	virtual ~PiniaAgachado();
};

#endif /* COMMAND_COMMANDCTRL_PINIAAGACHADO_H_ */
