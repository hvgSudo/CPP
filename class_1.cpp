#include<iostream>

using namespace std;

class input {
    int number;
    string cha, c;
    public:
        void getdata(void);
        void printdata(void);
}x, y;

void input::getdata(void) {
    cout << "\nEnter a number: ";
    cin >> number;
    cout << "\nEnter a string: ";
    fflush(stdin);
    getline(cin, cha);
    cout << "\nEnter second string: ";
    fflush(stdin);
    getline(cin, c);
}

void input::printdata(void) {
    cout << "\nNumber: " << number;
    cout << "\nString: " << cha;
    cout << "\nString 2: " << c;
}

int main() {
    x.getdata();
    y.getdata();
    x.printdata();
    y.printdata();
    return 0;
}