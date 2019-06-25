/*
 * Sonido.h
 *
 *  Created on: Jun 15, 2019
 *      Author: jorge
 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>

#ifndef SONIDO_H_
#define SONIDO_H_

class Sonido {
private:
	Mix_Music *audio = NULL;
	int tecla_activacion;
public:
	Sonido(int tecla);;
	bool init();
	bool loadMedia(char* path);
	const int get_tecla();
	void reproducir_sonido();
	void parar_sonido();
	virtual ~Sonido();
};

#endif /* SONIDO_H_ */
