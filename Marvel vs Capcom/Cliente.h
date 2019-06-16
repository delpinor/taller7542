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
#include "View/ViewMenu.h"
#include "pthread.h"
#include "Helper/TimeHelper.h"
#include "Sonido.h"

class Cliente {
public:
	Cliente(ViewMenu* vistaMenu, Conexion* conexion);
	//Cliente(View* vista, Conexion* conexion);
	int Equipo;
	bool Titular;
	char* IPServidor;
	char * Puerto;
	char Usuario[50];
	bool ServidorVivo = true;
	bool JuegoIniciado = false;
	bool EnviarPingHilo = true;
	bool juegoCorriendo = true;
	bool Ping = false;
	int CantidadEquipo = 0;
	bool servidor_vivo=true;
	void LanzarHiloConexion();
	int ConectarConServidor(char* hostname, char* puerto);
	int NroJugador;
	bool seleccionPersonajeIniciada = false;
	bool seleccionPersonajeFinalizada = false;
	void PushModeloEnCola(ModeloEstado modelo);
	bool servidor_esta_vivo();
	ModeloEstado PopModeloDeCola();
	void actualizarModelo(ModeloEstado modelo);
	int recibirModeloDelServidor();
	void enviarComandoAServidor(ComandoAlServidor comando);
	void EnviarPing();
	void LanzarHiloPing();
	void PararHiloPing();
	void lanzarHilosDelJuego();
	void MenuDeSeleccion();
	bool esta_conectado();
	std::queue<ModeloEstado> getModeloCambios();
	void enviarDataSeleccionAServidor(DataSeleccionAlServidor data);
	void IniciarSeleccionPersonaje();
	void FinalizarSeleccionPersonaje();
	bool EstaIniciadaSeleccionPersonaje();
	bool EstaFinalizadaSeleccionPersonaje();
	ModeloResultadoSeleccionPersonaje ResultadoSeleccionPersonaje;

	//TODO ver como imlementar la verificación de conexion del lado del cliente
	void setTiempoUltimoMensajeRecibido(int tiempo);
	int getTiepoUltimoMensajeRecibido();
	//geters y seters
	Conexion* getConexion();
	void setCenexion(Conexion* conexion);
	View* getVista();
	void setVista(View* vista);

	void lanzar_musica_juego();

	virtual ~Cliente();

private:

	Conexion* conexion;
	View* vista;
	std::queue<ModeloEstado> ModeloCambios;
	int tiempoUltimoMensajeRecivido;
	ViewMenu* vistaMenu;

};

#endif /* CLIENTE_H_ */
