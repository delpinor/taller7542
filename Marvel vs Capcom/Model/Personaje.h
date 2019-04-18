/*
 * Personaje.h
 *
 *  Created on: Apr 4, 2019
 *      Author: jorge
 */

#ifndef MODEL_PERSONAJE_H_
#define MODEL_PERSONAJE_H_
#include <string>
#include <map>

class Personaje {
private:
		std:: string nombre;
		std:: string pathImagen;
		int height;
		int width;
		int zindex;


public:
	Personaje(std::string nombre, std::map<std::string, std::string>  *valores);
	virtual ~Personaje();
};

#endif /* MODEL_PERSONAJE_H_ */
