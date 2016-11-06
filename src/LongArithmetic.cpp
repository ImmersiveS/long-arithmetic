#include <iostream>
#include "LongArithmetic.h"

LongArithmetic::LongArithmetic() {
    a.resize(0);
    b.resize(0);
}

LongArithmetic::LongArithmetic(string formalA, string formalB) {
    LongArithmetic();
    for (int i=(int)formalA.length(); i>0; i-=9)
        if (i < 9)
            a.push_back (atoi (formalA.substr (0, i).c_str()));
        else
            a.push_back (atoi (formalA.substr (i-9, 9).c_str()));
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    for (int i=(int)formalB.length(); i>0; i-=9)
        if (i < 9)
            b.push_back (atoi (formalB.substr (0, i).c_str()));
        else
            b.push_back (atoi (formalB.substr (i-9, 9).c_str()));
    while (b.size() > 1 && b.back() == 0)
        b.pop_back();
}

LongArithmetic::LongArithmetic(const LongArithmetic& longArithmetic) {
    a = longArithmetic.a;
    b = longArithmetic.b;

    for(int i = a.size()-1; i>=0; i--)
        if(a[i] != 0) {
            a[i] = a[i] - 2*a[i];
            break;
        }

    for(int i = b.size()-1; i>=0; i--)
        if(b[i] != 0) {
            b[i] = b[i] - 2*b[i];
            break;
        }
}

vector<int> LongArithmetic::getA() {
        return a;
}

vector<int> LongArithmetic::getB() {
        return b;
}

void LongArithmetic::print(vector<int> arr) {
    printf ("%d", arr.empty() ? 0 : arr.back());
    for (int i=(int)arr.size()-2; i>=0; --i)
        printf ("%09d", arr[i]);
    printf("\n");
}

vector<int> LongArithmetic::addition(vector<int> a, vector<int> b) {
    vector<int> sum = a;
    int carry = 0;

    for (size_t i=0; i<max(sum.size(),b.size()) || carry; ++i) {
        if (i == sum.size())
            sum.push_back (0);
        sum[i] += carry + (i < b.size() ? b[i] : 0);
        carry = sum[i] >= base;
        if (carry)  sum[i] -= base;
    }
    return sum;
}

vector<int> LongArithmetic::subtraction(vector<int> a, vector<int> b) {
    int carry = 0;
    vector<int> sub;

   if (compare(a, b) == 1) {
        sub = a;
        for (size_t i = 0; i < b.size() || carry; ++i) {
            sub[i] -= carry + (i < b.size() ? b[i] : 0);
            carry = sub[i] < 0;
            if (carry) sub[i] += base;
        }
        while (sub.size() > 1 && sub.back() == 0)
            sub.pop_back();
    }
    else {
        sub = b;
        for (size_t i = 0; i < a.size() || carry; ++i) {
            sub[i] -= carry + (i < a.size() ? a[i] : 0);
            carry = sub[i] < 0;
            if (carry) sub[i] += base;
        }

        while (sub.size() > 1 && sub.back() == 0)
            sub.pop_back();

        for(int i = sub.size()-1; i>=0; i--)
            if(sub[i] != 0) {
                sub[i] = sub[i] - 2*sub[i];
                break;
            }
    }
    return sub;
}

vector<int> LongArithmetic::multiplication(vector<int> a, vector<int> b) {

    vector<int> c (a.size()+b.size());

    for (size_t i=0; i<a.size(); ++i)
        for (int j=0, carry=0; j<(int)b.size() || carry; ++j) {
            long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
            c[i+j] = int (cur % base);
            carry = int (cur / base);
        }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}

int LongArithmetic::getCarry() {
    return carry;
}

void LongArithmetic::print(vector<int> arr, int carry) {
    printf ("%d", arr.empty() ? 0 : arr.back());
    for (int i=(int)arr.size()-2; i>=0; --i)
        printf ("%09d", arr[i]);
    printf(".%d\n", carry);
}

vector<int> LongArithmetic::division(vector<int> a, int shortB) {
    if (shortB == 0)
        throw "Error";

    carry = 0;
    vector<int> div(a);

    for (int i=(int)div.size()-1; i>=0; --i) {
        long long cur = div[i] + carry * 1ll * base;
        div[i] = int (cur / shortB);
        carry = int (cur % shortB);
    }
    if (carry < 0)
        carry = carry - 2 * carry;
    while (div.size() > 1 && div.back() == 0)
        div.pop_back();
    return div;
}

void LongArithmetic::evolution(int power) {
    vector<int> basis = a, result = a;

    if (power < 0)
        throw "Error";
    else if (power == 0)
        cout << 1 << endl;
    else {
        while (power--)
            result = multiplication(result, basis);
        print(result);
    }
}


void LongArithmetic::involution() {
    if (checkNegative(a))
        throw "Error";
    vector<int> l(0);
    l.push_back(0);
    vector<int> r(a), res;
     string one = "1";
     string two = "2";
    LongArithmetic longArithmetic(one,two);

    while (longArithmetic.compare(l,r) == -1 || longArithmetic.compare(l,r) == 0)
    {
        vector<int> m = longArithmetic.division(longArithmetic.addition(l,r),longArithmetic.getB()[longArithmetic.getB().size()-1]);
        if (longArithmetic.compare(longArithmetic.multiplication(m,m),a) == -1 || longArithmetic.compare(longArithmetic.multiplication(m,m),a) == 0)
        {
            res = m;
            l = longArithmetic.addition(m, longArithmetic.getA());
        }
        else
            r = longArithmetic.subtraction(m, longArithmetic.getA());
    }
    print(res);
}

LongArithmetic::~LongArithmetic() {}
