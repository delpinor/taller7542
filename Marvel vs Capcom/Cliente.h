/*
 * Cliente.h
 *
 *  Created on: 9 may. 2019
 *      Author: maciel
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "Model/Model.h"
#include "Comunicacion/EstructuraDatos.h"
#include <queue>
#include <sys/socket.h>
#include <ctime>
#include "Comunicacion/Conexion.h"
#include "View/View.h"
#include "pthread.h"

class Cliente {
public:
	Cliente(View* vista, Conexion* conexion);
	int Equipo;
	bool Titular;
	char* IPServidor;
	char * Puerto;
	char Usuario[50];
	bool ServidorVivo = true;
	bool juegoCorriendo = true;
	bool Ping = false;

	void LanzarHiloConexion();
	int ConectarConServidor(char* hostname, char* puerto);
	void PushModeloEnCola(ModeloEstado modelo);
	ModeloEstado PopModeloDeCola();
	void actualizarModelo(ModeloEstado modelo);
	int recibirModeloDelServidor();
	void enviarComandoAServidor(ComandoAlServidor comando);
	void lanzarHilosDelJuego();
	void MenuDeSeleccion();
	bool esta_conectado();
	std::queue<ModeloEstado> getModeloCambios();

	//TODO ver como imlementar la verificación de conexion del lado del cliente
	void setTiempoUltimoMensajeRecibido(int tiempo);
	int getTiepoUltimoMensajeRecibido();
	//geters y seters
	Conexion* getConexion();
	void setCenexion(Conexion* conexion);
	View* getVista();
	void setVista(View* vista);
	virtual ~Cliente();

private:
	Conexion* conexion;
	View* vista;
	std::queue<ModeloEstado> ModeloCambios;
	int tiempoUltimoMensajeRecivido;

};

#endif /* CLIENTE_H_ */
