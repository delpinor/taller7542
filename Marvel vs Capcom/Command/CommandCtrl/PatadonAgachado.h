/*
 * PatadonAgachado.h
 *
 *  Created on: 23 jun. 2019
 *      Author: jorge
 */

#ifndef COMMAND_COMMANDCTRL_PATADONAGACHADO_H_
#define COMMAND_COMMANDCTRL_PATADONAGACHADO_H_

#include "../CommandCtrl.h"
class PatadonAgachado : public CommandCtrl{
public:
	PatadonAgachado(Model* model);

	void execute(int i);
	virtual ~PatadonAgachado();
};

#endif /* COMMAND_COMMANDCTRL_PATADONAGACHADO_H_ */
