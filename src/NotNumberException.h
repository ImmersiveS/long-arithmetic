//
// Created by User on 12.11.2016.
//

#ifndef LONG_ARITHMETIC_NOTNUMBEREXCEPTION_H
#define LONG_ARITHMETIC_NOTNUMBEREXCEPTION_H


#include "BignumException.h"

class NotNumberException : public BignumException
{
public:
    const void what() const { cerr << "\nError, received inappropriate data" << endl; }
};


#endif //LONG_ARITHMETIC_NOTNUMBEREXCEPTION_H
