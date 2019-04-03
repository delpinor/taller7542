#ifndef SALTAR_H
#define SALTAR_H

#include "../CommandCtrl.h"

class Saltar: public CommandCtrl {
public:
	Saltar(Model* model);
	virtual ~Saltar();
	void execute(int i);

protected:

private:
};

#endif // SALTAR_H
