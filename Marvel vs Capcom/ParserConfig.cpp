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

			//throw Error_Juego("ERROR FATAL: no se pudo abrir default");
			return ERRORMSG;
		}

}
Json::Value* ParserConfig::getConfiguracion(){

	return (&(this->configuracion));

}

int ParserConfig::devolver_Map_Personajes(std::map<int, std::map<std::string, std::string> > *mapPersonajes){

	for (unsigned int i=0; i<this->configuracion["personajes"].size(); i++){
		(*mapPersonajes)[i]["nombre"]=configuracion["personajes"][i]["nombre"].asString();
		(*mapPersonajes)[i]["alto"]=configuracion["personajes"][i]["alto"].asString();
		(*mapPersonajes)[i]["ancho"]=configuracion["personajes"][i]["ancho"].asString();
		(*mapPersonajes)[i]["rutaArchivoImagen"]=configuracion["personajes"][i]["rutaArchivoImagen"].asString();
		(*mapPersonajes)[i]["zindex"]=configuracion["personajes"][i]["zindex"].asString();
	}
	return OK;

}

int ParserConfig::devolver_Map_Fondo(std::map<int, std::map<std::string, std::string> > *mapBackground){

	for(unsigned int i=0; i<this->configuracion["fondosPantalla"].size(); i++){
		(*mapBackground)[i]["orden"]=this->configuracion["fondosPantalla"][i]["orden"].asString();
		(*mapBackground)[i]["rutaArchivoImagen"]=this->configuracion["fondosPantalla"][i]["rutaArchivoImagen"].asString();
		(*mapBackground)[i]["zIndex"]=this->configuracion["fondosPantalla"][i]["zIndex"].asString();
	}


	return OK;

}

LOGGER_NIVEL ParserConfig::devolver_Tipo_Log(){

	string valor= this->configuracion["log"]["nivel"].asString();
	if (valor=="DEBUG") {
		return DEBUG;
	}else if(valor=="ERROR"){
		return ERROR;

	}else if (valor=="INFO"){
		return INFO;
	}else{
		//const char* mensaje="ERROR: no se detecto el nivel de debug requerido, se setea en modo debug";
		//throw Error_Juego("");

		//std::cout<<"ERROR"<<std::endl;
		return DEBUG;
	}
}


int ParserConfig::devolver_Tam_Imagen(int *ancho, int *alto){

	*alto=this->configuracion["ventana"]["alto"].asInt();
	*ancho= this->configuracion["ventana"]["ancho"].asInt();
	return OK;

}

int ParserConfig::devolver_Map_Nivel(std::map<std::string, std::string>  *mapNivel){

	(*mapNivel)["ancho"]=this->configuracion["nivel"]["ancho"].asString();
	(*mapNivel)["alto"]=this->configuracion["nivel"]["alto"].asString();

	return OK;
}


ParserConfig::~ParserConfig() {
	// TODO Auto-generated destructor stub
}

