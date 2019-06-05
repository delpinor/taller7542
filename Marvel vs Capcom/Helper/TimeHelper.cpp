/*
 * TimeHelper.cpp
 *
 *  Created on: May 30, 2019
 *      Author: dev73
 */
#include "TimeHelper.h"

char* TimeHelper::getStringLocalTimeNow(){
	time_t now = time(0);
	char* dt = ctime(&now);
	return dt;
}



