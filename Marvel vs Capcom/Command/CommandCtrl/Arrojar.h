#ifndef ARROJAR_H
#define ARROJAR_H

#include "../CommandCtrl.h"

class Arrojar: public CommandCtrl {
public:
	Arrojar(Model* model);
	virtual ~Arrojar();
	void execute(int i);

protected:

private:
};

#endif // ARROJAR_H
