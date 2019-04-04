#include <iostream>
#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/View.h"
#include "ParserConfig.h"
int main(int argc, char* argv[]) {
	int error;
	ParserConfig parser;
	try{
		error=parser.parsear_archivo(argv[1]);

	}catch(Exception &e){
		std::cout<<e.what();
		return ERROR;
	}

			std::map< std::string, std::map<std::string, std::string> > mapPersonajes;
			std::map<int, std::map<std::string, std::string> > mapBackground;
			string tipoLog;
			int ancho, alto;


			error=parser.devolver_Map_Personajes(&mapPersonajes);
			error=parser.devolver_Map_Fondo(&mapBackground);
			error=parser.devolver_Tam_Imagen(&ancho,&alto);
			tipoLog=parser.devolver_Tipo_Log();

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

