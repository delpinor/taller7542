#include <iostream>
#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/View.h"
#include "Configuracion.h"
int main(int argc, char* argv[]) {
	int error;
	//ParserConfig parser;
	Configuracion appConfig("config.json");
	try{
		//error=parser.parsear_archivo(argv[1]);

	}catch(Exception &e){
		std::cout<<e.what();
		return ERROR;
	}

			std::map< int, std::map<std::string, std::string> > mapPersonajes;
			std::map<int, std::map<std::string, std::string> > mapFondoPantalla;
			std::map<std::string, std::string> mapNivel;
			string nivelLog;
			int anchoVentana, altoVentana;


			/*error=parser.devolver_Map_Personajes(&mapPersonajes);
			error=parser.devolver_Map_Fondo(&mapBackground);
			error=parser.devolver_Tam_Imagen(&ancho,&alto);
			tipoLog=parser.devolver_Tipo_Log();*/
			mapPersonajes =  appConfig.get_Config_Personajes();
			mapFondoPantalla =  appConfig.get_Config_FondosPantalla();
			mapNivel =  appConfig.get_Config_Nivel();
			nivelLog = 	appConfig.get_Config_NivelLog();
			anchoVentana = 	appConfig.get_Config_AnchoVentana();
			altoVentana = 	appConfig.get_Config_AltoVentana();


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

