#include <iostream>
#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/View.h"
#include "Configuracion.h"
#include "Logger/Logger.h"
#include "Cliente.h"
#include "Servidor/Servidor.h"
#define MAX_CLIENTES 2
/* nombre_ejecutable  nombre_archivo_configuracion niveldeDebug*/
int main(int argc, char* argv[]) {

	char* ip;
	char* puerto;

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
	model.getEquipoNro(0)->setJugadorActivo(0);
	model.getEquipoNro(1)->setJugadorActivo(0);


	if (strcmp(argv[1], "servidor") == 0) {
		puerto = argv[2];
		cout << "puerto: " << puerto << endl;
		Servidor server;
		server.SetModel(&model);
		server.IniciarServidor(MAX_CLIENTES, puerto);
	} else if (strcmp(argv[1], "cliente") == 0) {
		ip = argv[2];
		cout << "ip: " << ip << endl;
		puerto = argv[3];
		cout << "puerto: " << puerto << endl;
		cout << "ingrese su nombre:" << endl;
		string nombre;
		cin >> nombre;
		View view(&model);
		cout << "vista creada."<< endl;
		cout << "ingrese otra vez su nombre:" << endl;
		cin >> nombre;
		Controller controller(&model);
		cout << "controller creado."<< endl;
		Cliente cliente(&view);
		cout << "Cliente creado."<< endl;
		if (cliente.ConectarConServidor(ip, puerto) == -1)
			return -1;
		cout << "conectado con servidor."<< endl;
		//TODO menu de seleccion
		cliente.MenuDeSeleccion();
//		cliente.setVista(view);
		view.setEstadoCliente();

		cliente.lanzarHilosDelJuego();
		while (!controller.quitPressed()) {
			ComandoAlServidor comandoParaServidor;
			comandoParaServidor.comando = controller.processInputCliente();
			cliente.enviarComandoAServidor(comandoParaServidor);
			usleep(10000);
//			model.update();
//			view.render();
		}

		return 0;
	}
}

