#include <iostream>
#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/View.h"
#include "Configuracion.h"
#include "Logger/Logger.h"
#include "Cliente.h"
#include "Servidor/Servidor.h"

/* nombre_ejecutable  nombre_archivo_configuracion niveldeDebug*/
int main(int argc, char* argv[]) {

	char* ip = argv[2];
	char* puerto = argv[3];

	LOGGER_NIVEL nivelLog = DEBUG;

	std::map<int, std::map<std::string, std::string> > mapPersonajes;
	std::map<int, std::map<std::string, std::string> > mapFondoPantalla;
	std::map<std::string, std::string> mapNivel;

	LOGGER_SALIDA salida = ARCHIVO;

	int anchoVentana, altoVentana;
	/*Se inicia el logger en modeo debug*/
	Logger::Inicio(nivelLog, salida);
	Logger::Log(nivelLog, "INICIO", "Iniciando el programa...");

	std::vector<string> *nombresPersonajes = new std::vector<string>(5);
	nombresPersonajes->push_back("captain america");
	nombresPersonajes->push_back("venom");
	nombresPersonajes->push_back("captain america black");
	nombresPersonajes->push_back("venom black");
	nombresPersonajes->push_back("spiderman");
	nombresPersonajes->push_back("default");

	Configuracion appConfig(NULL, nombresPersonajes);

	mapPersonajes = appConfig.get_Config_Personajes();
	mapFondoPantalla = appConfig.get_Config_FondosPantalla();
	altoVentana = appConfig.get_Config_AltoVentana();
	anchoVentana = appConfig.get_Config_AnchoVentana();
	nivelLog = appConfig.get_Config_NivelLog();

	/*  Verifico si se ingreso como segundo parametro el nivel de debug*/
//		if (argc > 2) {
//			std::string nivel(argv[2]);
//			if (nivel == "DEBUG") {
//				nivelLog = DEBUG;
//			} else if (nivel == "ERROR") {
//				nivelLog = ERROR;
//
//			} else if (nivel == "INFO") {
//				nivelLog = INFO;
//			}
//			Logger::Log(INFO,
//					"INICIO:: se cambia al nivel de log ingresado por linea de comandos",
//					argv[2]);
//		}
//		if (argc == 2) {
//			std::string nivel(argv[1]);
//			if (nivel == "DEBUG") {
//				nivelLog = DEBUG;
//			} else if (nivel == "ERROR") {
//				nivelLog = ERROR;
//
//			} else if (nivel == "INFO") {
//				nivelLog = INFO;
//			}
//			Logger::Log(DEBUG,
//					"INICIO:: se cambia al nivel de log ingresado por linea de comandos",
//					argv[1]);
//		}
	Logger::Cambiar_nivelLog(nivelLog);

	Model model;

	model.cargar_Tam_Pantalla(anchoVentana, altoVentana);

	model.CargarFondos(mapFondoPantalla);
	//metodo que carga los personajes ( jugador =personaje)
	model.cargar_Jugadores(mapPersonajes);
	//seteo los jugadores en los equipos
	//set_equipos_with_jugador(int nroEquipo, int nroJugadorEquipo, int nroJugador)
	model.set_equipos_with_jugador(0, 0, 0);
	model.set_equipos_with_jugador(0, 1, 1);
	model.set_equipos_with_jugador(1, 0, 2);
	model.set_equipos_with_jugador(1, 1, 3);
	//designo que jugadores van a estar activos
	model.inicializar();
	model.getEquipoNro(1)->setJugadorActivo(1);
	model.getEquipoNro(0)->setJugadorActivo(0);

	if (strcmp(argv[1], "server") == 0) {
		Servidor server;
		server.IniciarServidor(3, puerto);
		server.SetMode(model);
	} else if (strcmp(argv[1], "cliente") == 0) {

		View view(&model);
		Controller controller(&model);

		Cliente cliente;
		cliente.ConectarConServidor(ip, puerto);
		//TODO menu de seleccion
		cliente.MenuDeSeleccion();
		cliente.setVista(view);
		view.setEstadoCliente();

		cliente.lanzarHilosDelJuego();
		while (!controller.quitPressed()) {
			int comando = controller.processInputCliente();
			ComandoAlServidor comandoParaServidor;
			comandoParaServidor.comando = comando;
			cliente.enviarComandoAServidor(comandoParaServidor);
			usleep(10000);
//			model.update();
//			view.render();
		}

		return 0;
	}
}

