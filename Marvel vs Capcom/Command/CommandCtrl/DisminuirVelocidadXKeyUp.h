#ifndef DISMINUIRVELOCIDADXKEYUP_H
#define DISMINUIRVELOCIDADXKEYUP_H

#include "../CommandCtrl.h"

class DisminuirVelocidadXKeyUp: public CommandCtrl {
public:
	DisminuirVelocidadXKeyUp(Model* model);
	virtual ~DisminuirVelocidadXKeyUp();
	void execute(int i);

protected:

private:
};

#endif // DISMINUIRVELOCIDADXKEYUP_H
