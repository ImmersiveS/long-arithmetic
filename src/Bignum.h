#include <cstring>
#include <vector>
#include "stdio.h"
#include <cstdlib>

#ifndef LONG_ARITHMETIC_LONGARITHMETIC_H
#define LONG_ARITHMETIC_LONGARITHMETIC_H
using namespace std;

/*A base of the system*/
const int base = 1000*1000*1000;
int countDigits(int);
class Bignum
{
private:
    /*Operands to perform operations with*/
    vector<int> data;

    /*Check whether or not a given vector is negative*/
    inline bool checkNegative(vector<int> formalVector) {

        for(int i = formalVector.size()-1; i >= 0; i--)
            if(formalVector[i] < 0)
                return true;

        return false;
    }

    /*Compare given vectors*/
    int compare(const Bignum& a, const Bignum& b);

public:
    /*Default constructor. */
    Bignum() { data.resize(0); }

    /*Constructor with parameters */
    Bignum(string mData);

    /*Copy constructor*/
    Bignum(const Bignum& bignum) : data(bignum.data) {}

    /*Move constructor*/
    Bignum(Bignum&& bignum) : data(move(bignum.data)) {}

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

    /*Comparison operators*/
    bool operator < (const Bignum& other) { return compare((*this), other) == 0; }
    bool operator > (const Bignum& other) { return compare((*this), other) == 1; }
    bool operator <=(const Bignum& other) { return compare((*this), other) % 2 == 0; }
    bool operator >=(const Bignum& other) { return compare((*this), other) >= 1; }
    bool operator ==(const Bignum& other) { return compare((*this), other) == 2; }
    bool operator !=(const Bignum& other) { return compare((*this), other) != 2; }

    Bignum operator -()
    {
        Bignum tmp(*this);
        for(int i = tmp.data.size()-1; i>=0; i--)
            if(tmp[i] != 0) {
                tmp[i] = -tmp[i];
                break;
            }
        return tmp;
    }

    Bignum& operator ++()
    {
        Bignum one("1");
        return (*this) = (*this) + one;
    }
    Bignum operator ++(int) {
        Bignum one("1");
        return (*this) = (*this) + one;
    }
    Bignum& operator --()
    {
        Bignum one("1");
        return (*this) = (*this) - one;
    }
    Bignum operator --(int) {
        Bignum one("1");
        return (*this) = (*this) - one;
    }

    /*Add 2 vectors*/
    Bignum operator +(const Bignum&);

    /*Short addition*/
    Bignum operator +=(const Bignum& other) { return (*this) = (*this) + other; }

    /*Subtract 2 vectors*/
    Bignum operator -(const Bignum&);

    /*Short addition*/
    Bignum operator -=(const Bignum& other) { return (*this) = (*this) - other; }

    /*Multiply 2 vectors*/
    Bignum operator *(const Bignum&);

    /*Short multiplying*/
    Bignum operator *=(const Bignum& other) { return (*this) = (*this) * other; };

    /*Divide vector by number*/
    Bignum operator /(const long long);

    /*Short division*/
    Bignum operator /=(const long other) { return (*this) = (*this) / other; }

    /*Get arithmetic root of vector a*/
    Bignum extractRoot();

    /*Raise vector a to a positive power*/
    Bignum operator ^(int);

    /*Print vector*/
    void print();
};

#endif //LONG_ARITHMETIC_LONGARITHMETIC_H
