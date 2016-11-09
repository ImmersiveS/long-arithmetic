#include <iostream>
#include "Bignum.h"
using namespace std;

int main() {

    string a;
    string b;
    int power, shortB;
    int checker;

    while (true) {

        cout << "\nChoose operation: \n1)Read general information\n2)Perform calculations"
                "\n3)Quit\n";
        cin >> checker;

        switch (checker) {

            case 1: {
                cout << "SNP: Lobachev S.U.\nVariant: 8\nLevel: V\n"
                        "Assignment: implement the class long arithmetic within its operations" << endl;
                break;
            }

            case 2: {
                cout << "Input a, b, shortB, power: \n";
                cin >> a >> b >> shortB >> power;

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

                cout << "a ^ power: ";
                (firstNum ^ power).print();

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