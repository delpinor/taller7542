/*
 * StringHelper.h
 *
 *  Created on: Apr 9, 2019
 *      Author: dev73
 */

#ifndef HELPER_STRINGHELPER_H_
#define HELPER_STRINGHELPER_H_

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class StringHelper {

private:
	StringHelper() {}

public:
	static bool esUnNumero(std::string valor);
	static std::string toLower(std::string);
	//virtual ~StringHelper();
};





#endif /* HELPER_STRINGHELPER_H_ */
