/*
 * Agarrar.h
 *
 *  Created on: 4 jul. 2019
 *      Author: maciel
 */

#include "../CommandCtrl.h"

#ifndef COMMAND_COMMANDCTRL_AGARRAR_H_
#define COMMAND_COMMANDCTRL_AGARRAR_H_

class Tomado: public CommandCtrl {
public:
	Tomado(Model *model);
	void execute(int i);
	virtual ~Tomado();
};

#endif /* COMMAND_COMMANDCTRL_AGARRAR_H_ */
