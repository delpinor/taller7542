#include <iostream>
#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/View.h"
#include "View/ViewMenu.h"
#include "Configuracion.h"
#include "Logger/Logger.h"
#include "Cliente.h"
#include "Servidor/Servidor.h"
#include "Helper/TimeHelper.h"

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

	char  argConfig[] = "config.json";
	Configuracion appConfig(argConfig);

	mapPersonajes = appConfig.get_Config_Personajes();
	mapFondoPantalla = appConfig.get_Config_FondosPantalla();
	altoVentana = appConfig.get_Config_AltoVentana();
	anchoVentana = appConfig.get_Config_AnchoVentana();
	nivelLog = appConfig.get_Config_NivelLog();


	Logger::Cambiar_nivelLog(nivelLog);

	Model model;

	model.cargar_Tam_Pantalla(anchoVentana, altoVentana);

	model.CargarFondos(mapFondoPantalla);
	//metodo que carga los personajes ( jugador =personaje)
	model.cargar_Jugadores(mapPersonajes);

	cout << "MAIN: La cantidad de mapPersonajes es "<< mapPersonajes.size() << " | "  << TimeHelper::getStringLocalTimeNow() << endl;
	cout << "MAIN: La cantidad de jugadoresEquipo1 es "<< model.jugadoresEquipo1.size() << " | "  << TimeHelper::getStringLocalTimeNow() << endl;

	//seteo los jugadores en los equipos
	//set_equipos_with_jugador(int nroEquipo, int nroJugadorEquipo, int nroJugador)
	//OJO ACA, SI LO DESCOMENTO EL 3ER PARAMETRO TIENE QUE SER EL ENUM DE LOS PERSONAJES
	//model.set_equipos_with_jugador(0, 0, 0);
//	model.set_equipos_with_jugador(0, 1, 1);
//	model.set_equipos_with_jugador(1, 0, 2);
//	model.set_equipos_with_jugador(1, 1, 3);

	//designo que jugadores van a estar activos
//	model.inicializar();
//	model.getEquipoNro(0)->setJugadorActivo(0);
//	model.getEquipoNro(1)->setJugadorActivo(0);

	int num_jugadores= appConfig.get_NumJugadores();

	if (strcmp(argv[1], "servidor") == 0) {
		puerto = argv[2];
		cout << "puerto: " << puerto << endl;
		Servidor server;
		server.SetModel(&model);
		server.IniciarServidor(num_jugadores, puerto);
	} else if (strcmp(argv[1], "cliente") == 0) {
		ip = argv[2];
		cout << "ip: " << ip << endl;

		puerto = argv[3];
		cout << "puerto: " << puerto << endl;

		Controller controller;
		controller.SetModel(&model);
		cout << "controller creado | "<< TimeHelper::getStringLocalTimeNow() << endl;

		ViewMenu viewMenu(0);
		cout << "Vista Menu creada | "<< TimeHelper::getStringLocalTimeNow() << endl;

		Conexion conexion;
		Cliente cliente(&viewMenu, &conexion);
		cout << "Cliente creado | "<< TimeHelper::getStringLocalTimeNow() << endl;
		if (cliente.ConectarConServidor(ip, puerto) == -1)
			return -1;
		cout << "conectado con servidor | "<< TimeHelper::getStringLocalTimeNow() << endl;

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

		cliente.lanzarHilosDelJuego();
		cout << "Hilos del cliente lanzados | "<< TimeHelper::getStringLocalTimeNow() << endl;

		bool quitSeleccionMenu = false;
		while (!quitSeleccionMenu && !cliente.EstaFinalizadaSeleccionPersonaje()) {

			if(cliente.EstaIniciadaSeleccionPersonaje()){
				cout << "Ingreso en selección de personaje | "<< TimeHelper::getStringLocalTimeNow() << endl;

//				int personajeSeleccionadoId = static_cast<int>(PERSONAJE::P_NA);
//				bool personajeEstaConfirmado = false;
//				viewMenu.handleEvent(&quitSeleccionMenu, &personajeSeleccionadoId, &personajeEstaConfirmado);
//
//				DataSeleccionAlServidor unModelo;
//				unModelo.personajeId = personajeSeleccionadoId;
//				unModelo.confirmado = personajeEstaConfirmado;
//				cliente.enviarDataSeleccionAServidor(unModelo);
//
//				viewMenu.render();
			}
			usleep(50);
		}







//		View view(&model);
//		cout << "vista creada."<< endl;
//
//		view.setEstadoCliente();
//		cout << "EstadoCliente seteados."<< endl;
//
//		ComandoAlServidor comandoDefault;
//		comandoDefault.comando = 7; //PARAR
//		while (!controller.quitPressed()) {
//			ComandoAlServidor comandoParaServidor;
//			if (cliente.Titular)
//				comandoParaServidor.comando = controller.processInputCliente();
//			else
//				comandoParaServidor.comando = 99;
//			cliente.enviarComandoAServidor(comandoParaServidor);
//			usleep(50);
//			model.updateCliente();
//			view.render();
//		}

		return 0;
	}
}
