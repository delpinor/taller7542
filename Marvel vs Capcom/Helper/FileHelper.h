/*
 * FileHelper.h
 *
 *  Created on: Apr 13, 2019
 *      Author: dev73
 */

#ifndef HELPER_FILEHELPER_H_
#define HELPER_FILEHELPER_H_

#include <string>
#include <fstream>
using namespace std;

class FileHelper {

private:
	FileHelper() {}

public:
	static std::string getExtensionArchivo(std::string rutaArchivo);
	static bool archivoEsValido(std::string rutaArchivo);
	static bool archivoEsImagen(std::string rutaArchivo);
	//virtual ~NumericHelper();
};




#endif /* HELPER_FILEHELPER_H_ */
