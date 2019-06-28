#ifndef ESTADO_H
#define ESTADO_H

#define VELOCIDAD_NORMAL 3
#define VELOCIDAD_ACELERACION 2

class Estado {
public:
	Estado();
	virtual ~Estado();
	int getPosX();
	int getPosY();
	int getVelX();
	int getVelY();
	void setPosX(int PosX);
	void setPosY(int PosY);
	void setPosInitX(int posX);
	void setPosInitY(int posY);
	void copiarEstado(Estado* estado);
	void copiarEstadoAgachar(Estado* estado);
	void copiarEstadoCambiarPersonaje(Estado* estado);
	void disminuirVelocidadX();
	void disminuirVelocidadY();
	void Agachar();
	void Parar();
	void aumentarVelocidadX();
	void aumentarVelocidadY();
	void Saltar();
	void Pinia();
	void Pinion();
	void Arrojar();
	void TirarPoder();
	void Pinion_agachado();

	void Patada();
	void Patada_agachado();
	void Patadon();
	void Patadon_agachado();
	void Defensa();
	int  getDanioPinia();
	int  getDanioPinion();
	int  getDanioPatada();
	int  getDanioPatadon();
	int  getDanioArrojar();
	void detenerVelocidad();
	virtual void move() = 0;
	virtual void moveVertical() = 0;
	virtual bool estaActivo() = 0;
	virtual bool estaAgachado() = 0;
	virtual bool estaCambiandoPersonaje() = 0;
	virtual bool estaSaltando() = 0;
	int getAceleracion();
	void desacelerar();
	bool getAcelero();
	void setVelocidadX(int velx);
	void setVelocidadY(int vely);
	void setAceleracion(int ac);
	void aumentarVelocidadX(int vel);
	void aumentarVelocidadY(int vel);
	virtual bool isFueraDePantalla() = 0;
	//métodos para el cliente
	virtual void setEstaActivo(bool estaActivo) = 0;
	virtual void setEstaAgachado(bool estaAgachado) = 0;
	virtual void setEstaFueraDePantalla(bool estaEstaFueraDePantalla) = 0;
	virtual void setEstaCambiandoPersonaje(bool estaEstaCambiandoPersonaje) = 0;
	virtual void setEstaSaltando(bool estaSaltando) = 0;

protected:
	int posInitX, posInitY;
	int mPosX, mPosY;

	int mVelX, mVelY;
	int aceleracion;
	bool acelero;
	//estados para el cliente
	bool activo = false;
	bool agachado = false;
	bool fueraDePantalla = false;
	bool cambiandoPersonaje = false;
	bool saltando = false;

private:
};

#endif // ESTADO_H
