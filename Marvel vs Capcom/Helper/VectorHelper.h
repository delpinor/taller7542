/*
 * VectorHelper.h
 *
 *  Created on: Apr 12, 2019
 *      Author: dev73
 */

#ifndef HELPER_VECTORHELPER_H_
#define HELPER_VECTORHELPER_H_

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class VectorHelper {

private:
	VectorHelper() {}

public:
	static bool contiene(std::vector<string> *nombresPersonajes, std::string valor);
	//virtual ~StringHelper();
};

#endif /* HELPER_VECTORHELPER_H_ */
