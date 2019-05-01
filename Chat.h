#ifndef CHAT_H_
#define CHAT_H_

#include "Comunicacion.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>

class Chat {
public:
	Comunicacion servidor;
	std::vector<Comunicacion> conexiones;
	std::queue<char*> mensajes;
//	std::vector<std::string> nombres;
	int InitServidor(const char* puerto_numero, int num_clientes_espera);
	int InitCliente(char *nom_servidor, const char* puerto_num);
	void GestionaConexiones();
	void RecepcionMensajes1();
	void RecepcionMensajes2();
	void RecepcionMensajesCliente();
	void EnviarMensajesAClientes();
	int enviarMensaje(char* mensaje, int tam_mensaje);
};

#endif /* CHAT_H_ */
