/*
 * NumericHelper.cpp
 *
 *  Created on: Apr 12, 2019
 *      Author: dev73
 */

#include "NumericHelper.h"

int NumericHelper::parseStringToInt(std::string valor){
	int valorInt;
	std::stringstream ss (valor);
	ss >> valorInt;

	return valorInt;
}


