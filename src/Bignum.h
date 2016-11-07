#include <cstring>
#include <vector>
#include "stdio.h"
#include <cstdlib>

#ifndef LONG_ARITHMETIC_LONGARITHMETIC_H
#define LONG_ARITHMETIC_LONGARITHMETIC_H
using namespace std;

/*A base of the system*/
const int base = 1000*1000*1000;

class Bignum
{
private:
    /*Operands to perform operations with*/
    vector<int> data;
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
    Bignum() { data.resize(0); }

    /*Constructor with parameters */
    Bignum(string mData);

    /*Copy constructor*/
    Bignum(const Bignum& bignum) { data = bignum.data; }

    /*Move constructor*/
    Bignum(Bignum&& bignum) : data( move(bignum.data) )
    {}

    /*Geeter of data*/
    vector<int> getData() { return data; }

    /*Assigning operator*/
    Bignum& operator=(const Bignum& other)
    {
        data = other.data;
        return *this;
    }

    /*Array subscription*/
    int& operator[](int index) { return data[index]; }

    /*Add 2 vectors*/
    Bignum& operator+(const Bignum&);

    Bignum& operator+=(const Bignum& other) { return (*this) + other; }

//    /*Subtract 2 vectors*/
//    vector<int> subtraction(vector<int>, vector<int>);
//
//    /*Multiply 2 vectors*/
//    vector<int> multiplication(vector<int>, vector<int>);
//
//    /*Divide vector by number*/
//    vector<int> division(vector<int>, int);
//
//    /*Get arithmetic root of vector a*/
//    void involution();
//
//    /*Raise vector a to a positive power*/
//    void evolution(int);

    /*Print vector*/
    void print();

    /*Destructor of class*/
    ~Bignum();
};

#endif //LONG_ARITHMETIC_LONGARITHMETIC_H
