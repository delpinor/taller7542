#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../Model/Model.h"
#include "../Command/CommandCtrl.h"
#include <vector>
class Controller {
public:
	Controller(Model* model);
	virtual ~Controller();
	Command* handleEvent(SDL_Event& e);
	void processInput();
	int handleEventCliente(SDL_Event& e);
	int processInputCliente();
	bool quitPressed();
protected:
private:
	Model* model;
	std::vector<CommandCtrl*> commands;
	bool quit;
	SDL_Event e;
};
#endif // CONTROLLER_H
