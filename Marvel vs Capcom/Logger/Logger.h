/*
 * Logger.h
 *
 *  Created on: 26 mar. 2019
 *      Author: delpinor
 */
#include "log4cpp/Category.hh"
#include <iostream>
#ifndef LOGGER_H_
#define LOGGER_H_
enum NIVEL_LOGGER{DEBUG = 700 , INFO = 600, ERROR = 300};
class Logger{
private:
	// Default ERROR
	static NIVEL_LOGGER nivel;
	static Logger * instancia;
	Logger(NIVEL_LOGGER nivel);
public:
	static log4cpp::Category rootCat;
	static void Inicio(NIVEL_LOGGER nivel);
	static void Log(NIVEL_LOGGER nivelMensaje, std::string modulo, const char * stringFormat, ...);
//	static void Log(NIVEL_LOGGER nivelMensaje, std::string modulo,const char* stringFormat, ...);
	~Logger();

};
#endif /* LOGGER_H_ */
