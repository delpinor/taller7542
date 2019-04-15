/*
 * Logger.cpp
 *
 *  Created on: 26 mar. 2019
 *      Author: delpinor
 */

#include "Logger.h"
#include <plog/Appenders/ConsoleAppender.h>
#include "EntornoSistema.h"
#define NOMBRE_ARCHIVO "mvc.log"
Logger *Logger::instancia = NULL;
LOGGER_NIVEL Logger::nivelSeveridad = LOGGER_NIVEL::ERROR;
LOGGER_SALIDA Logger::salidaPor = LOGGER_SALIDA::ARCHIVO;

Logger::Logger(){

}
Logger::Logger(LOGGER_NIVEL nivel, LOGGER_SALIDA salida){
	static plog::RollingFileAppender<plog::FormatoSalida> fileAppender(NOMBRE_ARCHIVO);
	static plog::ConsoleAppender<plog::FormatoSalida> consoleAppender;
	if(salida == LOGGER_SALIDA::ARCHIVO){
		plog::init(GetSeveridad(nivel), &fileAppender);
	}else{
		plog::init(GetSeveridad(nivel), &consoleAppender);
	}

}
void Logger::Cambiar_nivelLog(LOGGER_NIVEL nivel){

	plog::get()->setMaxSeverity(GetSeveridad(nivel));
}
void Logger::Inicio(LOGGER_NIVEL nivel, LOGGER_SALIDA salida) {
	nivelSeveridad = nivel;
	salidaPor = salida;
	if(instancia == NULL){
		instancia = new Logger(nivel, salida);
	}
}
plog::Severity Logger::GetSeveridad(LOGGER_NIVEL nivel){
	plog::Severity plogSeveridad;
	switch(nivel){
	case LOGGER_NIVEL::DEBUG:
		plogSeveridad = plog::Severity::debug;
		break;
	case LOGGER_NIVEL::INFO:
		plogSeveridad = plog::Severity::info;
		break;
	case LOGGER_NIVEL::ERROR:
		plogSeveridad = plog::Severity::error;
		break;
	default:
		plogSeveridad = plog::Severity::error;

	}
	return plogSeveridad;
}
void Logger::Log(LOGGER_NIVEL nivel, std::string modulo, std::string mensaje){
	plog::Severity severidad=GetSeveridad(nivel);
	if (severidad<=plog::get()->getMaxSeverity()){
		LOG(GetSeveridad(nivel))<<"[" << EntornoSistema::getUserName() << "]" << "[" + modulo + "]"<< "[" << mensaje << "]";
	}
}


