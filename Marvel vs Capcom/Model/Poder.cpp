#include "Poder.h"
# include "../Logger/Logger.h"
# include "../Servidor/Partida.h"
Poder::Poder(int x,int y,int sentido ) {
	this->x=x;
	this->y=y;
	this->sentido=sentido;
}
void Poder::setPosInX(int x) {
	this->x=x;
}
void Poder::setPosInY(int y) {
	this->y=y;
}

void Poder::move() {
	this->x +=1 * sentido;
	std::cout << "vaaaa podeeerrrrrrrrrr" + std::to_string(this->x) << std::endl;
	if ((x < 0) || (x + 10 >= ANCHO_NIVEL)) {
		x -= 1*sentido;
	}

}
