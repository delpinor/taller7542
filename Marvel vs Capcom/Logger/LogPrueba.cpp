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
#include "EntornoSistema.h"

// DEBUG > INFO > ERROR

int temp() {



	// Salida por consola
	log4cpp::Appender* creadorDeArchivo = new log4cpp::OstreamAppender("console",	&std::cout);


	// Salida por archivo
	//log4cpp::Appender* creadorDeArchivo = new log4cpp::FileAppender("default",	"program.log");

	//Layout de salida
	log4cpp::PatternLayout* layoutSalida = new log4cpp::PatternLayout();


	layoutSalida->setConversionPattern("%d{%d-%m-%Y %H:%M:%S}[%p][%c][%t][%m]%n");

	//Seteo el layout al creador de archivo
	creadorDeArchivo->setLayout(layoutSalida);

	log4cpp::Category& root = log4cpp::Category::getRoot();
	root.setPriority(log4cpp::Priority::ERROR);
	root.addAppender(creadorDeArchivo);

	log4cpp::Category& sub1 = log4cpp::Category::getInstance(std::string("sub1"));
	sub1.setPriority(log4cpp::Priority::ERROR);

	//sub1.addAppender(appender2);

	// use of functions for logging messages
	/*
	root.error("root error");
	root.info("root info");
	root.debug("root debug");
*/
	sub1.error("");
	sub1.info("root info");
	sub1.debug("root debug");

	sub1.error("%d + %d == %s ?", 1, 1, "two");

	// printf-style for logging variables
	//root.error("%d", 1, 1, "two");

	// printf-style for logging variables
	root.warn("%d + %d == %s ?", 1, 1, "two");

	// use of streams for logging messages
	/*
	root << log4cpp::Priority::ERROR << "Streamed root error";
	root << log4cpp::Priority::INFO << "Streamed root info";
	sub1 << log4cpp::Priority::ERROR << "Streamed sub1 error";
	sub1 << log4cpp::Priority::WARN << "Streamed sub1 warn";

	// or this way:
	root.errorStream() << "Another streamed error";

	 */
	return 0;
}
