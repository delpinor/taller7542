/*
 * NumericHelper.h
 *
 *  Created on: Apr 12, 2019
 *      Author: dev73
 */

#ifndef HELPER_NUMERICHELPER_H_
#define HELPER_NUMERICHELPER_H_

#include <string>
#include <sstream>
using namespace std;

class NumericHelper {

private:
	NumericHelper() {}

public:
	static int parseStringToInt(std::string valor);
	//virtual ~NumericHelper();
};



#endif /* HELPER_NUMERICHELPER_H_ */
