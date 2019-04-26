#ifndef AGACHAR_H
#define AGACHAR_H

#include "../CommandCtrl.h"

class Agachar: public CommandCtrl {
public:
	Agachar(Model* model);
	virtual ~Agachar();
	void execute(int i);
protected:

private:
};

#endif // AGACHAR_H
