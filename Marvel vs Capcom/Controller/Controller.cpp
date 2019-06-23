#include "Controller.h"

#include "../Command/CommandCtrl/Agachar.h"
#include "../Command/CommandCtrl/Parar.h"
#include "../Command/CommandCtrl/DisminuirVelocidadY.h"
#include "../Command/CommandCtrl/AumentarVelocidadY.h"
#include "../Command/CommandCtrl/DisminuirVelocidadX.h"
#include "../Command/CommandCtrl/AumentarVelocidadX.h"
#include "../Command/CommandCtrl/Saltar.h"
#include "../Command/CommandCtrl/CambiarPersonaje.h"
#include "../Command/CommandCtrl/Pinia.h"
#include "../Command/CommandCtrl/Pinion.h"
#include "../Command/CommandCtrl/Patada.h"
#include "../Command/CommandCtrl/Patadon.h"
#include "../Command/CommandCtrl/Defensa.h"
#include "../Command/CommandCtrl/PatadaAgachado.h"
#include "../Command/CommandCtrl/PinionAgachado.h"
#include "../Command/CommandCtrl/Arrojar.h"
#include "../Command/CommandCtrl/TirarPoder.h"
#include <iostream>
void Controller::SetModel(Model* model) {
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
	this->commands[PINIA] = new Pinia(model);
	this->commands[PINION] = new Pinion(model);
	this->commands[PATADA] = new Patada(model);
	this->commands[PATADON] = new Patadon(model);
	this->commands[DEFENSA] = new Defensa(model);
	this->commands[ARROJAR] = new Arrojar(model);
	this->commands[PATADA_AGACHADO ] = new PatadaAgachado(model);
	this->commands[PINION_AGACHADO ] = new PinionAgachado(model);
	this->commands[PODER] = new TirarPoder(model);
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
void Controller::SetComando(int equipo, int comando) {
	Command* command = NULL;
	command = this->commands[comando];
	this->model->equipos[equipo]->agregarCambio(command);
}
bool Controller::quitPressed() {
	return this->quit;
}
void Controller::set_quit(){
	this->quit=true;

}

int Controller::processInputCliente() {
	while (SDL_PollEvent(&(this->e)) != 0) {
		if (this->e.type == SDL_QUIT)
			this->quit = true;
	//		//TODO accion al cerrar el juego
		else
			return handleEventCliente(this->e);
	}
	return 99;
}

int Controller::handleEventCliente(SDL_Event& e) {
	int comando = 99;
	  //Get the keystates
//obtengo los estados de todas las teclas
	const Uint8 *state =SDL_GetKeyboardState(NULL);
//si esta presionada la s y la k . es decir si esta agachado y quiere hacer la patada
	if  ((state[SDL_SCANCODE_S])&& (state[SDL_SCANCODE_K])){

		comando=PATADA_AGACHADO;
	} else if((state[SDL_SCANCODE_S])&& (state[SDL_SCANCODE_U])){
		comando=PINION_AGACHADO;

	}else{

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_w:
			comando =  SALTAR;
			break;
		case SDLK_s:
						comando =  AGACHAR;

						break;
		case SDLK_a:
			comando =  DECVELX;
			break;
		case SDLK_d:
			comando =  INCVELX;
			break;
		case SDLK_j:
			comando =  PINIA;
			break;
		case SDLK_k:
			comando =  PATADA;
			break;
		case SDLK_u:
			comando =  PINION;
			break;
		case SDLK_i:
			comando =  PATADON;
			break;
		case  SDLK_h:
			comando =  DEFENSA;
			break;
		case  SDLK_o:
			comando =  ARROJAR;
			break;
		case  SDLK_l:
			comando =  PODER;
			break;
		case SDLK_LCTRL:
			comando =  CAMBIAR_PERSONAJE;
			break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0) {

		switch (e.key.keysym.sym) {
		//case SDLK_w:

		//	break;
		case SDLK_s:
			comando =  PARAR;
			break;
		case SDLK_a:
			comando =  INCVELX;
			break;
		case SDLK_d:
			comando = DECVELX;
			break;
		}
	}
	}
	return comando;
}
