/*
 * EfectoSonido.h
 *
 *  Created on: Jun 16, 2019
 *      Author: jorge
 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>


#ifndef EFECTOSONIDO_H_
#define EFECTOSONIDO_H_

class EfectoSonido {
private:
	Mix_Chunk* audio = NULL;
	int tecla_activacion;

public:
	EfectoSonido(int tecla);
	bool init();
	bool loadMedia(char* path);
	const int get_tecla();
	void reproducir_sonido();
	void parar_sonido();
	virtual ~EfectoSonido();
};

#endif /* EFECTOSONIDO_H_ */
