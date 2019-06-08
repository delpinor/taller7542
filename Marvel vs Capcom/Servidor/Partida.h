#pragma once
#include <iostream>
#include <list>
#include <iterator>
#include <thread>
#include "../Model/Model.h"
#include "../Comunicacion/EstructuraDatos.h"
#include "../Controller/Controller.h"
#include "../View/View.h"
#include "../Enums/Personajes.h"
#define ANCHO_NIVEL 1040
#define ALTO_NIVEL 1080
using namespace std;
// Estructura de Cliente
struct ClienteConectado{
	int socket;
	pthread_t tid;
	string nombre;
	int equipo = 0;

	//indica si es 0,1. Su uso vale si tiene que seleccionar solo un personaje
	//va a dejar de usarse, manda el flag "titular"
	int numeroJugador;

	//Indica si es 1p, 2p, 3p,4p
	int numeroJugadorJuego;

	bool titular;
	int personajeId = static_cast<int>(PERSONAJE::P_NA);
	int personajeIdSuplente = static_cast<int>(PERSONAJE::P_NA);

	bool personajeConfirmado = false;
	bool personajeConfirmadoSuplente = false;
	bool dataPersonajesEnviada = false;
	int cantidadPersonajes = 0;
};
class Partida{
private:
	Model * modelo;
	Controller * controlador;
	SDL_Rect* camara;
	SDL_Rect camaraStatic;
	bool partidaIniciada = false;
	bool partidaFinalizada = false;
	unsigned int maximoJugadores;
	int cantEquipo0 = 0;
	int cantEquipo1 = 0;
	list<ClienteConectado> listaEspera;
	list<ClienteConectado> listaJugadores;
	list<ClienteConectado> listaDesconectados;
	bool seleccionPersonajesIniciada = false;
	bool seleccionPersonajesFinalizada = false;
	bool habilitadoEnvioPersonajes = false;
public:
	list<ClienteConectado> GetListaJugadores();
	list<ClienteConectado> GetListaEspera();
	list<ClienteConectado> GetListaJugadores(int equipo);
	ClienteConectado GetTitularJugando(int equipo);
	void SetComando(int equipo, int comando);
	void SetModelo(Model * model);
	void AjustarCamara();
	Controller * GetControlador();
	Model * GetModelo();
	ModeloEstado GetModeloEstado();
	void ActualizarModelo();
	void FinalizarPartida();
	void IniciarPartida();
	bool EquipoCompleto();
	bool Iniciada();
	bool Finalizada();
	bool EsClienteDesconectado(string nombre);
	bool EsClienteDesconectadoBySock(int sock);
	void SetMaximoJugadores(int max);
	void EliminarJugador(string nombre);
	void EliminarDesconectado(string nombre);
	void JugadorDesconectado(string nombre);
	void JuegaTitular(int equipo, ClienteConectado desconectado);
	void JuegaSuplente(int equipo);
	void AgregarCliente(ClienteConectado * cliente);
	ClienteConectado GetClienteEspera(string nombre);
	ClienteConectado GetClienteJugando(string nombre);
	ClienteConectado GetClienteDesconectado(string nombre);
	int GetCantidadJugando();
	int GetCantidadJugando(int equipo);
	int GetCantidadEnEspera(int equipo);
	int GetCantidadDesconectados();
	int GetCantidadEspera();
	bool TieneSuplente(int equipo);
	bool jugadorReconectado(int equipo);
	bool hayJugadorParaEquipo(int equipo);
	bool existeJugador(string nombre);
	void SwapPersonaje(int equipo);
	void SwapTitularSuplente(int equipo);
	void DetenerJugadores();
	string validarNombreUsuario(string nombreUsuario);
	int cantidadJugadoresConNombre(string nombre);

	ModeloSeleccion GetModeloSeleccion();
	void SetJugadoresPersonajeInicial();
	void IniciarSeleccionPersonajes();
	void FinalizarSeleccionPersonajes();
	bool IniciadaSeleccionPersonajes();
	bool FinalizadaSeleccionPersonajes();

	void HandleEventSeleccionPersonajes(string nombreJugador, DataSeleccionAlServidor *data);
	bool PersonajesSeleccionCompleta();
	bool PersonajesSeleccionCompletaSuplente();
	bool PersonajesSeleccionCompletaTitular();

	void SetPersonajes();
	bool EstaHabilitadoEnvioPersonajes();
	void HabilitarEnvioPersonajes();
	bool EstaEnviadaDataPersonajes();
	ModeloPersonajes GetModeloPersonajes();
	void SetDataPersonajesEnviada(string nombre);
	ModeloResultadoSeleccionPersonaje getResultadoSeleccionPersonaje();
};

