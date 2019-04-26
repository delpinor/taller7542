/*
 * VectorHelper.cpp
 *
 *  Created on: Apr 12, 2019
 *      Author: dev73
 */

#include "VectorHelper.h"
#include "StringHelper.h"

bool VectorHelper::contiene(std::vector<string> *vec, std::string valor){
	if (std::find(vec->begin(), vec->end(), StringHelper::toLower(valor)) != vec->end()){
		return true;
	}
	else{
		return false;
	}
}


