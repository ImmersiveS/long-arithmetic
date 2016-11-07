#include <iostream>
#include "Bignum.h"

Bignum::Bignum(string mData)
{
    Bignum();
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

Bignum& Bignum::operator+(const Bignum& b) {
    int carry = 0;

    for (size_t i = 0; i < max( (*this).data.size(), b.data.size()) || carry; ++i) {
        if (i == (*this).data.size())
            (*this).data.push_back (0);
        (*this)[i] += carry + (i < b.data.size() ? b.data[i] : 0);
        carry = (*this)[i] >= base;
        if (carry)  (*this)[i] -= base;
    }
    return *this;
}

//vector<int> Bignum::subtraction(vector<int> a, vector<int> b) {
//    int carry = 0;
//    vector<int> sub;
//
//   if (compare(a, b) == 1) {
//        sub = a;
//        for (size_t i = 0; i < b.size() || carry; ++i) {
//            sub[i] -= carry + (i < b.size() ? b[i] : 0);
//            carry = sub[i] < 0;
//            if (carry) sub[i] += base;
//        }
//        while (sub.size() > 1 && sub.back() == 0)
//            sub.pop_back();
//    }
//    else {
//        sub = b;
//        for (size_t i = 0; i < a.size() || carry; ++i) {
//            sub[i] -= carry + (i < a.size() ? a[i] : 0);
//            carry = sub[i] < 0;
//            if (carry) sub[i] += base;
//        }
//
//        while (sub.size() > 1 && sub.back() == 0)
//            sub.pop_back();
//
//        for(int i = sub.size()-1; i>=0; i--)
//            if(sub[i] != 0) {
//                sub[i] = sub[i] - 2*sub[i];
//                break;
//            }
//    }
//    return sub;
//}
//
//vector<int> Bignum::multiplication(vector<int> a, vector<int> b) {
//
//    vector<int> c (a.size()+b.size());
//
//    for (size_t i=0; i<a.size(); ++i)
//        for (int j=0, carry=0; j<(int)b.size() || carry; ++j) {
//            long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
//            c[i+j] = int (cur % base);
//            carry = int (cur / base);
//        }
//    while (c.size() > 1 && c.back() == 0)
//        c.pop_back();
//    return c;
//}

//vector<int> Bignum::division(vector<int> a, int shortB) {
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

Bignum::~Bignum() {}
