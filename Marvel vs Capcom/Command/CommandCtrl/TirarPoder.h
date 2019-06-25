#ifndef TIRARPODER_H
#define TIRARPODER_H

#include "../CommandCtrl.h"

class TirarPoder: public CommandCtrl {
public:
	TirarPoder(Model* model);
	virtual ~TirarPoder();
	void execute(int i);

protected:

private:
};

#endif // TIRARPODER_H
