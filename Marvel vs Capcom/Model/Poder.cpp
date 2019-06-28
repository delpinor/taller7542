#include "Poder.h"
# include "../Logger/Logger.h"
# include "../Servidor/Partida.h"
Poder::Poder() {

}
void Poder::setPosInX(int x) {
	this->izquierda=x;
}
void Poder::setPosInY(int y) {
	this->arriba=y;
}

void Poder::move() {
	if(estaActivo()){
	this->izquierda +=1 * sentido;
	if ((izquierda < 0) || (izquierda + 10 >= ANCHO_NIVEL)) {
		izquierda -= 1*sentido;
	}
	this->derecha=this->izquierda+10;
	this->abajo=this->arriba+10;
	}
}

bool Poder::colision(int izquierda , int arriba, int derecha, int abajo ) {
	if(this->estaActivo()){
	move();
//	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"  << std::endl;
//	std::cout << "izquierda coll" + std::to_string(this->izquierda) + ">=" + "derecha rival" + std::to_string(derecha) << std::endl;
//	std::cout << "derecha coll" + std::to_string(this->derecha)+ "<="  + "izquierda rival" + std::to_string(izquierda) << std::endl;
//	std::cout << "arriba coll" + std::to_string(this->arriba)  + ">=" + "abajo rival" + std::to_string(abajo) << std::endl;
//	std::cout << "abajo coll" + std::to_string(this->abajo)  + "<="+ "arriba rival"  + std::to_string(arriba) << std::endl;
//	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"  << std::endl;

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
	//std::cout << ">>>>>>>>CHOCO!<<<<<<<<"  << std::endl;
	this->setInactivo();
	return true;
	}else{
		return false;
	}

}
bool Poder::estaActivo() {
	return this->activo;
}
void Poder::setActivo(){
	this->activo=true;
}
void Poder::setInactivo(){
	this->activo=false;
}
void Poder::activarPoder(int x,int y,int sentido ) {
	this->izquierda=x;
	this->arriba=y;
	this->derecha=this->izquierda+10;
	this->abajo=this->arriba+10;
	this->sentido=sentido;
	this->setActivo();
}
int Poder::getPosX(){
	return this->izquierda;
}
int Poder::getPosY(){
	return this->arriba;
}
int Poder::getSentido(){
	return this->sentido;
}
void Poder::setPosY(int y){
	 this->arriba = y;
}
void Poder::setPosX(int x){
	 this->izquierda = x;
}
void Poder::setSentido(int z){
	 this->sentido = z;
}

