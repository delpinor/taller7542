/*
 * TimeHelper.h
 *
 *  Created on: May 30, 2019
 *      Author: dev73
 */

#ifndef HELPER_TIMEHELPER_H_
#define HELPER_TIMEHELPER_H_

#include<ctime>
#include <string>
using namespace std;

class TimeHelper {

private:
	TimeHelper() {}

public:
	static char* getStringLocalTimeNow();
	//virtual ~StringHelper();
};


#endif /* HELPER_TIMEHELPER_H_ */
