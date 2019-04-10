/*
 * Logger.h
 *
 *  Created on: 26 mar. 2019
 *      Author: delpinor
 */

#include <plog/Log.h>
#include "EntornoSistema.h"
enum LOGGER_SALIDA{CONSOLA = 1, ARCHIVO = 2};

enum LOGGER_NIVEL{DEBUG = 5 , INFO = 4, ERROR = 65};
class Logger{
private:
	// Default ERROR
	static LOGGER_NIVEL nivelSeveridad;
	static LOGGER_SALIDA salidaPor;
	static Logger * instancia;
	Logger(LOGGER_NIVEL nivel, LOGGER_SALIDA salida);
	static plog::Severity GetSeveridad(LOGGER_NIVEL);
public:
	static void Inicio(LOGGER_NIVEL nivel, LOGGER_SALIDA salida);
	static void Log(LOGGER_NIVEL NIVEL, std::string modulo , std::string mensaje);
	~Logger();

};
namespace plog
{
    class FormatoSalida
    {
    public:
        static util::nstring header()
        {
            return util::nstring();
        }

        static util::nstring format(const Record& record)
        {
        	bool useUtcTime = false;
        	 tm t;
        	            (useUtcTime ? util::gmtime_s : util::localtime_s)(&t, &record.getTime().time);
        	util::nostringstream ss;


            ss << "[" <<t.tm_year + 1900 << "-" << std::setfill(PLOG_NSTR('0')) << std::setw(2) << t.tm_mon + 1 << PLOG_NSTR("-") << std::setfill(PLOG_NSTR('0')) << std::setw(2) << t.tm_mday ;
            ss << std::setfill(PLOG_NSTR('0')) << std::setw(2) << " " << t.tm_hour << PLOG_NSTR(":") << std::setfill(PLOG_NSTR('0')) << std::setw(2) << t.tm_min << PLOG_NSTR(":") << std::setfill(PLOG_NSTR('0')) << std::setw(2) << t.tm_sec << "]";
            ss << "[" <<severityToString(record.getSeverity()) << "]";

            ss << record.getMessage() << PLOG_NSTR("\n");

            return ss.str();
        }
    };
}



