#include "Model_Jugador.h"
# include "../Logger/Logger.h"
#define MARGENDESELECCION 0
/*
Jugador::Jugador() {

}*/
Jugador::Jugador(int &ancho, int &alto, int &zind,std::string &nom,std::string &path, bool &inmortal) {
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
	this->mCollider.w =this->estado->getPosX()+ width;
	this->mCollider.h = this->estado->getPosY() +height;
	this->vidaJugador = 100;
	this->inmortal = inmortal;

}
void Jugador::SetVida(int vida){
	this->vidaJugador = vida;
}
int Jugador::GetVida(){
	return this->vidaJugador;
}
int Jugador::getPosXPoder(){
	return mipoder.getPosX();
}
int Jugador::getPosYPoder(){
	return mipoder.getPosY();
}
int Jugador::getSentidoPoder(){
	return mipoder.getSentido();
}
void Jugador::setPosYPoder(int y){
	 mipoder.setPosY(y);
}
void Jugador::setPosXPoder(int x){
	 mipoder.setPosX(x);
}
void Jugador::setSentidoPoder(int z){
	 mipoder.setSentido(z);
}
bool Jugador::poderActivo(){
	return mipoder.estaActivo();
}
void Jugador::setEstadoPoder(bool estado){
	 mipoder.setInactivo();
	if (estado)
		 mipoder.setActivo();

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

int Jugador::getCollideX(){
	return 	this->mCollider.x;
}
int Jugador::getCollideY(){
	return 	this->mCollider.y;
}
int Jugador::getCollideW(){
	return 	this->mCollider.w;
}
int Jugador::getCollideH(){
	return 	this->mCollider.h;
}
bool Jugador::collideConPoder(Poder * poder){
	return poder->colision(this->getCollideX(),this->getCollideY(),this->getCollideW(),this->getCollideH());
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
	jugadorVolando();
	if( this->murio())
		this->cambiarPersonaje();
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
	this->mCollider.w =this->estado->getPosX()+ width;
	this->mCollider.h = this->estado->getPosY() +height;
	//aca iria el contador
	if (this->getTipoGolpe() == TIPO_GOLPE::GOLPE_ARROJAR)
				this->setTipoGolpe(TIPO_GOLPE::NADA);
	if (this->getTipoGolpe() == TIPO_GOLPE::GOLPE_PODER)
				this->setTipoGolpe(TIPO_GOLPE::NADA);
	if (jugadorRival->collideConPoder(&mipoder)){
				jugadorRival->recibeDanio(10);
	}
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
	this->tipoGolpe = TIPO_GOLPE::NADA;
	}
}
void Jugador::Parar() {
	if(this->estado->estaAgachado()){
	this->activo.copiarEstadoAgachar(this->estado);
	this->estado = &(this->activo);
	this->tipoGolpe = TIPO_GOLPE::NADA;
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
//void Jugador::Defensa() {
//	this->estado->Defensa();
//	if (this->getTipoGolpe() == TIPO_GOLPE::NADA) {
//		std::cout << "Agregar PINIA!!!!!: " << std::endl;
//		this->setTipoGolpe(TIPO_GOLPE::ACTIVAR_DEFENSA);
//	}
//
//}

void Jugador::Pinia(Jugador * rival) {
	if ((this->getTipoGolpe() == TIPO_GOLPE::NADA) && (this->estado->getVelY() > -10)) {
		std::cout << "Agregar PINIA!!!!!: " << std::endl;
		this->setTipoGolpe(TIPO_GOLPE::GOLPE_PINIA);
	}
	if(rival->collideConJugador(&mCollider))
		rival->recibeDanio(this->estado->getDanioPinia());
}
//void Jugador::Pinia_agachado(Jugador * rival) {
//	this->estado->Pinia();
//	if (this->getTipoGolpe() == TIPO_GOLPE::NADA){
//
//				this->setTipoGolpe(TIPO_GOLPE::GOLPE_PINIA_AGACHADO);
//			}
//	if(rival->collideConJugador(&mCollider))
//	rival->recibeDanio(this->estado->getDanioPinia());
//}
void Jugador::Pinion(Jugador * rival) {
//	this->estado->Pinion();
	if (this->getTipoGolpe() == TIPO_GOLPE::NADA){

				this->setTipoGolpe(TIPO_GOLPE::GOLPE_PINION);
			}
	if(rival->collideConJugador(&mCollider))
	rival->recibeDanio(this->estado->getDanioPinion());

}

void Jugador::Patada(Jugador * rival) {
	if ((this->getTipoGolpe() == TIPO_GOLPE::NADA) && (this->estado->getVelY() > -10)){
		std::cout << "Agregar PATADA!!!!!: " << std::endl;
		this->setTipoGolpe(TIPO_GOLPE::GOLPE_PATADA);
	}
	if(rival->collideConJugador(&mCollider))
		rival->recibeDanio(this->estado->getDanioPatada());
}
void Jugador::Arrojar(Jugador * rival) {
	if (this->getTipoGolpe() == TIPO_GOLPE::NADA){
	this->estado->Arrojar();
				this->setTipoGolpe(TIPO_GOLPE::GOLPE_ARROJAR);
			}
	int i = -1;
	if (this->getDireccion()==SDL_FLIP_NONE)
		i=1;

	if((rival->collideConJugador(&mCollider))&&(rival->getTipoGolpe() == TIPO_GOLPE::NADA)){
	rival->estado->setVelocidadX(40*i);
	rival->estado->setVelocidadY(20);
	rival->setTipoGolpe(TIPO_GOLPE::GOLPE_VOLAR);
	rival->recibeDanio(this->estado->getDanioArrojar());
	}
}

void Jugador::Patadon(Jugador * rival) {
	if ((this->getTipoGolpe() == TIPO_GOLPE::NADA) && (this->estado->getVelY() > -10)){
		std::cout << "Agregar PATADON!!!!!: " << std::endl;
		this->setTipoGolpe(TIPO_GOLPE::GOLPE_PATADON);
	}
	if(rival->collideConJugador(&mCollider))
	rival->recibeDanio(this->estado->getDanioPatadon());
}

void Jugador::ActivarDefensa() {
	std::cout << "Agregar DEFENSAAAAAAAAAAAA!!!!!: " << std::endl;
	this->setTipoGolpe(TIPO_GOLPE::ACTIVAR_DEFENSA);
}

void Jugador::DesactivarDefensa() {
	std::cout << "Terminar DEFENSAAAAAAAAAAAA!!!!!: " << std::endl;
	this->setTipoGolpe(TIPO_GOLPE::DESACTIVAR_DEFENSA);
}

//void Jugador::Patada_agachado(Jugador * rival) {
//	this->estado->Patada_agachado();
//	if (this->getTipoGolpe() == TIPO_GOLPE::NADA){
//
//			this->setTipoGolpe(TIPO_GOLPE::GOLPE_PATADA_AGACHADO);
//		}
//	//aca va el if del collide
//	if(rival->collideConJugador(&mCollider))
//	rival->recibeDanio(this->estado->getDanioPatada());
//}

//void Jugador::Patadon_agachado(Jugador * rival) {
//	this->estado->Patadon_agachado();
//	if (this->getTipoGolpe() == TIPO_GOLPE::NADA){
//
//			this->setTipoGolpe(TIPO_GOLPE::GOLPE_PATADON_AGACHADO);
//		}
//	//aca va el if del collide
//	if(rival->collideConJugador(&mCollider))
//	rival->recibeDanio(this->estado->getDanioPatada());
//}
void Jugador::TirarPoder(Jugador * rival) {
	this->estado->TirarPoder();
	if (this->getTipoGolpe() == TIPO_GOLPE::NADA){

			this->setTipoGolpe(TIPO_GOLPE::GOLPE_PODER);
		}
	if (this->getDireccion()==SDL_FLIP_NONE){
		mipoder.activarPoder(getCollideW(),getCollideY()+30,1);
	}else{
		mipoder.activarPoder(getCollideX(),getCollideY()+30,-1);
	}
	std::cout << "HADOOOOUUUUKENNNNNN" << std::endl;
	std::cout << "HADOOOOUUUUKENNNNNN" << std::endl;
	std::cout << "HADOOOOUUUUKENNNNNN" << std::endl;

}

void Jugador::recibeDanio(int danio) {
	if (this->vidaJugador - danio >= 0){
		this->vidaJugador =this->vidaJugador - danio;
		if((this->getTipoGolpe())==!(TIPO_GOLPE::GOLPE_VOLAR))
		this->setTipoGolpe(TIPO_GOLPE::RECIBIR_DANIO);
	}
	//std::cout << "me pego y mi vida es : " + std::to_string(this->vidaJugador) << std::endl;
}

void Jugador::Saltar() {
//	this->estado->Saltar();
	if(!this->estado->estaSaltando()){
		this->estado->setVelocidadY(20);
		this->saltando.copiarEstado(this->estado);
		this->estado = &(this->saltando);
		this->tipoGolpe = TIPO_GOLPE::NADA;
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
	this->tipoGolpe = TIPO_GOLPE::NADA;
}
void Jugador::desactivar() {
	this->inactivo.copiarEstado(this->estado);
	this->estado = &(this->inactivo);
	this->detenerVelocidad();
	this->tipoGolpe = TIPO_GOLPE::NADA;
}
void Jugador::terminarSalto() {
	this->activo.copiarEstado(this->estado);
	this->estado = &(this->activo);
	this->tipoGolpe = TIPO_GOLPE::NADA;
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

bool Jugador::collideConJugador(SDL_Rect * jugador) {

	int leftRival, leftJugador;
	int rightRival, rightJugador;
	int topRival, topJugador;
	int bottomRival, bottomJugador;

	leftRival = jugador->x;

	rightRival = jugador->x + jugador->w;

	topRival = jugador->y;

	bottomRival = jugador->y + jugador->h;

	leftJugador = this->mCollider.x;
	rightJugador = this->mCollider.x + this->mCollider.w;
	topJugador = this->mCollider.y;
	bottomJugador = this->mCollider.y + this->mCollider.h;

	if (bottomJugador <= topRival) {
		return false;
	}

	if (topJugador >= bottomRival) {
		return false;
	}

	if (leftJugador >= rightRival) {
		return false;
	}

	if (rightJugador <= leftRival) {
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
void Jugador::setTipoGolpeCliente(TIPO_GOLPE tipoGolpe){
	if (tipoGolpe == TIPO_GOLPE::DESACTIVAR_DEFENSA){
		std::cout << "Defensa terminadaa##############" << std::endl;
		this->tipoGolpe = TIPO_GOLPE::NADA;
	}
	else
		this->tipoGolpe = tipoGolpe;
}
bool Jugador::murio(){
	if(this->inmortal){
		return false;
	}
	else{
		return this->vidaJugador==0;
	}
}
bool Jugador::estaVivo(){
	return !this->murio();
}

void Jugador::inicializarVida(){
	this->vidaJugador = 100;
}
bool Jugador::esInmortal(){
	return this->inmortal;
}

void Jugador::jugadorVolando(){
	if ((this->getTipoGolpe() == TIPO_GOLPE::GOLPE_VOLAR) ){
		if (this->estado->getVelX()!=0){
		if (this->estado->getVelX()>0)
			this->estado->setVelocidadX(this->estado->getVelX()-1);
		if (this->estado->getVelX()<0)
			this->estado->setVelocidadX(this->estado->getVelX()+1);
		}
		if(this->estado->getVelX()==0){
			this->setTipoGolpe(TIPO_GOLPE::NADA);
		}

	}
}
