#ifndef PARAR_H
#define PARAR_H

#include "../CommandCtrl.h"

class Parar: public CommandCtrl {
public:
	Parar(Model* model);
	virtual ~Parar();
	void execute(int i);
protected:

private:
};

#endif // PARAR_H
