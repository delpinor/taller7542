/*
 * Cliente.cpp
 *
 *  Created on: 9 may. 2019
 *      Author: maciel
 */
#include "Cliente.h"

pthread_mutex_t mutexx;
bool servidor_vivo=true;

// Estructura para enviar al hilo.
struct DatosHiloCliente {
	Model * model;
	int sock;
};

//hilos a lanzar por cada cliente

//éste hilo va a escuchar lo que el servidor envíe
//va a insertar lo el modelo que el servidor manda en una cola
//y va a guardar el tiempo en que recibió el ultimo mensaje para saber si sigue conectado al servidor
void * hilo_escucha(void * cliente) {
	cout << "HILO ESCUCHA lanzado." << endl;
	Cliente* p = (Cliente*) cliente;
	while (servidor_vivo) {
		//		cout << "adentro del while de escucha." << endl;
		p->recibirModeloDelServidor();
		usleep(10);
		if (!p->ServidorVivo) {
			cout << "Muere el HILO ESCUCHA porque el ServidorVivo es FALSO" << endl;
			pthread_exit(0);
			break;
		}
	}
}
bool Cliente::servidor_esta_vivo(){
	return servidor_vivo;
}
void * hilo_ping(void * cliente) {
	Cliente* p = (Cliente*) cliente;
	while (servidor_vivo) {
		IDMENSAJE idMsg = PING;
		send(p->getConexion()->getSocketCliente(), &idMsg, sizeof(idMsg), 0);
		if (!p->EnviarPingHilo) {
			pthread_exit(NULL);
			break;
		}
		usleep(18000);
	}
}
void * hilo_conexion(void * cliente) {
	Cliente* p = (Cliente*) cliente;
	while (1) {
		p->Ping = false;
		sleep(2);
		if (!p->Ping) {
			p->ServidorVivo = false;
			p->getConexion()->Cerrar();
			cout << "Falla en la comunicacion. Intentando reconectar..." << endl;
			while(!p->ServidorVivo){
				sleep(2);
				if (p->getConexion()->Reconectar() != -1) {
					JugadorLogin loginUsuario;
					IDMENSAJE idMsg = LOGIN;
					strcpy(loginUsuario.usuario, p->Usuario);
					send(p->getConexion()->getSocketCliente(), &idMsg,
							sizeof(idMsg), 0);
					send(p->getConexion()->getSocketCliente(), &loginUsuario,
							sizeof(loginUsuario), 0);
					p->lanzarHilosDelJuego();
					p->LanzarHiloConexion();
					p->ServidorVivo = true;
					pthread_exit(0);
					break;
				}
			}
		}
	}
}

Cliente::Cliente(ViewMenu* vistaMenu, Conexion* conexion) {
	cout << "creando cliente." << endl;
	this->vistaMenu = vistaMenu;
	this->conexion = conexion;
}
//Cliente::Cliente(View* vista, Conexion* conexion) {
//	cout << "creando cliente." << endl;
//	this->vista = vista;
//	this->conexion = conexion;
//}

void Cliente::actualizarModelo(ModeloEstado modelo) {
	pthread_mutex_lock(&mutexx);

	this->getVista()->model->equipos[0]->setJugadorActivo(modelo.activoEquipo1);
	this->getVista()->model->equipos[1]->setJugadorActivo(modelo.activoEquipo2);

	this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaActivo(
			modelo.jugadoresEquipo1.isActivo);
	this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaActivo(
			modelo.jugadoresEquipo1.isAgachado);
	this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaActivo(
			modelo.jugadoresEquipo1.isCambiandoPersonaje);
	this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setPosX(
			modelo.jugadoresEquipo1.posX);
	this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setPosY(
			modelo.jugadoresEquipo1.posY);
	this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setVelocidadX(
			modelo.jugadoresEquipo1.velX);
	this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setVelocidadY(
			modelo.jugadoresEquipo1.velY);

	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaActivo(
			modelo.jugadoresEquipo2.isActivo);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaActivo(
			modelo.jugadoresEquipo2.isAgachado);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaActivo(
			modelo.jugadoresEquipo2.isCambiandoPersonaje);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setPosX(
			modelo.jugadoresEquipo2.posX);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setPosY(
			modelo.jugadoresEquipo2.posY);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setVelocidadX(
			modelo.jugadoresEquipo2.velX);
	this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setVelocidadY(
			modelo.jugadoresEquipo2.velY);

	this->getVista()->getCamara()->x = modelo.camara.posX;
	this->getVista()->getCamara()->y = modelo.camara.posY;
	pthread_mutex_unlock(&mutexx);
}

bool Cliente::esta_conectado() {

	return (this->ServidorVivo);
}
void Cliente::LanzarHiloPing(){
	pthread_t thid_hilo_ping;
	pthread_create(&thid_hilo_ping, NULL, hilo_ping, this);
	pthread_detach(thid_hilo_ping);
}
void Cliente::PararHiloPing(){
	this->EnviarPingHilo = false;
}
int Cliente::ConectarConServidor(char* hostname, char* puerto) {
	//IPServidor = ip;
	Puerto = puerto;
	cout << "conectando con servidor en ip: " << hostname << " y en puerto: "
			<< puerto << endl;
	int error = this->getConexion()->conectarConServidor(hostname, puerto);
	if (error == -1) {
		cout << "ERROR conectando con el servidor :(" << endl;
		return -1;
	}
	cout << "conectando con el servidor!!" << endl;
	return 0;
}

void Cliente::enviarComandoAServidor(ComandoAlServidor comando) {
	if (this->ServidorVivo) {
		IDMENSAJE idComando = COMANDO;
		IDMENSAJE idPing = PING;
		send(this->getConexion()->getSocketCliente(), &idPing, sizeof(idPing), MSG_NOSIGNAL);
		send(this->getConexion()->getSocketCliente(), &idComando, sizeof(idComando),MSG_NOSIGNAL);
		send(this->getConexion()->getSocketCliente(), &comando, sizeof(comando),	MSG_NOSIGNAL);
	}
}
void Cliente::EnviarPing(){
	IDMENSAJE idCabecera = PING;
	send(this->getConexion()->getSocketCliente(), &idCabecera, sizeof(idCabecera), MSG_NOSIGNAL);
}
void Cliente::EnviarConfirmacion(){
	IDMENSAJE idCabecera = CARGACOMPLETA;
	send(this->getConexion()->getSocketCliente(), &idCabecera, sizeof(idCabecera), MSG_NOSIGNAL);
	cout << "Enviado confirmacion..." << endl;
}
void Cliente::enviarDataSeleccionAServidor(DataSeleccionAlServidor data) {

	int error = 0;
	IDMENSAJE com = DATASELECCION;
	error = send(this->getConexion()->getSocketCliente(), &com, sizeof(com),
			MSG_NOSIGNAL);
	error = send(this->getConexion()->getSocketCliente(), &data, sizeof(data),
			MSG_NOSIGNAL);
}
int Cliente::recibirModeloDelServidor() {
	IDMENSAJE idMsg;
	int errorRecv = recv(this->getConexion()->getSocketCliente(), &idMsg, sizeof(idMsg), 0);
	if (errorRecv > 0) {
		//-------->Recibe PING
		if ((idMsg == PING)) {
			//			cout << "Ping recibido..." << endl;
			this->Ping = true;
			// Respondo el ping
		}
		//-------->Recibe EQUIPO
		if (idMsg == EQUIPO) {
			ClienteEquipo unClienteEquipo;
			recv(this->getConexion()->getSocketCliente(), &unClienteEquipo,	sizeof(unClienteEquipo), 0);
			pthread_mutex_lock(&mutexx);
			Titular = unClienteEquipo.titular;
			Equipo = unClienteEquipo.equipo;
			NroJugador = unClienteEquipo.nroJugador;
			CantidadEquipo = unClienteEquipo.cantidadEquipo;

			this->vistaMenu->setNroJugadorLocal(this->NroJugador);
			pthread_mutex_unlock(&mutexx);

		}

		//-------->Recibe COMPLETO
		if (idMsg == COMPLETO) {
			this->juegoCorriendo = false;
			servidor_vivo=false;
//			this->getConexion()->Cerrar();

			//			this->getVista()->CajaMensaje("Equipos",
			//					"Juego iniciado. No hay lugar");
		}
		if (idMsg ==SERVIDORMUERTO) {
					cout << "SERVIDOR MUERTO" <<endl;
					servidor_vivo=false;
					this->servidor_vivo=false;
					SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
					                         "SERVIDOR CERRADO",
					                         "JUEGO FINALIZADO",
					                         NULL);

							this->juegoCorriendo = false;
							this->getConexion()->Cerrar();

		}

		//-------->Recibe JUEGO INICIADO
		if (idMsg == JUEGOINICIADO){
			ModeloResultadoSeleccionPersonaje unModelo;
			recv(this->getConexion()->getSocketCliente(), &unModelo, sizeof(unModelo), 0);
			this->FinalizarSeleccionPersonaje();
			this->ResultadoSeleccionPersonaje = unModelo;
		}

		//-------->Recibe JUEGO FINALIZADO
		if (idMsg == JUEGOFINALIZADO){
			pthread_mutex_lock(&mutexx);
			this->JuegoFinalizado = true;
			pthread_mutex_unlock(&mutexx);
		}

		//-------->Recibe MODELO
		if (idMsg == MODELO && this->JuegoIniciado) {
			ModeloEstado unModelo;
			recv(this->getConexion()->getSocketCliente(), &unModelo,
					sizeof(unModelo), 0);
			pthread_mutex_lock(&mutexx);
			//actualizarModelo(unModelo);
			//this->PushModeloEnCola(unModelo);
			this->getVista()->model->camara->x = unModelo.camara.posX;
			this->getVista()->model->camara->y = unModelo.camara.posY;

			if (this->getVista()->model->equipos[0]->nroJugadorActivo
					!= unModelo.activoEquipo1) {
				this->getVista()->model->equipos[0]->setJugadorActivo(
						unModelo.activoEquipo1);
			}
			if (this->getVista()->model->equipos[1]->nroJugadorActivo
					!= unModelo.activoEquipo2) {
				this->getVista()->model->equipos[1]->setJugadorActivo(
						unModelo.activoEquipo2);
			}
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setPosX(
					unModelo.jugadoresEquipo1.posX);
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setPosY(
					unModelo.jugadoresEquipo1.posY);
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setVelocidadX(
					unModelo.jugadoresEquipo1.velX);
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setVelocidadY(
					unModelo.jugadoresEquipo1.velY);
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaActivo(
					unModelo.jugadoresEquipo1.isActivo);
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaAgachado(
					unModelo.jugadoresEquipo1.isAgachado);
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaCambiandoPersonaje(
					unModelo.jugadoresEquipo1.isCambiandoPersonaje);
			this->getVista()->model->equipos[0]->getJugadorActivo()->estado->setEstaSaltando(
					unModelo.jugadoresEquipo1.isSaltando);
			if (unModelo.jugadoresEquipo1.tipoGolpe != TIPO_GOLPE::NADA &&
					this->getVista()->model->equipos[0]->getJugadorActivo()->getTipoGolpe() == TIPO_GOLPE::NADA){
				cout << "Jugador 1 esta pegando :  " << unModelo.jugadoresEquipo1.tipoGolpe <<endl;
				this->getVista()->model->equipos[0]->getJugadorActivo()->setTipoGolpe(
					unModelo.jugadoresEquipo1.tipoGolpe);
				this->getVista()->model->equipos[0]->getJugadorActivo()->setIniciarGolpe(true);
			}

			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setPosX(
					unModelo.jugadoresEquipo2.posX);
			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setPosY(
					unModelo.jugadoresEquipo2.posY);
			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setVelocidadX(
					unModelo.jugadoresEquipo2.velX);
			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setVelocidadY(
					unModelo.jugadoresEquipo2.velY);
			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaActivo(
					unModelo.jugadoresEquipo2.isActivo);
			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaAgachado(
					unModelo.jugadoresEquipo2.isAgachado);
			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaCambiandoPersonaje(
					unModelo.jugadoresEquipo2.isCambiandoPersonaje);
			this->getVista()->model->equipos[1]->getJugadorActivo()->estado->setEstaSaltando(
					unModelo.jugadoresEquipo2.isSaltando);
			if (unModelo.jugadoresEquipo2.tipoGolpe != TIPO_GOLPE::NADA &&
					this->getVista()->model->equipos[1]->getJugadorActivo()->getTipoGolpe() == TIPO_GOLPE::NADA){
				cout << "Jugador 2 esta pegando:  " << unModelo.jugadoresEquipo2.tipoGolpe <<endl;
				this->getVista()->model->equipos[1]->getJugadorActivo()->setTipoGolpe(
					unModelo.jugadoresEquipo2.tipoGolpe);
				this->getVista()->model->equipos[1]->getJugadorActivo()->setIniciarGolpe(true);
			}

			this->getVista()->model->SetTiempoJuego(unModelo.tiempo);
			pthread_mutex_unlock(&mutexx);
		}
		//-------->Datos IGAME
		if (idMsg == INGAME && this->JuegoIniciado) {
			ModeloInGame inGame;
			recv(this->getConexion()->getSocketCliente(), &inGame, sizeof(inGame), 0);
			this->getVista()->model->SetTiempoJuego(inGame.tiempo);

			this->getVista()->model->TipoMensaje = inGame.tipoMensaje;
			this->getVista()->model->TextoMensaje = inGame.mensaje;


			this->getVista()->model->getEquipoNro(0)->getJugadorNro(0)->SetVida(inGame.personajesEquipo0[0].vida);
			this->getVista()->model->getEquipoNro(0)->getJugadorNro(1)->SetVida(inGame.personajesEquipo0[1].vida);

			this->getVista()->model->getEquipoNro(1)->getJugadorNro(0)->SetVida(inGame.personajesEquipo1[0].vida);
			this->getVista()->model->getEquipoNro(1)->getJugadorNro(1)->SetVida(inGame.personajesEquipo1[1].vida);

			cout << "Resultados Equipo0: Cantidad: " << inGame.resultadoEquipo0.cantidadResultados << endl;
			for(int i = 0; i < inGame.resultadoEquipo0.cantidadResultados; i++){
				cout << "Equipo0: Round: " << inGame.resultadoEquipo0.NrosBatallasGanadas[i] << endl;
			}
			cout << "Resultados Equipo1: Cantidad: " << inGame.resultadoEquipo1.cantidadResultados << endl;
			for(int i = 0; i < inGame.resultadoEquipo1.cantidadResultados; i++){
				cout << "Equipo1: Round: " << inGame.resultadoEquipo1.NrosBatallasGanadas[i] << endl;
			}
		}

		//-------->Recibe DATA PERSONAJES
		if (idMsg == DATAPERSONAJES) {
			cout << "CLIENTE - recibirModeloDelServidor: Recibiendo DATAPERSONAJES | "<< TimeHelper::getStringLocalTimeNow() << endl;

			ModeloPersonajes unModelo;
			recv(this->getConexion()->getSocketCliente(), &unModelo,
					sizeof(unModelo), 0);
			pthread_mutex_lock(&mutexx);
			this->vistaMenu->setPersonajes(&unModelo);
			pthread_mutex_unlock(&mutexx);

			for(int i = 0; i < unModelo.cantidadPersonajes ; i++){
				cout << "PersonajeId: " << unModelo.idsPersonajes[i] << endl;
			}

			//cout << "CLIENTE - recibirModeloDelServidor: DATAPERSONAJES la lista de personajes tiene "<< unModelo.idsPersonajes.size() << " | "  << TimeHelper::getStringLocalTimeNow() << endl;
			cout << "CLIENTE - recibirModeloDelServidor: DATAPERSONAJES Recibido | "<< TimeHelper::getStringLocalTimeNow() << endl;
		}

		//-------->Recibe MODELO SELECCION
		if (idMsg == MODELOSELECCION) {
			//cout << "CLIENTE - recibirModeloDelServidor: Recibiendo MODELOSELECCION | "<< TimeHelper::getStringLocalTimeNow() << endl;

			ModeloSeleccion unModelo;

			recv(this->getConexion()->getSocketCliente(), &unModelo,sizeof(unModelo), 0);

			pthread_mutex_lock(&mutexx);
			this->vistaMenu->setModeloSeleccion(unModelo);

			if (!this->EstaIniciadaSeleccionPersonaje()) {
				//cout << "CLIENTE - recibirModeloDelServidor: Iniciando Seleccion Personaje | "<< TimeHelper::getStringLocalTimeNow() << endl;
				this->IniciarSeleccionPersonaje();
				//cout << "CLIENTE - recibirModeloDelServidor: Iniciando Seleccion Personaje HECHO | "<< TimeHelper::getStringLocalTimeNow() << endl;
			}
			pthread_mutex_unlock(&mutexx);

			//cout << "CLIENTE - recibirModeloDelServidor: MODELOSELECCION Recibido | "<< TimeHelper::getStringLocalTimeNow() << endl;
		}
	}
	return NULL;

}
void Cliente::lanzarHilosDelJuego() {
	cout << "por lanzar hilos del cliente" << endl;
	pthread_t thid_hilo_escucha;
	//	pthread_t thid_hilo_render;
	pthread_create(&thid_hilo_escucha, NULL, hilo_escucha, this);
	pthread_detach(thid_hilo_escucha);

	//pthread_create(&thid_hilo_render, NULL, hilo_render, this);
	//pthread_detach(thid_hilo_render);
}
void Cliente::LanzarHiloConexion() {
	pthread_t thid_hilo_conexion;
	pthread_create(&thid_hilo_conexion, NULL, hilo_conexion, this);
	pthread_detach(thid_hilo_conexion);
}
void Cliente::MenuDeSeleccion() {
}
std::queue<ModeloEstado> Cliente::getModeloCambios() {
	return this->ModeloCambios;
}
int Cliente::getTiepoUltimoMensajeRecibido() {
	return this->tiempoUltimoMensajeRecivido;
}
void Cliente::setTiempoUltimoMensajeRecibido(int tiempo) {
	this->tiempoUltimoMensajeRecivido = tiempo;
}

void Cliente::PushModeloEnCola(ModeloEstado modelo) {
	this->ModeloCambios.push(modelo);
}
ModeloEstado Cliente::PopModeloDeCola() {
	//lockear
	pthread_mutex_lock(&mutexx);
	ModeloEstado modelo = this->ModeloCambios.front();
	this->ModeloCambios.pop();
	pthread_mutex_unlock(&mutexx);
	return modelo;
}

Conexion * Cliente::getConexion() {
	return this->conexion;
}

void Cliente::setCenexion(Conexion* conexion) {
	this->conexion = conexion;
}
View * Cliente::getVista() {
	return this->vista;
}
void Cliente::setVista(View* vista) {
	this->vista = vista;
}

void Cliente::IniciarSeleccionPersonaje() {
	this->seleccionPersonajeIniciada = true;
}

void Cliente::FinalizarSeleccionPersonaje() {
	this->seleccionPersonajeFinalizada = true;
}

bool Cliente::EstaIniciadaSeleccionPersonaje() {
	return this->seleccionPersonajeIniciada;
}
bool Cliente::EstaFinalizadaSeleccionPersonaje() {
	return this->seleccionPersonajeFinalizada;
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}
