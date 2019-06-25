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
#include "Sonido.h"


int main(int argc, char* argv[]) {
	//ignore_sigpipe;
	struct sigaction act;
	    memset(&act, 0, sizeof(act));
	    act.sa_handler = SIG_IGN;
	    //act.sa_flags = SA_RESTART;
	  sigaction(SIGPIPE, &act, NULL);

	char* ip;
	char* puerto;

	LOGGER_NIVEL nivelLog = DEBUG;

	std::map<int, std::map<std::string, std::string> > mapPersonajes;
	std::map<int, std::map<std::string, std::string> > mapFondoPantalla;
	std::map<std::string, std::string> mapNivel;
	std::map<std::string, std::string> mapBatalla;

	LOGGER_SALIDA salida = ARCHIVO;

	int anchoVentana, altoVentana, tiempoBatalla, cantidadBatallas;
	bool modoTest;
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
	tiempoBatalla = appConfig.get_Config_TiempoBatalla();
	cantidadBatallas = appConfig.get_Config_CantidadBatallas();
	modoTest = appConfig.get_Config_ModoTest();
	//mapBatalla = appConfig.get_Config_Batalla();

	Logger::Cambiar_nivelLog(nivelLog);

	Model model;

	model.cargar_Tam_Pantalla(anchoVentana, altoVentana);

	model.CargarFondos(mapFondoPantalla);
	//metodo que carga los personajes ( jugador =personaje)
	model.cargar_Jugadores(mapPersonajes, modoTest);

	cout << "MAIN: La cantidad de mapPersonajes es " << mapPersonajes.size()
			<< " | " << TimeHelper::getStringLocalTimeNow() << endl;
	cout << "MAIN: La cantidad de jugadoresEquipo1 es "
			<< model.jugadoresEquipo1.size() << " | "
			<< TimeHelper::getStringLocalTimeNow() << endl;



	int num_jugadores = appConfig.get_NumJugadores();

	if (strcmp(argv[1], "servidor") == 0) {
		puerto = argv[2];
		cout << "puerto: " << puerto << endl;
		Servidor server;
		server.SetModel(&model);
//		int cantidad = atoi((mapRound["cantidad"]).c_str());
//			int tiempo = atoi((mapRound["tiempo"]).c_str());
		server.SetConfiguracion(tiempoBatalla, cantidadBatallas, modoTest);
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

		/* Cargo la musica de espera, la de seleccion y la del juego*/
		bool success;

		Sonido sonido_espera(0);

		success=sonido_espera.init();
		if (!success){
			return -1;

		}else{
				sonido_espera.loadMedia("Sonidos/01-opening.mp3");
		}

		Sonido sonido_seleccion(1);
				 //success=sonido_seleccion.init();
				if (!success){
						return -1;

				}else{

				sonido_seleccion.loadMedia("Sonidos/02-player-select.mp3");
				}
		Sonido sonido_juego(1);
						 success=sonido_juego.init();
						if (!success){
								return -1;

						}else{
									sonido_juego.loadMedia("Sonidos/05-theme-of-captain-america.mp3");
		}


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
		IDMENSAJE idMsg2;
		int numError = recv(conexion.getSocketCliente(), &idMsg2, sizeof(idMsg2), 0);
			if (idMsg2 == ACEPTADO) {
				cout<<"Aceptado \n";

				}else{

					cout<<"PARTIDA COMPLETA \n";
					return -1;
				}
		//reproduce la musica de espera
		sonido_espera.reproducir_sonido();

		cliente.lanzarHilosDelJuego();
		cout << "Hilos del cliente lanzados | "
				<< TimeHelper::getStringLocalTimeNow() << endl;


		bool quitSeleccionMenu = false;
		bool primerSeleccion = true;

		//variable para indicar el cambio de musica desde la de seleccion a la de espera
		bool cambiar_sonido=true;

		while (!quitSeleccionMenu && !cliente.EstaFinalizadaSeleccionPersonaje()) {
			if (cliente.EstaIniciadaSeleccionPersonaje()) {
				if (cliente.EstaIniciadaSeleccionPersonaje() && cambiar_sonido){
									sonido_espera.parar_sonido();
									sonido_seleccion.reproducir_sonido();
									cambiar_sonido=false;
				}

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
					viewMenu.MostrarMensaje("Elija su SEGUNDO personaje y presione la tecla ESPACIO");
				}
				if(primerSeleccion){
					viewMenu.MostrarMensaje("Elija su personaje y presione la tecla ESPACIO");
					primerSeleccion =  false;
				}
			}
			viewMenu.render();
			usleep(18000);
		}
		sonido_seleccion.parar_sonido();
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
		// Enviar confirmacion de carga.
		cliente.EnviarConfirmacion();
		//reproduzco sonido del juego
		cliente.LanzarHiloConexion();
		sonido_juego.reproducir_sonido();
		while (!controller.quitPressed()){ //&& !cliente.JuegoFinalizado) {
			if(!cliente.servidor_esta_vivo()){
				return -1;
			}
			ComandoAlServidor comandoParaServidor;
			int comando = controller.processInputCliente();
			if (cliente.Titular) {
				comandoParaServidor.comando = comando;
			} else {
				comandoParaServidor.comando = 99;
			}
			if(!cliente.JuegoFinalizado){
				cliente.enviarComandoAServidor(comandoParaServidor);
			}
			model.updateCliente(cliente.esta_conectado());
			usleep(18000);
			view.render();
		}

		return 0;
	}
}
