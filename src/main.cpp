#include <iostream>
#include "Bignum.h"
#include "BignumException.h"
#include "NotNumberException.h"
#include "OutOfBoundsException.h"
#include "ZeroDivideException.h"
#include "NegativeRootException.h"
#include "OverflowException.h"

using namespace std;

int main() {

    string a, b, buffChecker, buffShortB;
    string power;
    int shortB, checker;

    while (true) {

        cout << "\nChoose operation: \n1)Read general information\n2)Perform calculations"
                "\n3)Quit\n";
        try
        {
            cin >> buffChecker;
            string::iterator it;
            for ( it = buffChecker.begin(); it < buffChecker.end(); ++it)
                if (*it < '0' || *it > '9')
                    throw NotNumberException();
            if (buffChecker.size() > 18)
                throw OverflowException();
            checker = atoi(buffChecker.c_str());
        }
        catch (const BignumException& e) { e.what(); continue;}
        catch (...) { cerr << "Undefined exception called" << endl; continue; }

        switch (checker)
        {

            case 1:
            {
                cout << "FN: Lobachev S.U.\nVariant: 8\nLevel: V\n"
                        "Assignment: implement the class long arithmetic within its operations and exception handling" << endl;
                break;
            }

            case 2:
            {
                try
                {
                    cout << "Input a: \n";
                    cin >> a;
                    cout << "Input b: \n";
                    cin >> b;
                    cout << "Input shortB: \n";
                    cin >> buffShortB;
                    cout << "Input power: \n";
                    cin >> power;
                    string::iterator it1, it2, it3, it4;
                    //auto controlIterator = [](string::iterator it, string s) { if (it == s.end()) it--;};
                    for ( it1 = a.begin(), it2 = b.begin(), it3 = buffShortB.begin(), it4 = power.begin();
                          (it1 < a.end() || it2 < b.end() || it3 < buffShortB.end() || it4 < power.end());
                          it1, it2++, it3++, it4++) {
                        if (it1 == a.end()) --it1;
                        if (it2 == b.end()) --it2;
                        if (it3 == buffShortB.end()) --it3;
                        if (it4 == power.end()) --it4;
                        if (*it1 < '0' || *it1 > '9'
                            || *it2 < '0' || *it2 > '9'
                            || *it3 < '0' || *it3 > '9'
                            || *it4 < '0' || *it4 > '9')
                            throw NotNumberException();
                    }
                    if (a.length() > 40 || b.length() > 40 || power.length() > 3)
                        throw OutOfBoundsException();
                    if (buffShortB.size() > 18)
                        throw OverflowException();
                    else
                        shortB = atoi(buffShortB.c_str());
                }
                catch (BignumException& e) { e.what(); continue; }
                catch (...) { cerr << "\nUndefined exception called" << endl; continue; }

                Bignum firstNum(a);
                Bignum secondNum(b);

                cout << "a < b:" << (firstNum < secondNum) << endl;
                cout << "a > b:" << (firstNum > secondNum) << endl;
                cout << "a <= b:" << (firstNum <= secondNum) << endl;
                cout << "a >= b:" << (firstNum >= secondNum) << endl;
                cout << "a == b:" << (firstNum == secondNum) << endl;
                cout << "a != b:" << (firstNum != secondNum) << endl;

                cout << "a - b: ";
                (firstNum - secondNum).print();
                firstNum -= secondNum;
                cout << "a -= b: ";
                firstNum.print();

                firstNum += secondNum;
                cout << "a += b: ";
                firstNum.print();
                cout << "a + b: ";
                (firstNum + secondNum).print();

                cout << "a * b: ";
                (firstNum * secondNum).print();
                firstNum *= secondNum;
                cout << "a *= b: ";
                firstNum.print();

                try
                {
                    cout << "a / b: ";
                    (firstNum / shortB).print();
                    firstNum /= shortB;
                    cout << "a /= b: ";
                    firstNum.print();
                }
                catch (ZeroDivideException& e) { e.what(); continue; }
                catch (...) { cerr << "Undefined exception called" << endl; continue; }

                cout << "a ^ power: ";
                (firstNum ^ power).print();

                try
                {
                    cout << "The root of a : ";
                    (firstNum.extractRoot()).print();
                }
                catch (NegativeRootException& e) { e.what(); continue; }
                catch (...) { cerr << "Undefined exception called" << endl; continue; }
                cout << "-a: ";
                (-firstNum).print();
                cout << "++a: ";
                ++firstNum;
                firstNum.print();
                cout << "a++: ";
                firstNum++;
                firstNum.print();
                cout << "--a: ";
                --firstNum;
                firstNum.print();
                cout << "a--: ";
                firstNum--;
                firstNum.print();

                break;
            }
            case 3:
                return 0;
            default:
                cout << "Wrong selection!" << endl;
        }
    }
}