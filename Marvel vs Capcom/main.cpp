#include <iostream>
#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/View.h"
#include "Configuracion.h"
#include "Logger/Logger.h"

int main(int argc, char* argv[]) {

	std::map< int, std::map<std::string, std::string> > mapPersonajes;
	std::map<int, std::map<std::string, std::string> > mapFondoPantalla;
	std::map<std::string, std::string> mapNivel;
	LOGGER_NIVEL nivelLog;
	int anchoVentana, altoVentana;


	try {
		std::vector<string> *nombresPersonajes = new std::vector<string>(3);
		nombresPersonajes->push_back("captain america");
		nombresPersonajes->push_back("venom");
		nombresPersonajes->push_back("default");
		Configuracion appConfig(argv[1], nombresPersonajes);

		mapPersonajes = appConfig.get_Config_Personajes();
		mapFondoPantalla = appConfig.get_Config_FondosPantalla();
		altoVentana = appConfig.get_Config_AltoVentana();
		anchoVentana = appConfig.get_Config_AnchoVentana();
		nivelLog=appConfig.get_Config_NivelLog();

	} catch (Exception &e) {
		std::cout<<e.what();
		return ERROR;
	}

	Logger::Inicio(nivelLog, LOGGER_SALIDA::CONSOLA);
	Logger::Log(nivelLog, "INICIO", "Iniciando el programa...");
	//Logger::Inicio(LOGGER_NIVEL::DEBUG, LOGGER_SALIDA::CONSOLA);
	//Logger::Log(LOGGER_NIVEL::INFO, "INICIO","Iniciando el programa...");

	Model model;

	model.cargar_Tam_Pantalla(anchoVentana, altoVentana);

	model.CargarFondos(mapFondoPantalla);
	//metodo que carga los personajes ( jugador =personaje)
	model.cargar_Jugadores(mapPersonajes);
	//seteo los jugadores en los equipos
	model.set_equipos_with_jugador(0, 0, 0);
	model.set_equipos_with_jugador(0, 1, 1);
	model.set_equipos_with_jugador(1, 0, 2);
	model.set_equipos_with_jugador(1, 1, 3);
	//designo que jugadores van a estar activos
	model.inicializar();
	model.getEquipoNro(1)->setJugadorActivo(1);
	model.getEquipoNro(0)->setJugadorActivo(0);
	View view(&model);
	Controller controller(&model);
	while (!controller.quitPressed()) {
		controller.processInput();
		model.update();
		view.render();
	}

	return 0;
}

