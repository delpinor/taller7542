/*
 * Configuracion.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: jorge
 */

#include "Configuracion.h"

Configuracion::Configuracion(char* filepath) {
	/* Se carga los personajes disponibles*/


	nombresPersonajes.push_back("captain america");
	nombresPersonajes.push_back("venom");
	nombresPersonajes.push_back("captain america black");
	nombresPersonajes.push_back("venom black");
	nombresPersonajes.push_back("spiderman");
	nombresPersonajes.push_back("spiderman black");
	nombresPersonajes.push_back("chun li");
	nombresPersonajes.push_back("chun li black");
	nombresPersonajes.push_back("default");


	int error;
	ParserConfig parser;

	if(filepath == NULL || filepath[0] == '\0'){
		Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::No se ingreso un archivo " ,"");

		error=parser.parsear_archivo(ruta_archivo_default);
		Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se carga el archivo configuracion default " ,"");
	}else{
		error=parser.parsear_archivo(filepath);
		if (error!=OK){
			Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se carga el archivo configuracion default " ,"");
			error=parser.parsear_archivo(ruta_archivo_default);
		}else{
			Logger::Log(LOGGER_NIVEL::INFO, "Configuracion::Se carga correctamente la configuracion del archivo" ,"");
		}
	}
	parser.devolver_Map_Personajes(&mapPersonajes);
	parser.devolver_Map_Fondo(&mapFondoPantalla);
	parser.devolver_Tam_Imagen(&anchoVentana,&altoVentana);
	parser.devolver_Map_Nivel(&mapNivel);
	this->num_jugadores=parser.devolverNumeroJugadores();
	this->nivelLog = parser.devolver_Tipo_Log();
	this->ValidarConfigs(&nombresPersonajes);

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
		Logger::Log(LOGGER_NIVEL::DEBUG, "Configuracion::Se establace el nivel de log en DEBUG" ,"");
		return DEBUG;
	}else if(this->nivelLog=="ERROR"){
		Logger::Log(LOGGER_NIVEL::DEBUG, "Configuracion::Se establace el nivel de log en ERRO<R" ,"");
		return ERROR;
	}else if (this->nivelLog=="INFO"){
		Logger::Log(LOGGER_NIVEL::DEBUG, "Configuracion::Se establace el nivel de log en INFO" ,"");
		return INFO;}
	else{
		Logger::Log(LOGGER_NIVEL::DEBUG, "Configuracion::No se encuentra el nivel de debug, se establece el logger en nivel DEBUG" ,"");
		return DEBUG;
	};
}
int Configuracion::get_NumJugadores(){

	return this->num_jugadores;

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
void Configuracion::ValidarConfigs(vector<string> *nombresPersonajes){


	//Ventana
	if((!StringHelper::esUnNumero(this->anchoVentana) ) || (NumericHelper::parseStringToInt(this->anchoVentana) <= 0) || (NumericHelper::parseStringToInt(this->anchoVentana) < 600) || (NumericHelper::parseStringToInt(this->anchoVentana) >1200)){
		Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se establace el ancho de ventana default: " ,anchoVentana);
		this->anchoVentana = ancho_ventana_default;
	}

	if((!StringHelper::esUnNumero(this->altoVentana)) || (NumericHelper::parseStringToInt(this->altoVentana) <= 0)
			|| (NumericHelper::parseStringToInt(this->altoVentana) !=600)){
		Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se establace el alto de ventana default: " ,altoVentana);
		this->altoVentana = alto_ventana_default;
	}

	//Personajes  Revisar
	if(this->mapPersonajes.size() == 0){
		ParserConfig parser;
		Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se carga los personnajes del archivo default " ,"");
		parser.parsear_archivo(ruta_archivo_default);
		parser.devolver_Map_Personajes(&mapPersonajes);
	}
	else{

		for (unsigned int i = 0; i < mapPersonajes.size(); i++){

			bool personajeDefault = false;
			if (!VectorHelper::contiene(nombresPersonajes, mapPersonajes[i]["nombre"])){
				personajeDefault = true;

				mapPersonajes[i]["nombre"] = nombre_personaje_default;
				Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se establace el nombre del personaje default: " ,nombre_personaje_default);
			}

			if ((!StringHelper::esUnNumero(mapPersonajes[i]["alto"])) || (NumericHelper::parseStringToInt(mapPersonajes[i]["alto"]) <= 0)
					||(NumericHelper::parseStringToInt(mapPersonajes[i]["alto"]) <100) || (NumericHelper::parseStringToInt(mapPersonajes[i]["alto"]) >300) ){
				Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se establace el alto del personaje default: " ,alto_personaje_default);
				mapPersonajes[i]["alto"] = alto_personaje_default;

			}

			if((!StringHelper::esUnNumero(mapPersonajes[i]["ancho"])) || (NumericHelper::parseStringToInt(mapPersonajes[i]["ancho"]) <= 0)
					|| (NumericHelper::parseStringToInt(mapPersonajes[i]["ancho"]) <50) || (NumericHelper::parseStringToInt(mapPersonajes[i]["ancho"]) >250)){
				Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se establace el ancho del personaje default: " ,ancho_personaje_default);
				mapPersonajes[i]["ancho"] = ancho_personaje_default;
			}

			if(personajeDefault){
				Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se establace la imagen default: " ,ruta_imagen_personaje_default);
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
				Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se establace el zindex default: " ,zIndex_personaje_default);
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
				Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se carga un persoanje default: " ,nombre_personaje_default);
			}
		}
	}

	//Fondo Pantalla
	if(this->mapFondoPantalla.size() == 0){
		ParserConfig parser;
		Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se carga lso fondos de pantalla default" ,"");
		parser.devolver_Map_Fondo(&mapFondoPantalla);
	}
	else{
		for (unsigned int i = 0; i < mapFondoPantalla.size(); i++){

			if(!FileHelper::archivoEsValido(mapFondoPantalla[i]["rutaArchivoImagen"])
			|| !FileHelper::archivoEsImagen(mapFondoPantalla[i]["rutaArchivoImagen"])){
				Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se carga el fondo de pantalla default" ,ruta_imagen_fondoPantalla_default);
				mapFondoPantalla[i]["rutaArchivoImagen"] = ruta_imagen_fondoPantalla_default;
			}

			if(!StringHelper::esUnNumero(mapPersonajes[i]["zIndex"])){
				Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se carga el zindex de pantalla default" ,zIndex_fondoPantalla_default);
				mapPersonajes[i]["zIndex"] = zIndex_fondoPantalla_default;
			}
		}
	}

	//Nivel
	if(this->mapNivel.size() == 0){
		ParserConfig parser;
		Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::se cargan los nivel de mapas default" ,"");
		parser.devolver_Map_Nivel(&mapNivel);
	}
	else{
		if(!StringHelper::esUnNumero(mapNivel["alto"]) || NumericHelper::parseStringToInt(mapNivel["alto"]) <= 0){
			Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::se cargan el alto nivel de mapas default" ,alto_nivel_default);
			mapNivel["alto"] = alto_nivel_default;
		}

		if(!StringHelper::esUnNumero(mapNivel["ancho"]) || NumericHelper::parseStringToInt(mapNivel["ancho"]) <= 0){
			Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::se cargan el ancho nivel de mapas default" ,ancho_nivel_default);
			mapNivel["ancho"] = ancho_nivel_default;
		}
	}
	char num_str[4];
	if(num_jugadores>MAXIMO_JUGADORES) {

		sprintf(num_str, "%d", num_jugadores);
		Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::El numero de jugadores supera al maximo " ,num_str );

		sprintf(num_str, "%d", NUM_JUGADORES_DEFAUT);
		Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se carga el numero de jugadores default " ,num_str );
		num_jugadores = NUM_JUGADORES_DEFAUT;

	}else if ((num_jugadores<2)){
		sprintf(num_str, "%d", num_jugadores);
		Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::El numero de es inferior al minimo" ,num_str );

		sprintf(num_str, "%d", NUM_JUGADORES_DEFAUT);
		Logger::Log(LOGGER_NIVEL::ERROR, "Configuracion::Se carga el numero de jugadores default " ,num_str );
		num_jugadores = NUM_JUGADORES_DEFAUT;
	}else{
		sprintf(num_str, "%d", num_jugadores);
		Logger::Log(LOGGER_NIVEL::DEBUG, "Configuracion::Se carga el numero de jugadores ingresado" ,num_str );


	}

}
