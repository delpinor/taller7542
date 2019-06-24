#include "Poder.h"
# include "../Logger/Logger.h"
# include "../Servidor/Partida.h"
Poder::Poder(int x,int y,int sentido ) {
	this->izquierda=x;
	this->arriba=y;
	this->derecha=this->izquierda+10;
	this->abajo=this->arriba+10;
	this->sentido=sentido;
}
void Poder::setPosInX(int x) {
	this->izquierda=x;
}
void Poder::setPosInY(int y) {
	this->arriba=y;
}

void Poder::move() {
	this->izquierda +=1 * sentido;
	if ((izquierda < 0) || (izquierda + 10 >= ANCHO_NIVEL)) {
		izquierda -= 1*sentido;
	}
	this->derecha=this->izquierda+10;
	this->abajo=this->arriba+10;
}

bool Poder::colision(int izquierda , int arriba, int derecha, int abajo ) {
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"  << std::endl;
	std::cout << "vaaaa podeeerrrrrrrrrr izquierda coll" + std::to_string(this->izquierda) << std::endl;
	std::cout << "vaaaa podeeerrrrrrrrrr derecha coll" + std::to_string(this->derecha) << std::endl;
	std::cout << "vaaaa podeeerrrrrrrrrr arriba coll" + std::to_string(this->arriba) << std::endl;
	std::cout << "vaaaa podeeerrrrrrrrrr abajo coll" + std::to_string(this->abajo) << std::endl;
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"  << std::endl;

	std::cout << "vaaaa podeeerrrrrrrrrr izquierda rival"  + std::to_string(izquierda) << std::endl;
	std::cout << "vaaaa podeeerrrrrrrrrr derecha rival" + std::to_string(derecha) << std::endl;
	std::cout << "vaaaa podeeerrrrrrrrrr arriba rival" + std::to_string(arriba) << std::endl;
	std::cout << "vaaaa podeeerrrrrrrrrr abajo rival" + std::to_string(abajo) << std::endl;
	if (this->abajo <= arriba) {
		return false;
	}

	if (this->arriba >= abajo) {
		return false;
	}

	if (this->derecha <= izquierda) {
		return false;
	}

	if (this->izquierda >= derecha) {
		return false;
	}


	return true;

}
