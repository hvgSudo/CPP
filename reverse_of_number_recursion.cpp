#include <iostream>

using namespace std;

void reverse(long int number) {
    if (number < 10)    
        cout << number;
    else {
        cout << number % 10;
        reverse(number / 10);
    }
}

int main() {
    long int number;
    cout << "Enter the number to reverse: ";
    cin >> number;
    cout << "The reversed number: ";
    reverse(number);
    return 0;
}