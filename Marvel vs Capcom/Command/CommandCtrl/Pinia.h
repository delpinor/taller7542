#ifndef PINIA_H
#define PINIA_H

#include "../CommandCtrl.h"

class Pinia: public CommandCtrl {
public:
	Pinia(Model* model);
	virtual ~Pinia();
	void execute(int i);

protected:

private:
};

#endif // PINIA_H
