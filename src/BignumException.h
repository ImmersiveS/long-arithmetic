//
// Created by User on 12.11.2016.
//

#ifndef LONG_ARITHMETIC_BIGNUMEXCEPTION_H
#define LONG_ARITHMETIC_BIGNUMEXCEPTION_H


#include <iostream>

class BignumException {
public:
    virtual const  void what() const {
        cerr << "BignumException called" << endl;
    }
};


#endif //LONG_ARITHMETIC_BIGNUMEXCEPTION_H
