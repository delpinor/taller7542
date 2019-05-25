/*
 * Personajes.h
 *
 *  Created on: May 25, 2019
 *      Author: dev73
 */

#ifndef ENUMS_PERSONAJES_H_
#define ENUMS_PERSONAJES_H_

enum PERSONAJE{P_NA = -1, P_CAPITAN_AMERICA = 1 , P_SPIDERMAN = 2, P_VENOM = 3, P_CHUNLI = 4};

#include "../Helper/StringHelper.h"

class Personaje{
public:
	static int getPersonajeId(std::string nombre){

		nombre = StringHelper::toLower(nombre);

		if( nombre == "captain america"){
			return static_cast<int>(PERSONAJE::P_CAPITAN_AMERICA);
		}

		if( nombre == "venom"){
			return static_cast<int>(PERSONAJE::P_VENOM);
		}

		if( nombre == "spiderman"){
			return static_cast<int>(PERSONAJE::P_SPIDERMAN);
		}

		if( nombre == "chun li"){
			return static_cast<int>(PERSONAJE::P_CHUNLI);
		}

		return static_cast<int>(PERSONAJE::P_NA);

	}
};




#endif /* ENUMS_PERSONAJES_H_ */
