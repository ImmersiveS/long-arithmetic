//
// Created by User on 13.11.2016.
//

#ifndef LONG_ARITHMETIC_OUTOFBOUNDSEXCEPTION_H
#define LONG_ARITHMETIC_OUTOFBOUNDSEXCEPTION_H


#include "BignumException.h"

class OutOfBoundsException : public BignumException {
public:
    const void what() const
    {
        cerr << "\nError, big number can't have more than 40 "
                "digits and for power - more than 3" << endl;
    }
};


#endif //LONG_ARITHMETIC_OUTOFBOUNDSEXCEPTION_H
