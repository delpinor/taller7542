
#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/SimpleLayout.hh"
#include "log4cpp/PatternLayout.hh"

#include "log4cpp/Priority.hh"

int mainnn(int argc, char** argv) {
	 log4cpp::Appender *appender2 = new log4cpp::OstreamAppender("console", &std::cout);
 //log4cpp::Appender *appender2 = new log4cpp::FileAppender("default", "program.log");
 log4cpp::PatternLayout * mypattern = new log4cpp::PatternLayout();
 mypattern->setConversionPattern("%d{%d-%m-%Y %H:%M:%S}[%p] - %c - %m - %r - %t - %n");
 appender2->setLayout(mypattern);
 log4cpp::Category& root = log4cpp::Category::getRoot();

 root.setPriority(log4cpp::Priority::ERROR);


 log4cpp::Category& sub1 = log4cpp::Category::getInstance(std::string("sub1"));
 sub1.addAppender(appender2);

 // use of functions for logging messages
 root.error("root error");
 root.info("root info");
 sub1.error("sub1 error");
 sub1.warn("sub1 warn");

 // printf-style for logging variables
 root.warn("%d + %d == %s ?", 1, 1, "two");

 // use of streams for logging messages
 root << log4cpp::Priority::ERROR << "Streamed root error";
 root << log4cpp::Priority::INFO << "Streamed root info";
 sub1 << log4cpp::Priority::ERROR << "Streamed sub1 error";
 sub1 << log4cpp::Priority::WARN << "Streamed sub1 warn";

 // or this way:
 root.errorStream() << "Another streamed error";

 return 0;
}
