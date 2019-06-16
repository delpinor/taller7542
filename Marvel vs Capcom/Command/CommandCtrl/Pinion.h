#ifndef PINION_H
#define PINION_H

#include "../CommandCtrl.h"

class Pinion: public CommandCtrl {
public:
	Pinion(Model* model);
	virtual ~Pinion();
	void execute(int i);

protected:

private:
};

#endif // PINION_H
