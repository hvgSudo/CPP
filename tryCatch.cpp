#include<iostream>

using namespace std;

class employee {
    int age;
    public:
        void getAge() {
            cin >> age;
        }
        void display() {
            if (age < 15)
                throw "Age less than 15";
            cout << "Age: " << age << endl;
        }
};

int main() {
    employee e[5];
    cout << "Enter the age of 5 employees" << endl;
    for (int i = 0; i < 5; i++)
        e[i].getAge();
    for (int i = 0; i < 5; i++) {
        try {
            cout << (i + 1) << ". ";
            e[i].display();
        } catch (const char* msg) {
            cout << msg << endl;
        }
    }
}