#include "Controller.h"

#include "../Command/CommandCtrl/Agachar.h"
#include "../Command/CommandCtrl/Parar.h"
#include "../Command/CommandCtrl/DisminuirVelocidadY.h"
#include "../Command/CommandCtrl/AumentarVelocidadY.h"
#include "../Command/CommandCtrl/DisminuirVelocidadX.h"
#include "../Command/CommandCtrl/AumentarVelocidadX.h"
#include "../Command/CommandCtrl/Saltar.h"
#include "../Command/CommandCtrl/CambiarPersonaje.h"
#include <iostream>
void Controller::SetModel(Model* model){
	this->model = model;
		this->commands = std::vector<CommandCtrl*>(CANTCOMMANDS);
		this->commands[DECVELX] = new DisminuirVelocidadX(model);
		this->commands[DECVELY] = new DisminuirVelocidadY(model);
		this->commands[INCVELX] = new AumentarVelocidadX(model);
		this->commands[INCVELY] = new AumentarVelocidadY(model);
		this->commands[AGACHAR] = new Agachar(model);
		this->commands[PARAR] = new Parar(model);
		this->commands[SALTAR] = new Saltar(model);
		this->commands[CAMBIAR_PERSONAJE] = new CambiarPersonaje(model);
this->quit = false;
}
Controller::Controller() {
	model = NULL;
	quit = false;
}

Controller::~Controller() {
	for (unsigned i = 0; i < CANTCOMMANDS; ++i) {
		delete this->commands[i];
	}
}
void Controller::SetComando(int equipo, int comando){
	Command* command = NULL;
	command = this->commands[comando];
	this->model->equipos[equipo]->agregarCambio(command);
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
		Logger::Log(LOGGER_NIVEL::DEBUG, "Controller::Event", "Personaje:" +this->model->getEquipoNro(0)->getJugadorActivo()->getNombre() +
		 " Pos x:"+ std::to_string(this->model->getEquipoNro(0)->getJugadorActivo()->getPosX()) +
		 " Pos y:" + std::to_string(this->model->getEquipoNro(0)->getJugadorActivo()->getPosY()));

		Logger::Log(LOGGER_NIVEL::DEBUG, "Controller::Event", "Personaje:" +this->model->getEquipoNro(1)->getJugadorActivo()->getNombre() +
				 " Pos x:"+ std::to_string(this->model->getEquipoNro(1)->getJugadorActivo()->getPosX()) +
				 " Pos y:" + std::to_string(this->model->getEquipoNro(1)->getJugadorActivo()->getPosY()));
	}
}
Command* Controller::handleEvent(SDL_Event& e) {
	Command* command = NULL;

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_UP:
			command = this->commands[INCVELY];
			this->model->equipos[0]->agregarCambio(command);
			break;
		case SDLK_DOWN:
			command = this->commands[AGACHAR];
			this->model->equipos[0]->agregarCambio(command);
			break;
		case SDLK_LEFT:
			command = this->commands[DECVELX];
			this->model->equipos[0]->agregarCambio(command);
			break;
		case SDLK_RIGHT:
			command = this->commands[INCVELX];
			this->model->equipos[0]->agregarCambio(command);
			break;
		case SDLK_RCTRL:
			command = this->commands[CAMBIAR_PERSONAJE];
			this->model->equipos[0]->agregarCambio(command);
			break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_UP:

			break;
		case SDLK_DOWN:
			command = this->commands[PARAR];
			this->model->equipos[0]->agregarCambio(command);
			break;
		case SDLK_LEFT:
			command = this->commands[INCVELX];
			this->model->equipos[0]->agregarCambio(command);
			break;
		case SDLK_RIGHT:
			command = this->commands[DECVELX];
			this->model->equipos[0]->agregarCambio(command);
			break;
		}
	}

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
			switch (e.key.keysym.sym) {
			case SDLK_w:
				command = this->commands[INCVELY];
				this->model->equipos[1]->agregarCambio(command);
				break;
			case SDLK_s:
				command = this->commands[AGACHAR];
				this->model->equipos[1]->agregarCambio(command);
				break;
			case SDLK_a:
				command = this->commands[DECVELX];
				this->model->equipos[1]->agregarCambio(command);
				break;
			case SDLK_d:
				command = this->commands[INCVELX];
				this->model->equipos[1]->agregarCambio(command);
				break;
			case SDLK_LCTRL:
				command = this->commands[CAMBIAR_PERSONAJE];
				this->model->equipos[1]->agregarCambio(command);
				break;
			}
		}
		//If a key was released
		else if (e.type == SDL_KEYUP && e.key.repeat == 0) {

			switch (e.key.keysym.sym) {
			case SDLK_w:

				break;
			case SDLK_s:
				command = this->commands[PARAR];
				this->model->equipos[1]->agregarCambio(command);
				break;
			case SDLK_a:
				command = this->commands[INCVELX];
				this->model->equipos[1]->agregarCambio(command);
				break;
			case SDLK_d:
				command = this->commands[DECVELX];
				this->model->equipos[1]->agregarCambio(command);
				break;
			}
		}

	return command;
}

int Controller::processInputCliente() {
	while (SDL_PollEvent(&(this->e)) != 0) {
		if (this->e.type == SDL_QUIT) {
			this->quit = true;
			//TODO accion al cerrar el juego
		}
		return handleEventCliente(this->e);

}}

int Controller::handleEventCliente(SDL_Event& e) {

//	std::cout << "procesar evento." << std::endl;
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {

		switch (e.key.keysym.sym) {
		case SDLK_UP:
			return INCVELY;
			break;
		case SDLK_DOWN:
			return AGACHAR;
			break;
		case SDLK_LEFT:
			return DECVELX;
			break;
		case SDLK_RIGHT:
			return INCVELX;
			break;
		case SDLK_RCTRL:
			return CAMBIAR_PERSONAJE;
			break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_UP:

			break;
		case SDLK_DOWN:
			return PARAR;
			break;
		case SDLK_LEFT:
			return INCVELX;
			break;
		case SDLK_RIGHT:
			return DECVELX;
			break;
		}
	}

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
			switch (e.key.keysym.sym) {
			case SDLK_w:
				return INCVELY;
				break;
			case SDLK_s:
				return AGACHAR;
				break;
			case SDLK_a:
				return DECVELX;
				break;
			case SDLK_d:
				return INCVELX;
				break;
			case SDLK_LCTRL:
				return CAMBIAR_PERSONAJE;
				break;
			}
		}
		//If a key was released
		else if (e.type == SDL_KEYUP && e.key.repeat == 0) {

			switch (e.key.keysym.sym) {
			case SDLK_w:

				break;
			case SDLK_s:
				return PARAR;
				break;
			case SDLK_a:
				return INCVELX;
				break;
			case SDLK_d:
				return DECVELX;
				break;
			}
		}
//	std::cout << "evento:" << command <<std::endl;
	return 99;
}
