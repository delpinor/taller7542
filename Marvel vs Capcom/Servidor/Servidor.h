/*
 * GameServer.h
 *
 *  Created on: 9 may. 2019
 *      Author: delpinor
 */
#include "Partida.h"
#include "../Model/Model.h"
#include "../Comunicacion/EstructuraDatos.h"
#include "ConexionServidor.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../Helper/TimeHelper.h"

struct DatosHiloServidor {
	string usuario;
	int sock;
};
struct HiloConexion {
	bool ping;
	int sock;
	string usuario;
};

class Servidor {
private:
	Partida partida;
	ConexionServidor connServidor;
	Model model;
	//Controller controlador;
	int num_jugadores;
public:
	void SetModel(Model * model);
	int calcular_num_personajes(int orden_de_jugador);
	void LanzarHiloControl();
	void LanzarHiloLoggeo();
	void IniciarServidor(int maxClientes, char * puerto);
	void AceptarClientes(int maxClientes);
	void LanzarHiloControlSeleccionPersonajes();
	void LanzarHiloUpdateModelo();
	//virtual ~Funciones();
};


