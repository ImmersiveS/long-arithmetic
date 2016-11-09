#include <iostream>
#include "Bignum.h"

Bignum::Bignum(string mData)
{
    len = mData.length();
    for (int i = mData.length(); i > 0; i -= 9)
        if (i < 9)
            data.push_back(atoi(mData.substr(0, i).c_str()));
        else
            data.push_back(atoi(mData.substr(i - 9, 9).c_str()));
    while (data.size() > 1 && data.back() == 0)
        data.pop_back();
}

void Bignum::print() {
    printf ("%d", data.empty() ? 0 : data.back());
    for (int i=(int)data.size()-2; i>=0; --i)
        printf ("%09d", data[i]);
    printf("\n");
}

Bignum Bignum::operator +(const Bignum& other)
{
    Bignum sum = *this;
    int carry = 0;

    for (size_t i = 0; i < max( sum.data.size(), other.data.size()) || carry; ++i) {
        if (i == sum.data.size())
            sum.data.push_back (0);
        sum[i] += carry + (i < other.data.size() ? other.data[i] : 0);
        carry = sum[i] >= base;
        if (carry)  sum[i] -= base;
    }
    return sum;
}

Bignum Bignum::operator -(const Bignum& other)
{
    Bignum sub;
    int carry = 0;

   if ((*this) > other) {
        sub = *this;
        for (size_t i = 0; i < other.data.size() || carry; ++i) {
            sub[i] -= carry + (i < other.data.size() ? other.data[i] : 0);
            carry = sub[i] < 0;
            if (carry) sub[i] += base;
        }
        while (sub.data.size() > 1 && sub.data.back() == 0)
            sub.data.pop_back();
    }
    else {
        sub = other;
        for (size_t i = 0; i < (*this).data.size() || carry; ++i) {
            sub[i] -= carry + (i < (*this).data.size() ? (*this)[i] : 0);
            carry = sub[i] < 0;
            if (carry) sub[i] += base;
        }

        while (sub.data.size() > 1 && sub.data.back() == 0)
            sub.data.pop_back();

        for(int i = sub.data.size()-1; i>=0; i--)
            if(sub[i] != 0) {
                sub[i] = sub[i] - 2*sub[i];
                break;
            }
    }
    return sub;
}

Bignum Bignum::operator *(const Bignum& other)
{
    Bignum multi;
    multi.data.resize((*this).data.size() + other.data.size());

    for ( size_t i = 0; i < (*this).data.size(); ++i )
        for ( int j = 0, carry = 0; j < static_cast<int>(other.data.size()) || carry; ++j) {
            long long cur = multi[i+j] + (*this)[i] * 1ll * (j < static_cast<int>(other.data.size()) ? other.data[j] : 0 ) + carry;
            multi[i+j] = static_cast<int>(cur % base);
            carry = static_cast<int>(cur / base);
        }
    while ( multi.data.size() > 1 && multi.data.back() == 0)
        multi.data.pop_back();
    return multi;
}
//
//Bignum Bignum::operator /(const Bignum &)
//{
//    if (shortB == 0)
//        throw "Error";
//
//    carry = 0;
//    vector<int> div(a);
//
//    for (int i=(int)div.size()-1; i>=0; --i) {
//        long long cur = div[i] + carry * 1ll * base;
//        div[i] = int (cur / shortB);
//        carry = int (cur % shortB);
//    }
//    if (carry < 0)
//        carry = carry - 2 * carry;
//    while (div.size() > 1 && div.back() == 0)
//        div.pop_back();
//    return div;
//}
//
//void Bignum::evolution(int power) {
//    vector<int> basis = data, result = data;
//
//    if (power < 0)
//        throw "Error";
//    else if (power == 0)
//        cout << 1 << endl;
//    else {
//        while (power--)
//            result = multiplication(result, basis);
//        print(result);
//    }
//}
//
//
//void Bignum::involution() {
//    if (checkNegative(data))
//        throw "Error";
//    vector<int> l(0);
//    l.push_back(0);
//    vector<int> r(data), res;
//     string one = "1";
//     string two = "2";
//    Bignum longArithmetic(one,two);
//
//    while (longArithmetic.compare(l,r) == -1 || longArithmetic.compare(l,r) == 0)
//    {
//        vector<int> m = longArithmetic.division(longArithmetic.addition(l,r),longArithmetic.getB()[longArithmetic.getB().size()-1]);
//        if (longArithmetic.compare(longArithmetic.multiplication(m,m),data) == -1 || longArithmetic.compare(longArithmetic.multiplication(m,m),data) == 0)
//        {
//            res = m;
//            l = longArithmetic.addition(m, longArithmetic.getA());
//        }
//        else
//            r = longArithmetic.subtraction(m, longArithmetic.getA());
//    }
//    print(res);
//}
