//
// Created by user on 14.11.2016.
//

#ifndef LONG_ARITHMETIC_OVERFLOWEXCEPTION_H
#define LONG_ARITHMETIC_OVERFLOWEXCEPTION_H


#include "BignumException.h"

class OverflowException : public BignumException {
public:
    const void what() const { std::cerr << "\nThe value is bigger than MAX_INT or less than MIN_INT" << std::endl;}
};


#endif //LONG_ARITHMETIC_OVERFLOWEXCEPTION_H
