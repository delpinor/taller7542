/*
 * FileHelper.cpp
 *
 *  Created on: Apr 13, 2019
 *      Author: dev73
 */


#include "FileHelper.h"
#include "StringHelper.h"

std::string FileHelper::getExtensionArchivo(std::string rutaArchivo){
	size_t i = rutaArchivo.rfind('.', rutaArchivo.length());
	if (i != string::npos) {
		return(rutaArchivo.substr(i + 1, rutaArchivo.length() - i));
	}

	return("");
}

bool FileHelper::archivoEsValido(std::string rutaArchivo){
	std::ifstream file;
	file.open(rutaArchivo);
	if(file){
		//file.close();
		return true;
	}
	else{
		return false;
	}
}

bool FileHelper::archivoEsImagen(std::string rutaArchivo){

	std::string extension = FileHelper::getExtensionArchivo(rutaArchivo);
	extension = StringHelper::toLower(extension);

	if(extension == "jpeg"
		|| extension == "jpg"
		|| extension == "png"
		|| extension == "gif"
		|| extension == "tiff"
		|| extension == "tif"
		|| extension == "raw"
		|| extension == "bmp"
		|| extension == "psd"){
		return true;
	}
	else{
		return false;
	}
}

