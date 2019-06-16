#ifndef PATADON_H
#define PATADON_H

#include "../CommandCtrl.h"

class Patadon: public CommandCtrl {
public:
	Patadon(Model* model);
	virtual ~Patadon();
	void execute(int i);

protected:

private:
};

#endif // PATADON_H
