#ifndef PATADA_H
#define PATADA_H

#include "../CommandCtrl.h"

class Patada: public CommandCtrl {
public:
	Patada(Model* model);
	virtual ~Patada();
	void execute(int i);

protected:

private:
};

#endif // PATADA_H
