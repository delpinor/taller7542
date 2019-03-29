/*
 * EntornoSistema.h
 *
 *  Created on: 26 mar. 2019
 *      Author: delpinor
 */

#include <string.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

class EntornoSistema{
    public:
    static std::string getUserName();
};
