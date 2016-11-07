#include <cstring>
#include <vector>
#include "stdio.h"
#include <cstdlib>

#ifndef LONG_ARITHMETIC_LONGARITHMETIC_H
#define LONG_ARITHMETIC_LONGARITHMETIC_H
using namespace std;

class Bignum {

private:
    /*A base of the system*/
    const int base = 1000*1000*1000;
    /*Operands to perform operations with*/
    vector<int> a, b;
    /*A temporary value for some methods*/
    int carry;

    /*Check whether or not a given vector is negative*/
    inline bool checkNegative(vector<int> formalVector) {

        for(int i = formalVector.size()-1; i >= 0; i--)
            if(formalVector[i] < 0)
                return true;

        return false;
    }

    /*Compare given vectors*/
    int compare(vector<int> a, vector<int> b) {
        if (a.size() > b.size())
            return 1;
        else if (a.size() < b.size())
            return 0;
        for (int i = a.size()-1, j = b.size()-1; i >= 0, j >= 0; i--, j--) {
            if (a[i] > b[i])
                return 1;
            else if (a[i] < b[i])
                return -1;
        }
        return 0;
    }

public:
    /*Default constructor. */
    Bignum();

    /*Constructor with parameters */
    Bignum(string, string);

    /*Copy constructor*/
    Bignum(const Bignum&);

    /*Get a vector*/
    vector<int> getA();

    /*Get b vector */
    vector<int> getB();

    /*Get temporary value*/
    int getCarry();

    /*Add 2 vectors*/
    vector<int> addition(vector<int>, vector<int>);

    /*Subtract 2 vectors*/
    vector<int> subtraction(vector<int>, vector<int>);

    /*Multiply 2 vectors*/
    vector<int> multiplication(vector<int>, vector<int>);

    /*Divide vector by number*/
    vector<int> division(vector<int>, int);

    /*Get arithmetic root of vector a*/
    void involution();

    /*Raise vector a to a positive power*/
    void evolution(int);

    /*Print vector*/
    void print(vector<int>);

    /*Print vector with carry*/
    void print(vector<int>, int);

    /*Destructor of class*/
    ~Bignum();
};

#endif //LONG_ARITHMETIC_LONGARITHMETIC_H
