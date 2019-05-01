#include "Chat.h"
#include "pthread.h"
#include <iostream>

pthread_mutex_t mutex;

void* hilo_conecciones(void* com){
	std::cout << "Hilo connecciones lanzado" << std::endl;
	Chat* p=(Chat*) com;
	p->GestionaConexiones();
}

void* hilo_recepcion_j1(void* com){
	std::cout << "Hilo recepción J1 lanzado" << std::endl;
	Chat* p=(Chat*) com;
	p->RecepcionMensajes1();
}

void* hilo_recepcion_j2(void* com){
	std::cout << "Hilo recepción J2 lanzado" << std::endl;
	Chat* p=(Chat*) com;
	p->RecepcionMensajes2();
}

void* hilo_recepcion_cliente(void* com){
	std::cout << "Hilo recepción CLIENTE lanzado" << std::endl;
	Chat* p=(Chat*) com;
	p->RecepcionMensajesCliente();
}

int Chat::InitServidor(const char* puerto_numero, int num_clientes_espera){
	pthread_mutex_init(&mutex,NULL);
	int error;
	error = this->servidor.preparar_socket_servidor(puerto_numero, num_clientes_espera);
	if (error == -1){
		std::cout << "[Chat-InitServidor] Error preparando socket servidor"<< std::endl;
		return ERROR;
	}
	pthread_t thid_hilo_conecciones, thid_hilo_recepcion_j1, thid_hilo_recepcion_j2;
	pthread_create(&thid_hilo_conecciones, NULL, hilo_conecciones, this);
	pthread_create(&thid_hilo_recepcion_j1, NULL, hilo_recepcion_j1, this);
	pthread_create(&thid_hilo_recepcion_j2, NULL, hilo_recepcion_j2, this);
	return OK;
}

int Chat::InitCliente(char *nom_servidor, const char* puerto_num){
	std::cout << "[Chat-InitCliente] Por preparar el cocket cliente"<< std::endl;
	int error = NULL;
	error = this->servidor.preparar_socket_cliente(nom_servidor, puerto_num);
	if (error == -1){
		std::cout << "[Chat-InitCliente] Error preparando el socket cliente"<< std::endl;
		return ERROR;
	}
	std::cout << "[Chat-InitCliente] Socket cliente preparado correcntamente"<< std::endl;
	pthread_t thid_hilo_recepcion_cliente;
	pthread_create(&thid_hilo_recepcion_cliente, NULL, hilo_recepcion_cliente, this);
	return OK;
}

void Chat::GestionaConexiones(){
	int cantConn = 0;
	while (1) {
		Comunicacion com;
		int err=0;
		std::cout << "[Chat-GestionaConexiones(HILO)] Esperando clientes..."<< std::endl;

		err = servidor.aceptar_cliente();
		if (err != -1){
			std::cout << "[Chat-GestionaConexiones(HILO)] Conectó con un clientee! resultado: "<< err << std::endl;
			std::cout << "[Chat-GestionaConexiones(HILO)] Cliente numero: "<< cantConn << std::endl;
			com.socket_cliente = servidor.socket_cliente;
			cantConn=cantConn+1;
		}else {
			std::cout << "[Chat-GestionaConexiones(HILO)] Algo salió mal conectando con el cliente. resultado. "<< err << std::endl;
			servidor.close_socket(servidor.socket_servidor);
		}
		pthread_mutex_lock(&mutex);
		conexiones.push_back(com);
		pthread_mutex_unlock(&mutex);
	}
}

void Chat::RecepcionMensajes1() {
	std::cout << "[Chat-RecepcionMensajes1(HILO)] Recepcion de msjs del cliente 1." << std::endl;
	int tamConexiones = 0;
	char cad[300];
	int error = NULL;
	int tam = 0;
	while (1) {
		Comunicacion com;
		memset(cad, 0, sizeof(cad));
		usleep(10);
		pthread_mutex_lock(&mutex);
		tamConexiones = conexiones.size();
		pthread_mutex_unlock(&mutex);
		if (tamConexiones >= 1) {
			char mensaje[300];
			pthread_mutex_lock(&mutex);
			com = conexiones[0];
			pthread_mutex_unlock(&mutex);
			std::cout << "[Chat-RecepcionMensajes1(HILO)] Esperando msjs del cliente 1: " << com.socket_cliente << std::endl;

			error = com.recibir_mensaje(this->servidor.get_socket_cliente(),(char*) &tam, sizeof(int));
			if (error == -1) {
				std::cout << "[Chat-RecepcionMensajes1(HILO)] No se pudo obtener la cabecera del msj" << std::endl;
				this->servidor.close_socket(servidor.get_socket_cliente());
			} else
				std::cout << "[Chat-RecepcionMensajes1] Tamño del mensaje a recibir: " << tam << std::endl;

			error = com.recibir_mensaje(com.socket_cliente, cad, tam);
			if (error == -1) {
				std::cout << "[Chat-RecepcionMensajes1(HILO)] No se pudo obtener la cabecera del msj" << std::endl;
				this->servidor.close_socket(servidor.get_socket_cliente());
			} else
				std::cout << "[Chat-RecepcionMensajes1(HILO)] Mensaje recibido: " << cad << std::endl;
			strcpy(mensaje, cad);
//			std::cout << "[Chat-RecepcionMensajes1(HILO)] Se va a pushear a la cola el msj: " << mensaje << std::endl;
			pthread_mutex_lock(&mutex);
			mensajes.push(mensaje);
			pthread_mutex_unlock(&mutex);
		}
	}
	std::cout << "[Chat-RecepcionMensajes1(HILO)] Terminando hilo comandos jugador1" << std::endl;

}

void Chat::RecepcionMensajes2() {
	std::cout << "[Chat-RecepcionMensajes2(HILO)] Recepcion de msjs del cliente 2." << std::endl;
	int tamConexiones = 0;
	char cad[300];
	int error = NULL;
	int tam = 0;
	while (1) {
		Comunicacion com;
		memset(cad, 0, sizeof(cad));
		usleep(10);
		pthread_mutex_lock(&mutex);
		tamConexiones = conexiones.size();
		pthread_mutex_unlock(&mutex);
		if (tamConexiones >= 2) {
			char mensaje[300];
			pthread_mutex_lock(&mutex);
			com = conexiones[1];
			pthread_mutex_unlock(&mutex);
			std::cout << "[Chat-RecepcionMensajes2(HILO)] Esperando msjs del cliente 2: " << com.socket_cliente << std::endl;

			error = com.recibir_mensaje(this->servidor.get_socket_cliente(),(char*) &tam, sizeof(int));
			if (error == -1){
				std::cout << "[Chat-RecepcionMensajes2(HILO)] No se pudo obtener la cabecera del msj" << std::endl;
				this->servidor.close_socket(servidor.get_socket_cliente());
			}else
				std::cout << "[Chat-RecepcionMensajes2(HILO)] Tamño del mensaje a recibir: " << tam << std::endl;

			error = com.recibir_mensaje(com.socket_cliente,cad, tam);
			if (error == -1){
				std::cout << "[Chat-RecepcionMensajes2(HILO)] No se pudo obtener la cabecera del msj" << std::endl;
				this->servidor.close_socket(servidor.get_socket_cliente());
			}else
				std::cout << "[Chat-RecepcionMensajes2(HILO)] Mensaje recibido: " << cad << std::endl;
			strcpy(mensaje, cad);
//			std::cout << "[Chat-RecepcionMensajes2(HILO)] Se va a pushear a la cola el msj: " << mensaje << std::endl;
			pthread_mutex_lock(&mutex);
			mensajes.push(mensaje);
			pthread_mutex_unlock(&mutex);
		}
	}
	std::cout << "[Chat-RecepcionMensajes2(HILO)] Terminando hilo comandos jugador2" << std::endl;

}

void Chat::RecepcionMensajesCliente() {
	std::cout << "[Chat-RecepcionMensajesCliente(HILO)] Esperando Mensajes del Servidor" << std::endl;
	int error = NULL;
	int tam = 0;
	char cad[300];
	while (1) {
		memset(cad, 0, sizeof(cad));
		error = servidor.recibir_mensaje(this->servidor.get_socket_cliente(),(char*) &tam, sizeof(int));
		if (error == -1){
			std::cout << "[Chat-RecepcionMensajesCliente(HILO)] No se pudo obtener la cabecera del msj" << std::endl;
			this->servidor.close_socket(servidor.get_socket_cliente());
		}else
			std::cout << "[Chat-RecepcionMensajesCliente(HILO)] Tamaño del mensaje a recibir: " << tam << std::endl;

		error = this->servidor.recibir_mensaje(this->servidor.get_socket_cliente(), cad, tam);
		if (error == -1){
			std::cout << "[Chat-RecepcionMensajesCliente(HILO)] No se pudo obtener la cabecera del msj" << std::endl;
			this->servidor.close_socket(servidor.get_socket_cliente());
		}else
			std::cout << "[Chat-RecepcionMensajesCliente(HILO)] Mensaje recibido: " << cad << std::endl;
		if (cad[0] == 'q')
			servidor.close_socket(servidor.socket_cliente);
	}

}

void Chat::EnviarMensajesAClientes() {
	char* mensaje;
	Comunicacion com;
	int error = NULL;
	bool mensajesIsEmpty = true;
	int tam = 0;
	std::cout << "[Chat-EnviarMensajesACLientes] Por enviar mensajes.." << std::endl;
	while (1) {
		usleep(1000000);
		pthread_mutex_lock(&mutex);
		mensajesIsEmpty = this->mensajes.empty();
		pthread_mutex_unlock(&mutex);
//		std::cout << "[Chat-EnviarMensajesACLientes] La cola de msjs está vacía? " << mensajesIsEmpty << std::endl;
		if (!mensajesIsEmpty) {

			pthread_mutex_lock(&mutex);
			mensaje = mensajes.front();
			mensajes.pop();
			pthread_mutex_unlock(&mutex);

			tam = strlen(mensaje);
//			std::cout << "[Chat-EnviarMensajesACLientes] Mensaje obtenido: "<< mensaje << std::endl;
//			std::cout << "[Chat-EnviarMensajesACLientes] Con tamaño: "<< tam << std::endl;
			pthread_mutex_lock(&mutex);
			int tamConnexiones = conexiones.size();
			pthread_mutex_unlock(&mutex);

			for (int i = 0; i < tamConnexiones; i++) {

				pthread_mutex_lock(&mutex);
				com = conexiones[i];
				pthread_mutex_unlock(&mutex);

				std::cout << "[Chat-EnviarMensajesACLientes] Se va a enviar la cabecera mensaje: "<< tam << std::endl;
				error = com.enviar_mensaje(com.get_socket_cliente(),(char*) &tam, sizeof(int));
				if (error == -1)
					std::cout << "[Chat-EnviarMensajesACLientes] No se pudo enviar la cabecera del mensaje" << std::endl;

				std::cout << "[Chat-EnviarMensajesACLientes] Se va a enviar el mensaje: " << mensaje << "; de tamaño: " << tam << std::endl;
				error = com.enviar_mensaje(com.socket_cliente, mensaje, tam);
				if (error == -1)
					std::cout << "[Chat-EnviarMensajesACLientes] No se pudo enviar el mensaje" << std::endl;
			}
		}
	}
}

int Chat::enviarMensaje(char* mensaje, int tam_mensaje){
	int error = NULL;
	std::cout << "[Chat-enviarMensaje] Se va a enviar la cabecera mensaje: " << tam_mensaje << std::endl;
	error = this->servidor.enviar_mensaje(this->servidor.get_socket_cliente(),(char*) &tam_mensaje, sizeof(int));
	if (error == -1)
		std::cout << "[Chat-enviarMensaje] No se pudo enviar la cabecera del mensaje" << std::endl;

	std::cout << "[Chat-enviarMensaje] Se va a enviar el mensaje: " << mensaje << " de tamaño: "<< tam_mensaje << std::endl;
	error = this->servidor.enviar_mensaje(this->servidor.socket_cliente,mensaje, tam_mensaje);
	if (error == -1)
		std::cout << "[Chat-enviarMensaje] No se pudo enviar el mensaje" << std::endl;
	return error;
}
