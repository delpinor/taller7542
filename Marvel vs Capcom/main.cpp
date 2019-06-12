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
#include <signal.h>
/* nombre_ejecutable  nombre_archivo_configuracion niveldeDebug*/
/* Catch Signal Handler functio */
void signal_callback_handler(int signum){

        printf("Caught signal SIGPIPE %d\n",signum);
}
void ignore_sigpipe(void)
{

struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = SIG_IGN;
    act.sa_flags = SA_RESTART;
  sigaction(SIGPIPE, &act, NULL);

}

int main(int argc, char* argv[]) {
	struct sigaction act;
	    memset(&act, 0, sizeof(act));
	    act.sa_handler = SIG_IGN;
	    //act.sa_flags = SA_RESTART;
	  sigaction(SIGPIPE, &act, NULL);
	//sigaction(SIGPIPE, &(struct sigaction){SIG_IGN}, NULL);
	//ignore_sigpipe;
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

	char argConfig[] = "config.json";
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

	cout << "MAIN: La cantidad de mapPersonajes es " << mapPersonajes.size()
			<< " | " << TimeHelper::getStringLocalTimeNow() << endl;
	cout << "MAIN: La cantidad de jugadoresEquipo1 es "
			<< model.jugadoresEquipo1.size() << " | "
			<< TimeHelper::getStringLocalTimeNow() << endl;

	//seteo los jugadores en los equipos
	//set_equipos_with_jugador(int nroEquipo, int nroJugadorEquipo, int nroJugador)
	//OJO ACA, SI LO DESCOMENTO EL 3ER PARAMETRO TIENE QUE SER EL ENUM DE LOS PERSONAJES
	//	model.set_equipos_with_jugador(0, 0, 4);
	//	model.set_equipos_with_jugador(0, 1, 1);
	//	model.set_equipos_with_jugador(1, 0, 2);
	//	model.set_equipos_with_jugador(1, 1, 3);
	//
	//	//designo que jugadores van a estar activos
	//	model.inicializar();
	//	model.getEquipoNro(0)->setJugadorActivo(0);
	//	model.getEquipoNro(1)->setJugadorActivo(0);

	int num_jugadores = appConfig.get_NumJugadores();

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

		IDMENSAJE idMsg = LOGIN;

		Controller controller;
		controller.SetModel(&model);
		cout << "controller creado | " << TimeHelper::getStringLocalTimeNow()
				<< endl;

		ViewMenu viewMenu(0);
		cout << "Vista Menu creada | " << TimeHelper::getStringLocalTimeNow()
				<< endl;

		Conexion conexion;
		Cliente cliente(&viewMenu, &conexion);
		cout << "Cliente creado | " << TimeHelper::getStringLocalTimeNow()
				<< endl;

		cout << "conectado con servidor | "
				<< TimeHelper::getStringLocalTimeNow() << endl;
		std::string nombre_usuario;
		viewMenu.getNombre_usuario(nombre_usuario);

		if (cliente.ConectarConServidor(ip, puerto) == -1)
			return -1;

		strcpy(cliente.Usuario, nombre_usuario.c_str());
		send(conexion.getSocketCliente(), &idMsg, sizeof(idMsg), 0);
		send(conexion.getSocketCliente(), &cliente.Usuario, sizeof(cliente.Usuario),
				0);

		cliente.lanzarHilosDelJuego();
		cout << "Hilos del cliente lanzados | "
				<< TimeHelper::getStringLocalTimeNow() << endl;


		bool quitSeleccionMenu = false;
		bool primerSeleccion = true;

		while (!quitSeleccionMenu && !cliente.EstaFinalizadaSeleccionPersonaje()) {
			if (cliente.EstaIniciadaSeleccionPersonaje()) {
				//cout << "Ingresó en selección de personaje | "<< TimeHelper::getStringLocalTimeNow() << endl;
				viewMenu.TextoTitulo = "SELECCION DE PERSONAJE";

				int personajeSeleccionadoId = static_cast<int>(PERSONAJE::P_NA);
				bool personajeEstaConfirmado = false;
				viewMenu.handleEvent(&quitSeleccionMenu,
						&personajeSeleccionadoId, &personajeEstaConfirmado);

				DataSeleccionAlServidor unModelo;
				unModelo.personajeId = personajeSeleccionadoId;
				unModelo.confirmado = personajeEstaConfirmado;
				cliente.EnviarPing();
				if (personajeSeleccionadoId != -1) {
					cliente.enviarDataSeleccionAServidor(unModelo);
				}
				if (unModelo.confirmado && cliente.CantidadEquipo == 1) {
					viewMenu.TextoMensaje =
							"Elija su SEGUNDO personaje y presione la tecla ESPACIO";
					primerSeleccion = false;

				}
				if (primerSeleccion) {
					viewMenu.TextoMensaje =
							"Elija su personaje y presione la tecla ESPACIO";
				}
				//viewMenu.loadText();
			}
			viewMenu.render();
			usleep(18000);
		}
		viewMenu.close();

		if (quitSeleccionMenu) {
			return 1;
		}

		ModeloResultadoSeleccionPersonaje resultadoSeleccionPersonaje =
				cliente.ResultadoSeleccionPersonaje;
		for (int i = 0; i < resultadoSeleccionPersonaje.cantidadData; i++) {

			ModeloResultadoSeleccionItem item = resultadoSeleccionPersonaje.data[i];

			cout << "Equipo: " << item.equipo
					<< " | Numero Jugador: " << item.numeroJugador
					<< " | Personaje1: " << item.personaje1Id
					<< " | Personaje2: " << item.personaje2Id
					<< endl;


			if (item.cantidadPersonajes == 2) {
				model.set_equipos_with_jugador(item.equipo, 0,
						item.personaje1Id);
				model.set_equipos_with_jugador(item.equipo, 1,
						item.personaje2Id);
			} else {
				model.set_equipos_with_jugador(item.equipo, item.numeroJugador,
						item.personaje1Id);
			}
			//cout << "Seteo de personajes |  Equipo "<< it->equipo << " | JugadorEquipoId" << << TimeHelper::getStringLocalTimeNow() << endl;
		}
		model.inicializar();
		model.getEquipoNro(0)->setJugadorActivo(0);
		model.getEquipoNro(1)->setJugadorActivo(0);

		cout << "Finalizo el seteo de los Personajes en el modelo | " << TimeHelper::getStringLocalTimeNow() << endl;
		cliente.LanzarHiloPing();
		View view(&model);
		cliente.setVista(&view);
		// Habilito a recibir el modelo
		cliente.JuegoIniciado = true;
		cout << "vista creada." << endl;
		view.setEstadoCliente();
		cout << "EstadoCliente seteados." << endl;
		// Hilo conexion.
		cliente.PararHiloPing();
		cliente.LanzarHiloConexion();
		while (!controller.quitPressed()) {
			ComandoAlServidor comandoParaServidor;
			int comando = controller.processInputCliente();
			if (cliente.Titular) {
				comandoParaServidor.comando = comando;
			} else {
				comandoParaServidor.comando = 99;
			}
			cliente.enviarComandoAServidor(comandoParaServidor);
			model.updateCliente(cliente.esta_conectado());
			usleep(18000);
			view.render();
		}

		return 0;
	}
}
