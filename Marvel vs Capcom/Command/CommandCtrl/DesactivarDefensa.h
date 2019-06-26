/*
 * DesactivarDefensa.h
 *
 *  Created on: 23 jun. 2019
 *      Author: maciel
 */
#include "../CommandCtrl.h"

#ifndef COMMAND_COMMANDCTRL_DESACTIVARDEFENSA_H_
#define COMMAND_COMMANDCTRL_DESACTIVARDEFENSA_H_

class DesactivarDefensa: public CommandCtrl {
public:
	DesactivarDefensa(Model* model);
	void execute(int i);
	virtual ~DesactivarDefensa();
};

#endif /* COMMAND_COMMANDCTRL_DESACTIVARDEFENSA_H_ */
