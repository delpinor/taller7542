#include <iostream>
#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/View.h"
#include "Logger/Logger.h"
#include <string.h>

int main(int argc, char* args[]) {

	Logger::Inicio(NIVEL_LOGGER::DEBUG);
	Logger::Log(NIVEL_LOGGER::INFO, "INICIO","Iniciando el programa...");

	Model model;
	View view(&model);
	Controller controller(&model);
	while (!controller.quitPressed()) {
		controller.processInput();
		model.update();
		view.render();
	}
	return 0;
}

