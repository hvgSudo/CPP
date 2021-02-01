/* Euclid's Algorithm is used to compute the gcd (Greatest Common Divisor)
   of two integers.
*/
#include<iostream>

using namespace std;

int gcd(int num_1, int num_2) {
    if (int(num_1 % num_2) > 0) {
        cout << "\n\t" << num_2 << " = " << num_1 << " x ";
        cout << int(num_2 / num_1) << " + " << int(num_2 % num_1);
    }
    if (num_1 == 0)
        return num_2;
    return gcd(num_2 % num_1, num_1);
}

int main() {
    int number_1, number_2, ret = 0;
    char ch;
    do {
        cout << "\n\tEnter the first number: ";
        cin >> number_1;
        cout << "\n\tEnter the second number: ";
        cin >> number_2;
        if (number_1 < number_2) {
            ret = gcd(number_1, number_2);
            cout << "\n\tThe gcd(" << number_1 << ", " << number_2 << ")";
            cout << " = " << ret;
        } else if (number_1 > number_2) {
            ret = gcd(number_2, number_1);
            cout << "\n\tThe gcd(" << number_1 << ", " << number_2 << ")";
            cout << " = " << ret;
        } else if (number_1 == number_2) {
            cout << "\n\tThe gcd(" << number_1 << ", " << number_2 << ")";
            cout << " = " << number_1;
        }
        cout << "\n\tDo you want to start again(y/n): ";
        cin >> ch;
    }while (ch == 'y' || ch == 'Y');
    return 0;
}
