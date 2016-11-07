#include <iostream>
#include "Bignum.h"
using namespace std;

int main() {

    string a;
    string b;
    int checker;

    while (true) {

        cout << "\nChoose operation: \n1)To read general information\n2)Addition"
                "\n3)Subtraction\n4)Multiplication\n5)Division\n6)Evolution\n7)Arithmetic root\n8)Quit\n";
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

                Bignum longArithmetic(a, b);

                vector<int> additionResult = longArithmetic.addition(longArithmetic.getA(), longArithmetic.getB());
                cout << "Result: ";
                longArithmetic.print(additionResult);
                cout << sizeof(a)*a.capacity() << " " << sizeof(b) << " " << sizeof(additionResult)*additionResult.capacity();
                break;
            }
            case 3: {
                cout << "Input a,b: \n";
                cin >> a >> b;

                Bignum longArithmetic(a, b);

                vector<int> subtractionResult = longArithmetic.subtraction(longArithmetic.getA(),
                                                                             longArithmetic.getB());
                cout << "Result: ";
                longArithmetic.print(subtractionResult);
                break;
            }
            case 4: {
                cout << "Input a,b: \n";
                cin >> a >> b;

                Bignum longArithmetic(a, b);

                vector<int> multiplicationResult =
                        longArithmetic.multiplication(longArithmetic.getA(), longArithmetic.getB());
                cout << "Result: ";
                longArithmetic.print(multiplicationResult);
                break;
            }
            case 5: {
                int shortB;

                cout << "Input a, b(short): \n";
                cin >> a >> shortB;

                Bignum longArithmetic(a, b);

                try {
                    vector<int> divisionResult = longArithmetic.division(longArithmetic.getA(), shortB);
                    cout << "Result: ";
                    longArithmetic.print(divisionResult, longArithmetic.getCarry());
                } catch (const char *errorMassage) {
                    cout << "Captured division by 0" << endl;
                }
                break;
            }
            case 6: {
                int power;

                cout << "Input a and power: \n";
                cin >> a >> power;
                try {
                    Bignum longArithmetic(a, b);

                    longArithmetic.evolution(power);
                } catch (const char *errorMassage) {
                    cout << "Invalid power!" << endl;
                }
                break;
            }
            case 7: {
                cout << "Input a: \n";
                cin >> a;

                Bignum longArithmetic(a, b);

                try {
                    longArithmetic.involution();
                } catch (const char *errorMassage) {
                    cout << "Can't calculate square of negative number" << endl;
                }
                break;
            }
            case 8:
                return 0;
            default:
                cout << "Wrong selection!" << endl;
        }
    }
}