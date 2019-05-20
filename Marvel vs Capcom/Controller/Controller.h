#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../Model/Model.h"
#include "../Command/CommandCtrl.h"
#include <vector>
class Controller {
public:
	Controller();
	void SetModel(Model* model);
	virtual ~Controller();
	Command* handleEvent(SDL_Event& e);
	void processInput();
	int handleEventCliente(SDL_Event& e);
	int processInputCliente();
	bool quitPressed();
	void SetComando(int equipo, int comando);
protected:
private:
	Model* model;
	std::vector<CommandCtrl*> commands;
	bool quit;
	SDL_Event e;
};
#endif // CONTROLLER_H
