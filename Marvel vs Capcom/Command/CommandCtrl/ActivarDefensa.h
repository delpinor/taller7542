/*
 * Defensa.h
 *
 *  Created on: 23 jun. 2019
 *      Author: maciel
 */

#include "../CommandCtrl.h"

#ifndef COMMAND_COMMANDCTRL_DEFENSA_H_
#define COMMAND_COMMANDCTRL_DEFENSA_H_

class ActivarDefensa: public CommandCtrl {
public:
	ActivarDefensa(Model* model);
	void execute(int i);
	virtual ~ActivarDefensa();
};

#endif /* COMMAND_COMMANDCTRL_DEFENSA_H_ */
