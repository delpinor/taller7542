/*
 * StringHelper.cpp
 *
 *  Created on: Apr 9, 2019
 *      Author: dev73
 */

#include "StringHelper.h"

bool StringHelper::esUnNumero(string valor){

	if(valor == ""){
		return false;
	}
	else{
		for (unsigned int i = 0; i < valor.length(); i++){
			if (isdigit(valor[i]) == false){
				return false;
			}
		}
		return true;
	}
}

std::string StringHelper::toLower(std::string valor){
	std::transform(valor.begin(), valor.end(), valor.begin(), ::tolower);
	return valor;
}
