#include "Model_Jugador.h"
# include "../Logger/Logger.h"
#define MARGENDESELECCION 0
/*
Jugador::Jugador() {

}*/
Jugador::Jugador(int &ancho, int &alto, int &zind,std::string &nom,std::string &path) {
	this->estado = &(this->inactivo);
	this->mCollider.x = this->estado->getPosX();
	this->mCollider.y = this->estado->getPosY();

	this->direccion = SDL_FLIP_NONE;
	this->personaje = 0;

	this->width=ancho;
	this->height=alto;
	this->zindex= zind;
	this->nombre=nom;
	this->pathImagen=path;
	this->mCollider.w = width;
	this->mCollider.h = height;

}

int Jugador::get_alto(){

	return height;
}
int Jugador::get_ancho(){
	return width;

}
int Jugador::get_zindex(){
	return zindex;


}
std::string Jugador::getNombre(){

	return nombre;
}
std::string Jugador::getPathImagen(){
	return pathImagen;

}

void Jugador::setPosInitX(int posX) {
	this->estado->setPosInitX(posX);

}

void Jugador::setPosInitY(int posY) {
	this->estado->setPosInitY(posY);
}

void Jugador::setDireccion(SDL_RendererFlip direccion) {
	Logger::Log(DEBUG,"Jugador:: setea la direccion ","");
	this->direccion = direccion;
}

void Jugador::move(Jugador* jugadorRival, SDL_Rect* camara) {
	if (this->estado->estaCambiandoPersonaje()){
		this->estado->move();
	}
	else if (movimientoDerecha()) {
		if (!collideDerecha(camara)) {
			this->estado->move();
		} else {
			if (!jugadorRival->collideIzquierda(camara)) {
				this->estado->move();
			}
			else{
				this->estado->moveVertical();
			}
		}
	} else if (movimientoIzquierda()) {
			if (!collideIzquierda(camara)) {
				this->estado->move();
			} else {
				if (!jugadorRival->collideDerecha(camara)) {
					this->estado->move();
				} else {
					this->estado->moveVertical();
				}
			}
	} else {
		this->estado->move();
	}
	updateDirection(*jugadorRival);
	this->mCollider.x = this->estado->getPosX();
	this->mCollider.y = this->estado->getPosY();
}

int Jugador::getPosX() {
	return this->estado->getPosX();
}

int Jugador::getPosY() {
	return this->estado->getPosY();
}

void Jugador::setPosX(int PosX) {
	this->estado->setPosX(PosX);
}

void Jugador::setPosY(int PosY) {
	this->estado->setPosY(PosY);
}

void Jugador::disminuirVelocidadX() {
	this->estado->disminuirVelocidadX();
}
void Jugador::disminuirVelocidadY() {
	this->estado->disminuirVelocidadY();
}

void Jugador::cambiarPersonaje() {
	if(this->estado->getVelY()==0){
	this->estado->aumentarVelocidadY(20);
	this->cambiandoPersonaje.copiarEstadoCambiarPersonaje(this->estado);
	this->estado = &(this->cambiandoPersonaje);
	}
}

void Jugador::Agachar() {
	if(this->estado->getVelY()==0){
	this->agachado.copiarEstadoAgachar(this->estado);
	this->estado = &(this->agachado);
	}
}
void Jugador::Parar() {
	if(this->estado->estaAgachado()){
	this->activo.copiarEstadoAgachar(this->estado);
	this->estado = &(this->activo);
	}
}

void Jugador::aumentarVelocidadX() {
	this->estado->aumentarVelocidadX();
}

void Jugador::aumentarVelocidadX(int vel) {
	this->estado->aumentarVelocidadX(vel);
}

void Jugador::aumentarVelocidadY() {
	this->estado->aumentarVelocidadY();
}

void Jugador::aumentarVelocidadY(int vel) {
	this->estado->aumentarVelocidadY(vel);
}

void Jugador::Pinia() {
	this->estado->Pinia();
}

void Jugador::Pinion() {
	this->estado->Pinion();
}

void Jugador::Patada() {
	this->estado->Patada();
}

void Jugador::Patadon() {
	if (this->getTipoGolpe() == TIPO_GOLPE::NADA)
		this->setTipoGolpe(TIPO_GOLPE::GOLPE_PATADON);
}
void Jugador::TerminarGolpe() {
	this->activo.copiarEstado(this->estado);
	this->estado = &(this->activo);
	this->estado->setPegandoPatadon(false);
}

void Jugador::Saltar() {
//	this->estado->Saltar();
	if(!this->estado->estaSaltando()){
		this->estado->setVelocidadY(20);
		this->saltando.copiarEstado(this->estado);
		this->estado = &(this->saltando);
		}
}

int Jugador::getVelX() {
	return this->estado->getVelX();
}

int Jugador::getVelY() {
	return this->estado->getVelY();
}
void Jugador::set_desconectado(){
this->desconectado=true;

}
void Jugador::set_conectado(){
	this->desconectado=false;

}
bool Jugador::get_estado_desconexion(){

	return desconectado;
}
void Jugador::detenerVelocidad() {
	this->estado->detenerVelocidad();
}
bool Jugador::estaActivo() {
	return this->estado->estaActivo();
}
bool Jugador::estaAgachado() {
	return this->estado->estaAgachado();
}
bool Jugador::estaCambiandoPersonaje() {
	return this->estado->estaCambiandoPersonaje();
}
bool Jugador::estaSaltando() {
	return this->estado->estaSaltando();
}
void Jugador::activar() {
	this->activo.copiarEstado(this->estado);
	this->estado = &(this->activo);
	this->detenerVelocidad();
}
void Jugador::desactivar() {
	this->inactivo.copiarEstado(this->estado);
	this->estado = &(this->inactivo);
	this->detenerVelocidad();
}
void Jugador::terminarSalto() {
	this->activo.copiarEstado(this->estado);
	this->estado = &(this->activo);
}
bool Jugador::collide(SDL_Rect * camara) {

	int leftCam, leftJugador;
	int rightCam, rightJugador;
	int topCam, topJugador;
	int bottomCam, bottomJugador;

	leftCam = camara->x + MARGENDESELECCION;

	rightCam = camara->x + camara->w - MARGENDESELECCION;

	topCam = camara->y + MARGENDESELECCION;

	bottomCam = camara->y + camara->h - MARGENDESELECCION;

	leftJugador = this->mCollider.x;
	rightJugador = this->mCollider.x + this->mCollider.w;
	topJugador = this->mCollider.y;
	bottomJugador = this->mCollider.y + this->mCollider.h;

	if (bottomJugador <= topCam) {
		return false;
	}

	if (topJugador >= bottomCam) {
		return false;
	}

	if (leftJugador >= rightCam) {
		return false;
	}

	if (rightJugador <= leftCam) {
		return false;
	}

	return true;
}

bool Jugador::collideDerecha(SDL_Rect * camara) {

	int leftCam, leftJugador;
	int rightCam, rightJugador;
	int topCam, topJugador;
	int bottomCam, bottomJugador;

	leftCam = camara->x + MARGENDESELECCION;

	rightCam = camara->x + camara->w - MARGENDESELECCION;

	topCam = camara->y + MARGENDESELECCION;

	bottomCam = camara->y + camara->h - MARGENDESELECCION;

	leftJugador = this->mCollider.x;
	rightJugador = this->mCollider.x + this->mCollider.w;
	topJugador = this->mCollider.y;
	bottomJugador = this->mCollider.y + this->mCollider.h;

	if (rightJugador >= rightCam) {
		return true;
	}

	return false;
}

bool Jugador::collideIzquierda(SDL_Rect * camara) {

	int leftCam, leftJugador;
	int rightCam, rightJugador;
	int topCam, topJugador;
	int bottomCam, bottomJugador;

	leftCam = camara->x + MARGENDESELECCION;

	rightCam = camara->x + camara->w - MARGENDESELECCION;

	topCam = camara->y + MARGENDESELECCION;

	bottomCam = camara->y + camara->h - MARGENDESELECCION;

	leftJugador = this->mCollider.x;
	rightJugador = this->mCollider.x + this->mCollider.w;
	topJugador = this->mCollider.y;
	bottomJugador = this->mCollider.y + this->mCollider.h;

	if (leftJugador <= leftCam) {
		return true;
	}

	return false;
}

SDL_RendererFlip Jugador::getDireccion() {
	return this->direccion;
}

void Jugador::updateDirection(Jugador &oponente) {

	if (this->estado->getVelX() > 0) {
		direccion = SDL_FLIP_NONE;
	}else if (this->estado->getVelX() < 0) {
		direccion = SDL_FLIP_HORIZONTAL;
	}else if (this->getPosX()> oponente.getPosX()){
		direccion = SDL_FLIP_HORIZONTAL;
	}else{
		direccion = SDL_FLIP_NONE;
	}


}
int Jugador::Personaje() {
	return this->personaje;
}
void Jugador::setPersonaje(int p) {
	this->personaje = p;
}

bool Jugador::isFueraDePantalla(){
	return this->estado->isFueraDePantalla();
}

bool Jugador::movimientoDerecha(){
	return (this->estado->getVelX() > 0);
}

bool Jugador::movimientoIzquierda(){
	return (this->estado->getVelX() < 0);
}

void Jugador::setColor(int red,int green,int blue){
	this->r=red;
	this->g=green;
	this->b=blue;
}

int Jugador::getR(){
return r;
}
int Jugador::getG(){
return g;
}
int Jugador::getB(){
return b;
}
bool Jugador::isDebeTerminarSalto() {
	return debeTerminarSalto;
}

void Jugador::setDebeTerminarSalto(bool debeTerminarSalto) {
	this->debeTerminarSalto = debeTerminarSalto;
}
bool Jugador::isIniciarGolpe(){
	return this->iniciarGolpe;
}
void Jugador::setIniciarGolpe(bool iniciarGolpe){
	this->iniciarGolpe = iniciarGolpe;
}
TIPO_GOLPE Jugador::getTipoGolpe(){
	return this->tipoGolpe;
}
void Jugador::setTipoGolpe(TIPO_GOLPE tipoGolpe){
	this->tipoGolpe = tipoGolpe;
}
