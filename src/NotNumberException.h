//
// Created by User on 12.11.2016.
//

#ifndef LONG_ARITHMETIC_NOTNUMBEREXCEPTION_H
#define LONG_ARITHMETIC_NOTNUMBEREXCEPTION_H


#include "BignumException.h"

class NotNumberException : public BignumException {
public:
    NotNumberException() { std::cin.clear(); while (std::cin.get() != '\n'); }
    void what() {
        std::cout << "Expected 'int' but received 'char'" << std::endl;
    }
};


#endif //LONG_ARITHMETIC_NOTNUMBEREXCEPTION_H
