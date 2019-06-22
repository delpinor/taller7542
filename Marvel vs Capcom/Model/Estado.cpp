#include "Estado.h"
#include "../View/View.h"
#include "GeneralPantalla.h"

#define VELOCIDAD_JUGADOR 3
#define VELOCIDAD_JUGADOR_SALTO 20

Estado::Estado() {
	this->posInitX = 10;
	this->posInitY = 480;
	this->mPosX = this->posInitX;
	this->mPosY = this->posInitY;
	this->mVelX = 0;
	this->mVelY = 0;
	this->aceleracion = 1;
	this->acelero = false;
}

Estado::~Estado() {
	//dtor
}

void Estado::move() {
//	quieto=false;

		this->mPosX += this->mVelX * aceleracion;
		if ((mPosX < 0) || (mPosX + ANCHO_JUGADOR >= ANCHO_NIVEL)) {
			mPosX -= mVelX * aceleracion;
		}
		mVelY -= aceleracion;
		mPosY -= mVelY;
		if ((mPosY < 0) || (mPosY + ALTO_JUGADOR >= ALTO_NIVEL)) {
			mPosY += mVelY;
			mVelY = 0;
		}
//		quieto=true;
}

void Estado::moveVertical() {
//	quieto=false;

		mVelY -= aceleracion;
		mPosY -= mVelY;
		if ((mPosY < 0) || (mPosY + ALTO_JUGADOR >= ALTO_NIVEL)) {
			mPosY += mVelY;
			mVelY = 0;
		}
//		quieto=true;
}

int Estado::getPosX() {
	return this->mPosX;
}
int Estado::getPosY() {
	return this->mPosY;
}
int Estado::getVelX() {
	return this->mVelX;
}
int Estado::getVelY() {
	return this->mVelY;
}

void Estado::setPosX(int PosX) {
	this->mPosX = PosX;
}
void Estado::setPosY(int PosY) {
	this->mPosY = PosY;
}

void Estado::setPosInitX(int posX) {
	this->posInitX = posX;
}
void Estado::setPosInitY(int posY) {
	this->posInitY = posY;
}

void Estado::setAceleracion(int ac) {
	this->aceleracion = ac;
}

void Estado::setVelocidadX(int velx) {
	this->mVelX = velx;

}
void Estado::setVelocidadY(int vely) {
	this->mVelY = vely;

}

void Estado::copiarEstado(Estado* estado) {
	this->posInitX = estado->posInitX;
	this->posInitY = estado->posInitY;
	this->mPosX = estado->mPosX;
	this->mPosY = estado->mPosY;
	this->mVelX = estado->mVelX;
	this->mVelY = estado->mVelY;
}

void Estado::copiarEstadoAgachar(Estado* estado) {
	this->posInitX = estado->posInitX;
	this->posInitY = estado->posInitY;
	this->mPosX = estado->mPosX;
	this->mPosY = estado->mPosY;
	this->mVelX = estado->mVelX;
	this->mVelY = estado->mVelY;
}

void Estado::copiarEstadoCambiarPersonaje(Estado* estado) {
	this->posInitX = estado->posInitX;
	this->posInitY = estado->posInitY;
	this->mPosX = estado->mPosX;
	this->mPosY = estado->mPosY;
	this->mVelX = estado->mVelX;
	this->mVelY = estado->mVelY;
}

void Estado::disminuirVelocidadX() {
	this->mVelX -= VELOCIDAD_JUGADOR;
	if (this->mVelX < -VELOCIDAD_JUGADOR) {
		this->mVelX = -VELOCIDAD_JUGADOR;
	}
}
void Estado::disminuirVelocidadY() {
	this->mVelY -= VELOCIDAD_JUGADOR;
	if (this->mVelY < -VELOCIDAD_JUGADOR) {
		this->mVelY = -VELOCIDAD_JUGADOR;
	}
}
void Estado::Agachar() {

}
void Estado::Parar() {

}
void Estado::aumentarVelocidadX() {
	this->mVelX += VELOCIDAD_JUGADOR;
	if (this->mVelX > VELOCIDAD_JUGADOR) {
		this->mVelX = VELOCIDAD_JUGADOR;
	}
}

void Estado::aumentarVelocidadX(int vel) {
	this->mVelX += vel;
}
void Estado::aumentarVelocidadY() {
	if (this->mVelY != 0)
		return;
	this->mVelY += VELOCIDAD_JUGADOR_SALTO;
	if (this->mVelY > VELOCIDAD_JUGADOR_SALTO) {
		this->mVelY = VELOCIDAD_JUGADOR_SALTO;
	}
}

void Estado::aumentarVelocidadY(int vel) {
	this->mVelY += vel;
}
void Estado::Saltar() {

}
void Estado::Pinia() {

}
int  Estado::getDanioPinia(){
	return 10;
}
int  Estado::getDanioPinion(){
	return 10;
}
int  Estado::getDanioPatada(){
	return 10;
}
int  Estado::getDanioPatadon(){
	return 10;
}
int  Estado::getDanioArrojar(){
	return 10;
}
void Estado::Pinion() {

}
void Estado::Arrojar() {

}
void Estado::Pinion_agachado() {

}
void Estado::Patada() {

}
void Estado::Patada_agachado() {

}
void Estado::Patadon() {

}
void Estado::Defensa(){

}
void Estado::detenerVelocidad() {
	this->mVelX = 0;
	this->mVelY = 0;
}

void Estado::desacelerar() {
	this->aceleracion = 1;
	this->acelero = false;
}

int Estado::getAceleracion() {
	return this->aceleracion;

}
bool Estado::getAcelero() {
	return this->acelero;
}
//métodos para cliente
bool Estado::isFueraDePantalla(){
	return this->fueraDePantalla;
}
void Estado::setEstaActivo(bool activo){
	this->activo = activo;
}
void Estado::setEstaAgachado(bool agachado){
	this->agachado = agachado;
}
void Estado::setEstaFueraDePantalla(bool fueraDePantalla){
	this->fueraDePantalla = fueraDePantalla;
}
void Estado::setEstaCambiandoPersonaje(bool cambiandoPersonaje){
	this->cambiandoPersonaje = cambiandoPersonaje;
}
void Estado::setEstaSaltando(bool saltando){
	this->saltando = saltando;
}
