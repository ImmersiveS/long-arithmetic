#include <iostream>
#include <conio.h>
#include "Bignum.h"
#include "BignumException.h"
#include "NotNumberException.h"
using namespace std;

int main() {

    string a;
    string b;
    int shortB;
    int checker;
    auto clearFlow = []() { std::cin.clear(); while (std::cin.get() != '\n'); };

    while (true) {

        cout << "\nChoose operation: \n1)Read general information\n2)Perform calculations"
                "\n3)Quit\n";
        try
        {
            cin >> checker;
            clearFlow();
            if (!cin) throw NotNumberException();
        }

        catch (NotNumberException& e) { e.what(); continue;}

        switch (checker) {

            case 1: {
                cout << "FN: Lobachev S.U.\nVariant: 8\nLevel: V\n"
                        "Assignment: implement the class long arithmetic within its operations and exception handling" << endl;
                break;
            }

            case 2: {
                cout << "Input a, b, shortB: \n";
                cin >> a >> b >> shortB;

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

                cout << "a / b: ";
                (firstNum / shortB).print();
                firstNum /= shortB;
                cout << "a /= b: ";
                firstNum.print();

                cout << "a ^ b: ";
                (firstNum ^ secondNum).print();

                try {
                    cout << "The root of a : ";
                    (firstNum.extractRoot()).print();
                } catch (const char* e) {
                    cerr << "Can't take root" << endl;
                }
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