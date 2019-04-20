/*
 * View_Elemento_renderizable.h
 *
 *  Created on: Apr 19, 2019
 *      Author: dev73
 */

#ifndef VIEW_VIEW_ELEMENTO_RENDERIZABLE_H_
#define VIEW_VIEW_ELEMENTO_RENDERIZABLE_H_

#include <string>
#include <map>
using namespace std;

enum TIPO_ELEMENTO_RENDERIZABLE{FONDO = 1 , PERSONAJE = 2};

class View_Elemento_renderizable {
public:
	View_Elemento_renderizable(TIPO_ELEMENTO_RENDERIZABLE pTipoElementoRenderizable);
	TIPO_ELEMENTO_RENDERIZABLE getTipoElemetoRenderizable();
	int getDataValor(std::string clave);
	void setDataValor(std::string clave, int valor);
	virtual ~View_Elemento_renderizable();

private:
	TIPO_ELEMENTO_RENDERIZABLE tipoElementoRenderizable;
	std::map<std::string, int> data;
};



#endif /* VIEW_VIEW_ELEMENTO_RENDERIZABLE_H_ */
