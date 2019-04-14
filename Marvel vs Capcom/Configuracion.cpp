/*
 * Configuracion.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: jorge
 */

#include "Configuracion.h"

Configuracion::Configuracion(char* filepath, std::vector<string> *nombresPersonajes) {


	bool utilizarArchivoDefault = false;
	ParserConfig parser;
	ParserConfig parserArchivoDefault;
	parserArchivoDefault.parsear_archivo(ruta_archivo_default);

	this->nivelLog = nivel_log_default;

	try{
		if(filepath == NULL || filepath[0] == '\0'){
			throw Exception("La ruta del archivo JSON no es válida: ", filepath, "");
		}
		parser.parsear_archivo(filepath);
		parser.devolver_Map_Personajes(&mapPersonajes);
		parser.devolver_Map_Fondo(&mapFondoPantalla);
		parser.devolver_Tam_Imagen(&anchoVentana,&altoVentana);
		parser.devolver_Map_Nivel(&mapNivel);
		this->nivelLog = parser.devolver_Tipo_Log();
	}
	catch(Exception& ex){
		std::string msjError = "Error Parseando el archivo: " + ex.what() + ".";
		//LOGUEAR EL ERROR
		//LOGUEAR QUE SE PROCESARÁ EL ARCHIVO DEFAULT
		utilizarArchivoDefault = true;
	}

	if(utilizarArchivoDefault){
		parserArchivoDefault.devolver_Map_Personajes(&mapPersonajes);
		parserArchivoDefault.devolver_Map_Fondo(&mapFondoPantalla);
		parserArchivoDefault.devolver_Tam_Imagen(&anchoVentana,&altoVentana);
		parserArchivoDefault.devolver_Map_Nivel(&mapNivel);
		nivelLog = parserArchivoDefault.devolver_Tipo_Log();
	}
	else{
		this->ValidarConfigs(&parserArchivoDefault,nombresPersonajes);
	}
}

std::map< int, std::map<std::string, std::string> > Configuracion::get_Config_Personajes(){
	return mapPersonajes;
}

std::map< int, std::map<std::string, std::string> > Configuracion::get_Config_FondosPantalla(){
	return mapFondoPantalla;
}

std::map<std::string, std::string> Configuracion::get_Config_Nivel(){
	return mapNivel;
}

LOGGER_NIVEL Configuracion::get_Config_NivelLog(){

	if (this->nivelLog=="DEBUG") {
		return DEBUG;
	}else if(this->nivelLog=="ERROR"){
		return ERROR;
	}else if (this->nivelLog=="INFO"){
		return INFO;}
	else{
	//const char* mensaje="ERROR: no se detecto el nivel de debug requerido, se setea en modo debug";
		return DEBUG;
	};
}

int Configuracion::get_Config_AnchoVentana(){
	return NumericHelper::parseStringToInt(this->anchoVentana);
}

int Configuracion::get_Config_AltoVentana(){
	return NumericHelper::parseStringToInt(this->altoVentana);
}

Configuracion::~Configuracion() {
	// TODO Auto-generated destructor stub
}

//Private
void Configuracion::ValidarConfigs(ParserConfig *parserArchivoDefault, vector<string> *nombresPersonajes){

	//Log
	if(this->nivelLog == ""){
		//TODO validar que el valor pertenezca a uno de los niveles que maneja el logger.
		// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULT
		this->nivelLog = nivel_log_default;
	}

	//Ventana
	if(!StringHelper::esUnNumero(this->anchoVentana) || NumericHelper::parseStringToInt(this->anchoVentana) <= 0){
		// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULT
		this->anchoVentana = ancho_ventana_default;
	}

	if(!StringHelper::esUnNumero(this->altoVentana) || NumericHelper::parseStringToInt(this->altoVentana) <= 0){
		// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULT
		this->altoVentana = alto_ventana_default;
	}

	//Personajes
	if(this->mapPersonajes.size() == 0){
		// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULTs
		parserArchivoDefault->devolver_Map_Personajes(&mapPersonajes);
	}
	else{

		for (unsigned int i = 0; i < mapPersonajes.size(); i++){

			bool personajeDefault = false;
			if (!VectorHelper::contiene(nombresPersonajes, mapPersonajes[i]["nombre"])){
				personajeDefault = true;
				// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULT
				mapPersonajes[i]["nombre"] = nombre_personaje_default;
			}

			if(!StringHelper::esUnNumero(mapPersonajes[i]["alto"]) || NumericHelper::parseStringToInt(mapPersonajes[i]["alto"]) <= 0){
				// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULT
				mapPersonajes[i]["alto"] = alto_personaje_default;
			}

			if(!StringHelper::esUnNumero(mapPersonajes[i]["ancho"]) || NumericHelper::parseStringToInt(mapPersonajes[i]["ancho"]) <= 0){
				// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULT
				mapPersonajes[i]["ancho"] = ancho_personaje_default;
			}

			if(personajeDefault){
				// TODO LOGUEAR PORQUESE TOMA EL VALOR DEFAULT
				mapPersonajes[i]["rutaArchivoImagen"] = ruta_imagen_personaje_default;
			}
			else{
				if(!FileHelper::archivoEsValido(mapPersonajes[i]["rutaArchivoImagen"])
					|| !FileHelper::archivoEsImagen(mapPersonajes[i]["rutaArchivoImagen"])){
					// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULT
					mapPersonajes[i]["rutaArchivoImagen"] = ruta_imagen_personaje_default;
					mapPersonajes[i]["nombre"] = nombre_personaje_default;
				}
			}

			if(!StringHelper::esUnNumero(mapPersonajes[i]["zIndex"])){
				// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULT
				mapPersonajes[i]["zIndex"] = zIndex_personaje_default;
			}
		}

		if(cantidad_minima_personajes_default > mapPersonajes.size()){
			for(unsigned int i = mapPersonajes.size(); i < cantidad_minima_personajes_default; i++){
				mapPersonajes[i]["nombre"] = nombre_personaje_default;
				mapPersonajes[i]["alto"] = alto_personaje_default;
				mapPersonajes[i]["ancho"] = ancho_personaje_default;
				mapPersonajes[i]["rutaArchivoImagen"] = ruta_imagen_personaje_default;
				mapPersonajes[i]["zIndex"] = zIndex_personaje_default;
			}
		}
	}

	//Fondo Pantalla
	if(this->mapFondoPantalla.size() == 0){
		// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULTs
		parserArchivoDefault->devolver_Map_Fondo(&mapFondoPantalla);
	}
	else{
		for (unsigned int i = 0; i < mapFondoPantalla.size(); i++){

			if(!FileHelper::archivoEsValido(mapFondoPantalla[i]["rutaArchivoImagen"])
				|| !FileHelper::archivoEsImagen(mapFondoPantalla[i]["rutaArchivoImagen"])){
				// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULT
				mapFondoPantalla[i]["rutaArchivoImagen"] = ruta_imagen_fondoPantalla_default;
			}

			if(!StringHelper::esUnNumero(mapPersonajes[i]["zIndex"])){
				// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULT
				mapPersonajes[i]["zIndex"] = zIndex_fondoPantalla_default;
			}
		}
	}

	//Nivel
	if(this->mapNivel.size() == 0){
		// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULTs
		parserArchivoDefault->devolver_Map_Nivel(&mapNivel);
	}
	else{
		if(!StringHelper::esUnNumero(mapNivel["alto"]) || NumericHelper::parseStringToInt(mapNivel["alto"]) <= 0){
			// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULT
			mapNivel["alto"] = alto_nivel_default;
		}

		if(!StringHelper::esUnNumero(mapNivel["ancho"]) || NumericHelper::parseStringToInt(mapNivel["ancho"]) <= 0){
			// TODO LOGUEAR QUE SE TOMA EL VALOR DEFAULT
			mapNivel["ancho"] = ancho_nivel_default;
		}
	}

}

