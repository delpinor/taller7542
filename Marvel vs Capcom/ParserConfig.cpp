/*
 * ParserConfig.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: jorge
 */

#include "ParserConfig.h"

ParserConfig::ParserConfig() {


}
int ParserConfig::parsear_archivo(char* filepath){

	 std::ifstream file;
	 file.open (filepath);

	if (file){
		Json::Reader reader;
		reader.parse(file,this->configuracion);
		return OK;
	} else {
		 //agregar metodo logger: "se carga arcivo default

	}

	file.open (archivo_default);
	if (file){
		Json::Reader reader;
		reader.parse(file,this->configuracion);
		return OK;
		} else {

			throw Exception("ERROR FATAL: no se pudo abrir default","","");
			return ERROR;
		}

}
Json::Value* ParserConfig::getConfiguracion(){

	return (&(this->configuracion));

}

int ParserConfig::devolver_Map_Personajes(std::map< std::string, std::map<std::string, std::string> > *mapPersonajes){


	Json::Value valor;


	for (unsigned int i=0; i<this->configuracion["characters"].size(); i++){


	string name=configuracion["characters"][i]["name"].asString();
	(*mapPersonajes)[name]["filepath"]=configuracion["characters"][i]["filepath"].asString();
	(*mapPersonajes)[name]["height"]=configuracion["characters"][i]["height"].asString();
	(*mapPersonajes)[name]["width"]=configuracion["characters"][i]["width"].asString();
	(*mapPersonajes)[name]["zindex"]=configuracion["characters"][i]["zindex"].asString();

	}
	return OK;

}

int ParserConfig::devolver_Map_Fondo(std::map<int, std::map<std::string, std::string> > *mapBackground){



	for(unsigned int i=0; i<this->configuracion["battlefield"].size(); i++){



	(*mapBackground)[i]["filepath"]=this->configuracion["battlefield"][i]["background"]["filepath"].asString();
	(*mapBackground)[i]["zindex"]=this->configuracion["battlefield"][i]["background"]["zindex"].asString();

	}


	return OK;

}
	//funcion que devulve el tipo de log. Sino lo encuentra devuelve por default Debug

string ParserConfig::devolver_Tipo_Log(){

	string valor= this->configuracion["debug"].asString();

	if ( (valor!="ERROR") && (valor!="DEBUG") && (valor!="INFO") ) {
		return Log_Default;
	}else{
		return valor;
	}
}


int ParserConfig::devolver_Tam_Imagen(int *ancho, int *alto){


*alto=this->configuracion["window"]["height"].asInt();
	*ancho= this->configuracion["window"]["width"].asInt();
return OK;

}

ParserConfig::~ParserConfig() {
	// TODO Auto-generated destructor stub
}

