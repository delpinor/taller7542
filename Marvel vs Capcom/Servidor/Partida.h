#pragma once
#include <iostream>
#include <list>
#include <iterator>
#include <thread>
#include "../Model/Model.h"
#include "../Comunicacion/EstructuraDatos.h"
#include "../Controller/Controller.h"
using namespace std;
// Estructura de Cliente
struct ClienteConectado{
	int socket;
	pthread_t tid;
	string nombre;
	int equipo = 0;
	int numeroJugador;
	bool titular;
};
class Partida{
private:
	Model * modelo;
	Controller * controlador;
	bool partidaIniciada = false;
	bool partidaFinalizada = false;
	unsigned int maximoJugadores;
	int cantEquipo0 = 0;
	int cantEquipo1 = 0;
	list<ClienteConectado> listaEspera;
	list<ClienteConectado> listaJugadores;
	list<ClienteConectado> listaDesconectados;
public:
	list<ClienteConectado> GetListaJugadores();
	list<ClienteConectado> GetListaEspera();
	list<ClienteConectado> GetListaJugadores(int equipo);
	ClienteConectado GetTitularJugando(int equipo);
	void SetComando(int equipo, int comando);
	void SetModelo(Model * model);
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


};

