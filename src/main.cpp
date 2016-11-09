#include <iostream>
#include "Bignum.h"
#include <typeinfo>
using namespace std;

int main() {

    string a;
    string b;
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
                cout << "Input a,b: \n";
                cin >> a >> b;

                Bignum firstNum(a);
                Bignum secondNum(b);

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

                cout << (firstNum < secondNum);
                cout << (firstNum > secondNum);
                cout << (firstNum <= secondNum);
                cout << (firstNum >= secondNum);
                cout << (firstNum == secondNum);
                cout << (firstNum != secondNum);
                break;
            }
            case 3:
                return 0;
            default:
                cout << "Wrong selection!" << endl;
        }
    }
}