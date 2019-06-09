#include "Conexion.h"

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

Conexion::Conexion() {
	socketCliente = 0;
	falloConexion = false;
//	cout << "creando conexion" << endl;
}
int Conexion::Reconectar() {

	cout<<"puerto: "<<_puerto;
	cout<<"_ip"<<_ip;
	return conectarConServidor(_ip, _puerto);

}
int Conexion::conectarConServidor( char* hostname, char * puerto) {



	strcpy (_ip , hostname );
	strcpy (_puerto , puerto );
	cout << "ip."<< _ip<<endl;

	cout << "puerto"<< puerto<<endl;
	//_ip = hostname;
	//_puerto = puerto;
//	cout << "creará un socket."<< endl;
	char ip[100];
	struct hostent *he;
	   struct in_addr **addr_list;
	   int i;
	   if ( (he = gethostbyname( _ip) ) == NULL)
	   { herror("gethostbyname");
	     return 1;}
	   addr_list = (struct in_addr **) he->h_addr_list;
	    for(i = 0; addr_list[i] != NULL; i++)
	    {   strcpy(ip , inet_ntoa(*addr_list[i]) );
	    	break;
	    }






	direcionServidor.sin_family = AF_INET;
	direcionServidor.sin_addr.s_addr = inet_addr(ip);
	direcionServidor.sin_port = htons(atoi(puerto));
	if ((socketCliente = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Creación de socket");
		falloConexion = true;
		cout << "Falló creación de socket." << endl;
	}
	if (!falloConexion) {
		if (connect(socketCliente, (struct sockaddr *) &direcionServidor,
				sizeof(direcionServidor)) < 0) {
			perror("Conexión");
			falloConexion = true;
			close(socketCliente);
			socketCliente = SOCKET_NO_VALIDO;
			cout << "Falló coneccion con servidor." << endl;
		}
	}
	int reuse = 1;

	if (setsockopt(socketCliente, SOL_SOCKET, SO_REUSEADDR, (const char*) &reuse,
			sizeof(reuse)) < 0) {
		perror("SO_REUSEADDR failed");
		falloConexion = true;
	}

	if (setsockopt(socketCliente, SOL_SOCKET, SO_REUSEPORT, (const char*) &reuse,
			sizeof(reuse)) < 0) {
		perror("SO_REUSEPORT failed");
		falloConexion = true;
	}
	if (falloConexion)
		return -1;
	return 0;
}
void Conexion::Cerrar() {
	shutdown(socketCliente, SHUT_RDWR);
	close(socketCliente);
}

int Conexion::enviar_mensaje(int socket, void* mensaje, int tam_mensaje) {

	int sent = 0;
	int s = 0;
	bool is_the_socket_valid = true;
//	std::cout << "[Comunicacion-enviarMensaje] Se va a iniciar el en enviado del mensaje: "<< mensaje << ";" << std::endl;
	while (sent < tam_mensaje && is_the_socket_valid) {
		s = send(socket, &mensaje, tam_mensaje - sent, MSG_NOSIGNAL);
		if (s == 0) {
			is_the_socket_valid = false;
		} else if (s < 0) {
			is_the_socket_valid = false;
		} else {
			sent += s;
		}
	}
//	std::cout << "[Comunicacion-enviarMensaje] Se completó el envío del mensaje: " << mensaje << ";" << std::endl;

	if (is_the_socket_valid) {
		return sent;
	} else {
		return -1;
	}
}

int Conexion::recibir_mensaje(int socket, void* mensaje, int tam_mensaje) {
//	int received = 0;
	int s = 0;
	bool is_the_socket_valid = true;
////	std::cout << "[Comunicacion-recibir_mensaje] Se va a recibir un msj de tamaño: " << tam_mensaje << std::endl;
//	while (received < tam_mensaje && is_the_socket_valid) {

	s = recv(socket, &mensaje, tam_mensaje, MSG_NOSIGNAL);
	cout << "Conexion::mensaje recibido." << mensaje << endl;
	if (s == 0) { // nos cerraron el socket :(
		perror("[Comunicacion-recibir_mensaje] Perror nos cerraron el socket");
		is_the_socket_valid = false;
//			std::cout << "[Comunicacion-recibir_mensaje] nos cerraron el socket :(" << std::endl;
	} else if (s < 0) { // hubo un error >(
		is_the_socket_valid = false;
		perror("[Comunicacion-recibir_mensaje] Perror recibiendo msj");
//			std::cout << "[Comunicacion-recibir_mensaje] Error recibiendo msj" << std::endl;
	}
//		else {
//			received += s;
////			std::cout << "[Comunicacion-recibir_mensaje] tamaño actual: " << s << std::endl;
//		}
//	}
//	std::cout << "[Comunicacion-recibir_mensaje] Tamaño recibido: " << received << std::endl;
//	std::cout << "[Comunicacion-recibir_mensaje] Mensaje recibido: " << mensaje << std::endl;

	if (is_the_socket_valid) {
		return 1;
	} else {
		return -1;
	}
}

int Conexion::getSocketCliente() {
	return socketCliente;
}
bool Conexion::falloLaConexion() {
	return falloConexion;
}

