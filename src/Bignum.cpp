#include <iostream>
#include "Bignum.h"

Bignum::Bignum(string mData)
{
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
    for (int i = static_cast<int>(data.size()-2); i >= 0; --i)
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
                sub[i] = -sub[i];
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

Bignum Bignum::operator /(long long other)
{
    if (other == 0)
        throw "Error";

    int carry = 0;
    Bignum div = *this;

    for (int i = static_cast<int>(div.data.size() - 1); i >= 0; --i) {
        long long cur = div[i] + carry * 1ll * base;
        div[i] = static_cast<int> (cur / other);
        carry = static_cast<int> (cur % other);
    }
    while (div.data.size() > 1 && div.data.back() == 0)
        div.data.pop_back();
    return div;
}

Bignum Bignum::operator ^(int power)
{
    Bignum basis = *this;
    Bignum result = *this;
    Bignum one("1");
    if (power < 0)
        throw "Error";
    else if (power == 0)
        result = one;
    else {
        while (--power)
            result *= basis;
        for(int i = result.data.size()-2; i>=0; i--)
            if(result[i] < 0) {
                result[i] = -result[i];
                break;
            }
    }
    return result;
}

Bignum Bignum::extractRoot()
{
    if ( checkNegative((*this).data) )
        throw "Error";
    Bignum l("0");
    Bignum r = *this;
    Bignum result;
    Bignum one("1");

    while ( l <= r )
    {
        Bignum m = (l + r) / 2;

        if ( (m * m) <= (*this) )
        {
            result = m;
            l = m + one;
        }
        else
            r = m - one;

    }
    return result;
}

int Bignum::compare(const Bignum &a, const Bignum &b)
{
    int digitsA = 0, digitsB = 0;
    for(int i = a.data.size() - 1; i >= 0; --i )
        digitsA += countDigits(a.data[i]);
    for(int i = b.data.size() - 1; i >= 0; --i )
        digitsB += countDigits(b.data[i]);
    if (digitsA > digitsB)
        return 1;
    else if (digitsA < digitsB)
        return 0;
    for (int i = a.data.size()-1, j = b.data.size()-1; i >= 0, j >= 0; --i, --j) {
        if (a.data[i] > b.data[i])
            return 1;
        else if (a.data[i] < b.data[i])
            return 0;
    }
    return 2;
}

int countDigits(int n)
{
    int count = 1;

    while ( n ) {
        n = n / 10;
        count++;
    }

    return count;
}
