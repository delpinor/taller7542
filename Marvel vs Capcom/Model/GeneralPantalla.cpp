/*
 * GeneralPantalla.cpp
 *
 *  Created on: 17 abr. 2019
 *      Author: delpinor
 */
#include "GeneralPantalla.h"
GeneralPantalla* GeneralPantalla::instance = 0;
int GeneralPantalla::_alto =0;
int GeneralPantalla::_ancho =0;
GeneralPantalla* GeneralPantalla::GetInstancia()
{
    if (instance == 0)
    {
        instance = new GeneralPantalla();
    }

    return instance;
}
void GeneralPantalla::SetResolucion(int alto, int ancho){
	_alto = alto;
	_ancho = ancho;

}
int GeneralPantalla::GetAlto(){
	return _alto;
}
int GeneralPantalla::GetAncho(){
	return _alto;
}
GeneralPantalla::GeneralPantalla()
{}



