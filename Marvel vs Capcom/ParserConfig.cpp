/*
 * ParserConfig.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: jorge
 */

#include "ParserConfig.h"
// defino los niveles de log para pasarle al parser
//enum LOGGER_NIVEL{DEBUG = 5 , INFO = 4, ERROR = 65};

ParserConfig::ParserConfig() {


}
int ParserConfig::parsear_archivo(char* filepath){

	 std::ifstream file;
	 file.open(filepath);

	 if (file){
		 Json::Reader reader;
		 reader.parse(file,this->configuracion);
		 file.close();
		 return OK;
	 }else{
		 return ERROR_ARCHIVO;
	 }
	// } else {
		// throw Exception("El Archivo no existe o no pudo ser abierto correctamente.","","");
	// }
}
Json::Value* ParserConfig::getConfiguracion(){

	return (&(this->configuracion));

}

void ParserConfig::devolver_Map_Personajes(std::map<int, std::map<std::string, std::string> > *mapPersonajes){

	for (unsigned int i=0; i<this->configuracion["personajes"].size(); i++){
		(*mapPersonajes)[i]["nombre"]=configuracion["personajes"][i]["nombre"].asString();
		(*mapPersonajes)[i]["alto"]=configuracion["personajes"][i]["alto"].asString();
		(*mapPersonajes)[i]["ancho"]=configuracion["personajes"][i]["ancho"].asString();
		(*mapPersonajes)[i]["rutaArchivoImagen"]=configuracion["personajes"][i]["rutaArchivoImagen"].asString();
		(*mapPersonajes)[i]["zIndex"]=configuracion["personajes"][i]["zIndex"].asString();
	}
}

void ParserConfig::devolver_Map_Fondo(std::map<int, std::map<std::string, std::string> > *mapBackground){

	for(unsigned int i=0; i<this->configuracion["fondosPantalla"].size(); i++){
		(*mapBackground)[i]["rutaArchivoImagen"]=this->configuracion["fondosPantalla"][i]["rutaArchivoImagen"].asString();
		(*mapBackground)[i]["zIndex"]=this->configuracion["fondosPantalla"][i]["zIndex"].asString();
	}
}

std::string ParserConfig::devolver_Tipo_Log(){

	string valor= this->configuracion["log"]["nivel"].asString();
	return valor;
}


void ParserConfig::devolver_Tam_Imagen(std::string *ancho, std::string *alto){

	*ancho = this->configuracion["ventana"]["ancho"].asString();
	*alto = this->configuracion["ventana"]["alto"].asString();
}

void ParserConfig::devolver_Map_Nivel(std::map<std::string, std::string>  *mapNivel){

	(*mapNivel)["ancho"]=this->configuracion["nivel"]["ancho"].asString();
	(*mapNivel)["alto"]=this->configuracion["nivel"]["alto"].asString();
}


ParserConfig::~ParserConfig() {
	// TODO Auto-generated destructor stub
}

