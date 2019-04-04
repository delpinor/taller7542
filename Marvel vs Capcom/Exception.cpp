/*
 * Exception.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: jorge
 */

#include "Exception.h"

std::string Exception::what()  noexcept{
	 std::string mensaje =inicio + id  + fin;
	 return mensaje;
}

Exception::~Exception() {
	// TODO Auto-generated destructor stub
}

