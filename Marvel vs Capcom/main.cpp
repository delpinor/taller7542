#include <iostream>
#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/View.h"
#include "Configuracion.h"
int main(int argc, char* argv[]) {
	int error;
	ParserConfig parser;
	//Configuracion appConfig("config.json");
	try{
		error=parser.parsear_archivo(argv[1]);

	}catch(Exception &e){
		std::cout<<e.what();
		return ERROR;
	}

			std::map< int, std::map<std::string, std::string> > mapPersonajes;
			std::map<int, std::map<std::string, std::string> > mapFondoPantalla;
			std::map<std::string, std::string> mapNivel;
			string nivelLog;
			int anchoVentana, altoVentana;


			error=parser.devolver_Map_Personajes(&mapPersonajes);
			error=parser.devolver_Map_Fondo( &mapFondoPantalla);
			error=parser.devolver_Tam_Imagen(&anchoVentana,&altoVentana);
			nivelLog=parser.devolver_Tipo_Log();
			/*
			mapPersonajes =  appConfig.get_Config_Personajes();
			mapFondoPantalla =  appConfig.get_Config_FondosPantalla();
			mapNivel =  appConfig.get_Config_Nivel();
			nivelLog = 	appConfig.get_Config_NivelLog();
			anchoVentana = 	appConfig.get_Config_AnchoVentana();
			altoVentana = 	appConfig.get_Config_AltoVentana();


*/
			for (map <int, map<string, string>>::iterator it = mapFondoPantalla.begin(); it != mapFondoPantalla.end(); ++it){
						map<string, string> &internal_map = it->second;
						cout << internal_map["orden"] << endl;
						cout << internal_map["rutaArchivoImagen"] << endl;
						cout << internal_map["zIndex"] << endl;
					}

			Model model;
			//metodo que carga los personales ( jugador =personaje)
			model.cargar_Jugadores(mapPersonajes);
			//metodo que setea los equipos
			// solo asigna dos personajes , uno para cada equipo
			model.set_Equipos();
			View view(&model);
			Controller controller(&model);

			while (!controller.quitPressed()) {
				controller.processInput();
				model.update();
				view.render();
			}

	return 0;
}

