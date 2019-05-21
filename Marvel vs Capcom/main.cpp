#include <iostream>
#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/View.h"
#include "Configuracion.h"
#include "Logger/Logger.h"
#include "Cliente.h"
#include "Servidor/Servidor.h"
#define MAX_CLIENTES 3
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
	nombresPersonajes->push_back("spiderman black");
	nombresPersonajes->push_back("chun li");
	nombresPersonajes->push_back("chun li black");
	nombresPersonajes->push_back("default");
	char * argConfig = "config.json";
	Configuracion appConfig(argConfig, nombresPersonajes);

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
		View view(&model);
		cout << "vista creada."<< endl;
		Controller controller;
		controller.SetModel(&model);
		cout << "controller creado."<< endl;
		Conexion conexion;
		Cliente cliente(&view, &conexion);
		cout << "Cliente creado."<< endl;
		if (cliente.ConectarConServidor(ip, puerto) == -1)
			return -1;
		cout << "conectado con servidor."<< endl;

		// Envio de usuario
		JugadorLogin loginUsuario;
		IDMENSAJE idMsg = LOGIN;
		// Capturo datos del jugador
		char nombre[50];
		cout << "Usuario:";
		cin >> nombre;
		strcpy(loginUsuario.usuario, nombre);

		send(conexion.getSocketCliente(), &idMsg, sizeof(idMsg),0);
		send(conexion.getSocketCliente(), &loginUsuario, sizeof(loginUsuario),0);

		//TODO menu de seleccion
		cliente.MenuDeSeleccion();
//		cout << "pasó el menu de selección."<< endl;
//		cliente.setVista(view);
		view.setEstadoCliente();
		cout << "EstadoCliente seteados."<< endl;
		cliente.lanzarHilosDelJuego();
		cout << "Hilos del cliente lanzados."<< endl;
		while (!controller.quitPressed()) {
			ComandoAlServidor comandoParaServidor;
			comandoParaServidor.comando = controller.processInputCliente();
			if ((comandoParaServidor.comando != 99) && cliente.Titular){
				cliente.enviarComandoAServidor(comandoParaServidor);
			}
			usleep(50);
			model.update();
			view.render();
		}

		return 0;
	}
}

