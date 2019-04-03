#include "Controller.h"

#include "../Command/CommandCtrl/Agachar.h"
#include "../Command/CommandCtrl/DisminuirVelocidadY.h"
#include "../Command/CommandCtrl/AumentarVelocidadY.h"
#include "../Command/CommandCtrl/DisminuirVelocidadX.h"
#include "../Command/CommandCtrl/AumentarVelocidadX.h"
#include "../Command/CommandCtrl/Saltar.h"

Controller::Controller(Model* model) {
	this->model = model;
	this->commands = std::vector<CommandCtrl*>(CANTCOMMANDS);
	this->commands[DECVELX] = new DisminuirVelocidadX(model);
	this->commands[DECVELY] = new DisminuirVelocidadY(model);
	this->commands[INCVELX] = new AumentarVelocidadX(model);
	this->commands[INCVELY] = new AumentarVelocidadY(model);
	this->commands[AGACHAR] = new Agachar(model);
	this->commands[SALTAR] = new Saltar(model);
	this->quit = false;
}
Controller::~Controller() {
	for (unsigned i = 0; i < CANTCOMMANDS; ++i) {
		delete this->commands[i];
	}
}
bool Controller::quitPressed() {
	return this->quit;
}
void Controller::processInput() {
	while (SDL_PollEvent(&(this->e)) != 0) {
		if (this->e.type == SDL_QUIT) {
			this->quit = true;
		}
		handleEvent(this->e);
	}
}
Command* Controller::handleEvent(SDL_Event& e) {
	Command* command = NULL;

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_UP:
			command = this->commands[INCVELY];
			break;
		case SDLK_DOWN:

			break;
		case SDLK_LEFT:
			command = this->commands[DECVELX];
			break;
		case SDLK_RIGHT:
			command = this->commands[INCVELX];
			break;
		}
		this->model->equipos[0].agregarCambio(command);
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_UP:

			break;
		case SDLK_DOWN:

			break;
		case SDLK_LEFT:
			command = this->commands[INCVELX];
			break;
		case SDLK_RIGHT:
			command = this->commands[DECVELX];
			break;
		}
		this->model->equipos[0].agregarCambio(command);
	}

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
			switch (e.key.keysym.sym) {
			case SDLK_w:
				command = this->commands[INCVELY];
				break;
			case SDLK_s:

				break;
			case SDLK_a:
				command = this->commands[DECVELX];
				break;
			case SDLK_d:
				command = this->commands[INCVELX];
				break;
			}
			this->model->equipos[1].agregarCambio(command);
		}
		//If a key was released
		else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
			switch (e.key.keysym.sym) {
			case SDLK_w:
				command = this->commands[INCVELY];
				break;
			case SDLK_s:

				break;
			case SDLK_a:
				command = this->commands[INCVELX];
				break;
			case SDLK_d:
				command = this->commands[DECVELX];
				break;
		}
			this->model->equipos[1].agregarCambio(command);
		}

	return command;
}
