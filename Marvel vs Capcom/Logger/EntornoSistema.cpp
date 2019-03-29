/*
 * EntornoSistema.cpp
 *
 *  Created on: 26 mar. 2019
 *      Author: delpinor
 */

#include "EntornoSistema.h"
#include <iostream>

std::string EntornoSistema::getUserName(){
        uid_t uid = geteuid ();
        struct passwd *pw = getpwuid (uid);
        if (pw)
        {
            return std::string(pw->pw_name);
        }
        return {};
}
