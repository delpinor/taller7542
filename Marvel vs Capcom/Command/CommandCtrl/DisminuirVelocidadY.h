#ifndef DISMINUIRVELOCIDADY_H
#define DISMINUIRVELOCIDADY_H

#include "../CommandCtrl.h"

class DisminuirVelocidadY: public CommandCtrl {
public:
	DisminuirVelocidadY(Model* model);
	virtual ~DisminuirVelocidadY();
	void execute(int i);

protected:

private:
};

#endif // DISMINUIRVELOCIDADY_H
