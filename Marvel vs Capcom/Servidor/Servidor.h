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
struct DatosHiloServidor {
	string usuario;
	int sock;
};

class Servidor {
private:
	Partida partida;
	ConexionServidor connServidor;
public:
	void SetModel(Model * model);
	void LanzarHiloControl();
	void LanzarHiloLoggeo();
	void IniciarServidor(int maxJugadores, char * puerto);
	//virtual ~Funciones();
};


