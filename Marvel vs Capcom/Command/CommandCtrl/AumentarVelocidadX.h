#ifndef AUMENTARVELOCIDADX_H
#define AUMENTARVELOCIDADX_H

#include "../CommandCtrl.h"

class AumentarVelocidadX: public CommandCtrl {
public:
	AumentarVelocidadX(Model* model);
	virtual ~AumentarVelocidadX();
	void execute(int i);

protected:

private:
};

#endif // AUMENTARVELOCIDADX_H
