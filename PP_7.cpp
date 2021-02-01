#include<iostream>
   
using namespace std;

class complex_number {
    float real_1, complex_1;
    float real_2, complex_2;
    float add_real, add_complex; 
    public:
        complex_number() { // defautlt constructor
            cout << "\nIn default constructor" << endl;
        }
        complex_number(complex_number &c) { // copy constructor
        	cout << endl << "In Copy constructor" << endl;
		}
        complex_number(float r1, float c1, float r2, float c2) { // Parameterized constructor
            add_real = 0;
            add_complex = 0;
            this->real_1 = r1;
            this->complex_1 = c1;
            this->real_2 = r2;
            this->complex_2 = c2;
            cout << "\nIn parameterized constructor" << endl;
        }
        void display(int r, int c) {
            if (c > 0) 
                cout << "\n" << r << " + " << c << "i";
            else
                cout << "\t\t" << r << " - " << c * -1 << "i";
        }
        void display_sum() {
            if (add_complex > 0)
                cout << "\nSum: " << add_real << " + " << add_complex << "i";
            else
                cout << "\nSum: " << add_real << " - " << add_complex * -1 << "i";
        }
        void friend add(complex_number c_no); // Friend function
        ~complex_number() { // Destructor
        }
};

void add(complex_number c_no) {
    c_no.add_real = c_no.real_1 + c_no.real_2;
    c_no.add_complex = c_no.complex_1 + c_no.complex_2;
    c_no.display_sum();
}

int main() {
    float r1, c1, r2, c2;
    complex_number cn;
    complex_number cn_2 = cn; //copy constructor
    cout << "\nEnter the real part of the first complex number: ";
    cin >> r1;
    cout << "\nEnter the complex part of the first complex number: ";
    cin >> c1;
    cn.display(r1, c1);
    cn_2.display(r1, c1);
    cout << "\nEnter the real part of the second complex number: ";
    cin >> r2;
    cout << "\nEnter the complex part of the second complex number: ";
    cin >> c2;
    cn.display(r2, c2);
    complex_number cn_1(r1, c1, r2, c2);
    add(cn_1);
    return 0;
}
