//
// Created by User on 13.11.2016.
//

#ifndef LONG_ARITHMETIC_OUTOFBOUNDSEXCEPTION_H
#define LONG_ARITHMETIC_OUTOFBOUNDSEXCEPTION_H


#include "BignumException.h"

class OutOfBoundsException : public BignumException {
public:
    void what() { cerr << "Error, big number can't have more than 30 "
                "digits and for power - more than 4" << endl;}
};


#endif //LONG_ARITHMETIC_OUTOFBOUNDSEXCEPTION_H
