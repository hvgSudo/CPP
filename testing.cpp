#include<iostream>

using namespace std;

class A {
	public:
		A() {
			cout << "\nBase constructor";
		}
		~A() {
			cout << "\nBase destructor";
		}
};

class B : private A {
	public:
		B() {
			cout << "\nDerived constructor";
		}
		~B() {
			cout << "\nDerived destructor";
		}
};

int main() {
	A b;
	return 0;
}