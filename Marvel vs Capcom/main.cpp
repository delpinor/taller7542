#include <iostream>
#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/View.h"
int main(int argc, char* args[]) {
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

