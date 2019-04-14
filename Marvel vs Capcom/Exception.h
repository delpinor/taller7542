/*
 * Exception.h
 *
 *  Created on: Apr 4, 2019
 *      Author: jorge
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_
#include <string>
#include <iostream>
#include <exception>

/* clase Exception generica*/

class Exception: public std::exception {
private:
	std::string inicio;
	   std::string id;
	   std::string fin;

public:
	   /* en el constructor le ingreso como parametros
	    * el comienzo , la mitad y el fin del mensaje*/
	   Exception(char* ini,char* valor, char* fi): inicio(ini), id(valor),fin(fi){}

	   /* Metodo que imprime por pantalla el mensaje de error */
	   std::string what()  noexcept;
	   virtual ~Exception();
};


/*
class Error_Juego: public std::exception {
private:
	//std::string inicio;
	  // std::string id;
	   //std::string fin;
	 std::string error_message;

public:




	 	 explicit Error_Juego( const std::string& msg): error_message(msg){}
	 	 const char* what() const throw ()
	 	{ return error_message.c_str();
	 	}

	   // en el constructor le ingreso como parametros
	     el comienzo , la mitad y el fin del mensaje
	 //  Exception(const char* ini,const char* valor,
		//	   const char* fi): inicio(ini), id(valor),fin(fi){}

	   // Metodo que imprime por pantalla el mensaje de error
	 //  virtual std::string what()  noexcept;

	  // virtual std::string what()  throw();

	   virtual ~Error_Juego() throw() {}
};*/

#endif /* EXCEPTION_H_ */


