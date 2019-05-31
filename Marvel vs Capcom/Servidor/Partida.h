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
	int numeroJugador;
	//TODO : refactorizar para que solo quede el anterior
	int numeroJugadorJuego;
	bool titular;
	int personajeId = static_cast<int>(PERSONAJE::P_NA);
	bool personajeConfirmado = false;
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
	int GetCantidadDesconectados();
	int GetCantidadEspera();
	bool TieneSuplente(int equipo);

	ModeloSeleccion GetModeloSeleccion();
	ModeloSeleccion GetModeloSeleccionInicial();
	void IniciarSeleccionPersonajes();
	void FinalizarSeleccionPersonajes();
	bool IniciadaSeleccionPersonajes();
	bool FinalizadaSeleccionPersonajes();
	void HandleEventSeleccionPersonajes(string nombreJugador, DataSeleccionAlServidor *data);
	bool PersonajesSeleccionCompleta();
	void SetPersonajes();
	ModeloPersonajes GetModeloPersonajes();
};

