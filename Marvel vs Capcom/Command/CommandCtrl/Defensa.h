/*
 * Defensa.h
 *
 *  Created on: 22 jun. 2019
 *      Author: jorge
 */

#ifndef COMMAND_COMMANDCTRL_DEFENSA_H_
#define COMMAND_COMMANDCTRL_DEFENSA_H_
#include "../CommandCtrl.h"

class Defensa: public CommandCtrl {
public:
	Defensa(Model* model);

	void execute(int i);
	virtual ~Defensa();
};

#endif /* COMMAND_COMMANDCTRL_DEFENSA_H_ */
