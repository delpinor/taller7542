/*
 * Mensajes.h
 *
 *  Created on: 25 jun. 2019
 *      Author: delpinor
 */

#ifndef VIEW_MENSAJES_H_
#define VIEW_MENSAJES_H_
#include "../Model/LTexture.h"
#include <sstream>
#include <stdio.h>
#include <string>
#include <iostream>
#define MENSAJECARGA "CARGANDO...."
class Mensajes{
private:
	SDL_Renderer * gRenderer;
	LTexture gTextTexture;
	TTF_Font * gFont = NULL;
	SDL_Color textColor = { 0, 0, 0, 255 };
	std::stringstream texto;

public:
	Mensajes(SDL_Renderer * gRen);
	void Apagar();
	void render();

};





#endif /* VIEW_MENSAJES_H_ */
