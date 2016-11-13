//
// Created by User on 13.11.2016.
//

#ifndef LONG_ARITHMETIC_ZERODIVIDE_H
#define LONG_ARITHMETIC_ZERODIVIDE_H


#include "BignumException.h"

class ZeroDivideException : public BignumException{
public:
    void what() { cerr << "\nError, caught division by zero" << endl;}
};


#endif //LONG_ARITHMETIC_ZERODIVIDE_H
