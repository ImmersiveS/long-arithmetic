#include <iostream>
#include <conio.h>
#include <limits>
#include "Bignum.h"
#include "BignumException.h"
#include "NotNumberException.h"
#include "OutOfBoundsException.h"
#include "ZeroDivideException.h"
#include "NegativeRootException.h"

using namespace std;

int main() {

    string a;
    string b;
    string power;
    int shortB, checker;
    char buffChecker[100];
    auto clearFlow = []() { cin.clear(); while (cin.get() != '\n'); };

    while (true) {

        cout << "\nChoose operation: \n1)Read general information\n2)Perform calculations"
                "\n3)Quit\n";
        try
        {
            cin >> buffChecker;
            if (buffChecker[1] != '\0') throw NotNumberException();
            clearFlow();
            checker = atoi(buffChecker);
        }
        catch (NotNumberException& e) { e.what(); continue;}
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
                    cin >> shortB;
                    if (!cin)
                        throw NotNumberException();
                    clearFlow();
                    cout << "Input power: \n";
                    cin >> power;
                    if (shortB > INTMAX_MAX || shortB < INTMAX_MIN)
                        throw overflow_error("shortB is overflowed");
                    string::iterator it;
                    for ( it = a.begin(); it < a.end(); ++it )
                        if (*it < '0' || *it > '9')
                            throw NotNumberException();
                    for ( it = b.begin(); it < b.end(); ++it )
                        if (*it < '0' || *it > '9')
                            throw NotNumberException();
                    for ( it = power.begin(); it < power.end(); ++it )
                        if (*it < '0' || *it > '9')
                            throw NotNumberException();
                    if (a.length() > 30 || b.length() > 30 || power.length() > 4)
                        throw OutOfBoundsException();
                }
                catch (NotNumberException& e) { e.what(); continue; }
                catch (overflow_error& e) { e.what(); continue; }
                catch (OutOfBoundsException& e) { e.what(); continue; }
                catch (...) { cerr << "Undefined exception called" << endl; continue; }

                Bignum firstNum(a);
                Bignum secondNum(b);

                cout << "a < b:" << (firstNum < secondNum) << endl;
                cout << "a > b:" << (firstNum > secondNum) << endl;
                cout << "a <= b:" << (firstNum <= secondNum) << endl;
                cout << "a >= b:" << (firstNum >= secondNum) << endl;
                cout << "a == b:" << (firstNum == secondNum) << endl;
                cout << "a != b:" << (firstNum != secondNum) << endl;

                cout << "a + b: ";
                (firstNum + secondNum).print();
                firstNum += secondNum;
                cout << "a += b: ";
                firstNum.print();

                firstNum -= secondNum;
                cout << "a -= b: ";
                firstNum.print();
                cout << "a - b: ";
                (firstNum - secondNum).print();

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