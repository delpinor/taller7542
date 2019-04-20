/*
 * View_Elemento_renderizable.cpp
 *
 *  Created on: Apr 19, 2019
 *      Author: dev73
 */

#include "View_Elemento_Renderizable.h"

View_Elemento_renderizable::View_Elemento_renderizable(TIPO_ELEMENTO_RENDERIZABLE pTipoElementoRenderizable) {
	this->tipoElementoRenderizable = pTipoElementoRenderizable;
}

TIPO_ELEMENTO_RENDERIZABLE View_Elemento_renderizable::getTipoElemetoRenderizable() {
	return this->tipoElementoRenderizable;
}

int View_Elemento_renderizable::getDataValor(std::string clave) {
	return this->data[clave];
}

void View_Elemento_renderizable::setDataValor(std::string clave, int valor){
	this->data[clave] = valor;
}

View_Elemento_renderizable::~View_Elemento_renderizable() {
	// TODO Auto-generated destructor stub
}
