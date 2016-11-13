//
// Created by User on 13.11.2016.
//

#ifndef LONG_ARITHMETIC_NEGATIVEROOTEXCEPTION_H
#define LONG_ARITHMETIC_NEGATIVEROOTEXCEPTION_H

#include "BignumException.h"

class NegativeRootException : public BignumException{
public:
    void what() { std::cout << "\nError, caught obtaining arithmetical root of negative number" << std::endl;}
};

#endif //LONG_ARITHMETIC_NEGATIVEROOTEXCEPTION_H
