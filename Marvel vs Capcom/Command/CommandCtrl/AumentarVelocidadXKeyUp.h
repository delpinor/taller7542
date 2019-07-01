#ifndef AUMENTARVELOCIDADXKEYUP_H
#define AUMENTARVELOCIDADXKEYUP_H

#include "../CommandCtrl.h"

class AumentarVelocidadXKeyUp: public CommandCtrl {
public:
	AumentarVelocidadXKeyUp(Model* model);
	virtual ~AumentarVelocidadXKeyUp();
	void execute(int i);

protected:

private:
};

#endif // AUMENTARVELOCIDADXKEYUP_H
