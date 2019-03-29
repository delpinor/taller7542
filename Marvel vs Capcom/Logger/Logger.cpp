/*
 * Logger.cpp
 *
 *  Created on: 26 mar. 2019
 *      Author: delpinor
 */

#include "Logger.h"
#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/PatternLayout.hh"
#include "log4cpp/Priority.hh"
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <iostream>
#include "EntornoSistema.h"
Logger *Logger::instancia = NULL;
NIVEL_LOGGER Logger::nivel = NIVEL_LOGGER::DEBUG;

void Logger::Inicio(NIVEL_LOGGER nivelMensaje) {
	nivel = nivelMensaje;

	if (instancia == NULL) {
		instancia = new Logger(nivelMensaje);
	}
	//return instancia;
}
void Logger::Log(NIVEL_LOGGER nivelMensaje, std::string modulo,
		const char * mensajeCadena, ...) {
	// Salida por consola
	log4cpp::Appender* creadorDeArchivo = new log4cpp::OstreamAppender(	"console", &std::cout);

	//Salida por archivo
	//log4cpp::Appender* creadorDeArchivo = new log4cpp::FileAppender("default",	"program.log");

	//Layout de salida
	log4cpp::PatternLayout* layoutSalida = new log4cpp::PatternLayout();
	layoutSalida->setConversionPattern("[" + EntornoSistema::getUserName() + "][" + modulo + "][%d{%d-%m-%Y %H:%M:%S}][%p][%t][%m]%n");

	//Seteo el layout al creador de archivo
	creadorDeArchivo->setLayout(layoutSalida);

	log4cpp::Category& root = log4cpp::Category::getRoot();

	root.setPriority(nivel);

	root.addAppender(creadorDeArchivo);
	switch (nivelMensaje) {
	case NIVEL_LOGGER::DEBUG:

		root.debug(mensajeCadena);
		break;
	case NIVEL_LOGGER::INFO:

		root.info(mensajeCadena);
		break;
	case NIVEL_LOGGER::ERROR:

		root.error(mensajeCadena);
		break;
	default:

		root.error(mensajeCadena);

	}

	root.shutdown();
}
;
Logger::Logger(NIVEL_LOGGER nivelMensaje) {
	nivel = nivelMensaje;
}
;
Logger::~Logger() {

}

