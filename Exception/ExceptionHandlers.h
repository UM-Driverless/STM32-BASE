/*
 * exceptions.h
 *
 *  Created on: Apr 29, 2023
 *      Author: alvar
 */

#ifndef SRC_EXCEPTIONHANDLERS_H_
#define SRC_EXCEPTIONHANDLERS_H_

#include <exception>
#include "exceptionList.h"

class CANException : public std::exception {
    private:
	char * message;

    public:
    CANException(int code) {}
    char * what () {
        return message;
    }
};

#endif /* SRC_EXCEPTIONHANDLERS_H_ */
