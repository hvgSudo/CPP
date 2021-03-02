#include<iostream>

using namespace std;

class complex {
    int real, imag;
    int sum_real, sum_imag;
    int mul_1, mul_2;
    public:
        complex() {
            this->sum_real = 0;
            this->sum_imag = 0;
            this->mul_1 = 0;
            this->mul_2 = 0;
        }
        void get() {
            cout << "\n\t Real part of complex number: ";
            cin >> this->real;
            cout << "\n\t Imaginary part of complex number: ";
            cin >> this->imag;
        }
        complex operator ++() { // prefix
            complex c;
            c.real = ++real;
            c.imag = ++imag;
            return c;
        }
        complex operator *(complex r) { // multiplication operator
        	complex w;
        	n.mul_1 = real * r.real;
        	n.mul_2 = imag * r.imag;
        	return w;
		}
        complex operator ++(int){ // postfix
            complex p;
            p.real = real++;
            p.imag = imag++;
            return p;
        } 
        void display() {
            if (imag > 0)
                cout << " (" << real << " + " << imag << "i) ";
            else 
                cout << " (" << real << " - " << imag * -1 << "i) ";
        }
        void display_sum() {
            if (sum_imag > 0)
                cout << " (" << sum_real << " + " << sum_imag << "i) ";
            else
                cout << " (" << sum_real << " - " << sum_imag * -1 << "i) ";
        }
        friend complex operator +(complex m, complex l); // friend function for + operator overloading
        complex operator <(complex e) {
            complex o;
            if (real < e.real && imag < e.imag) {
                o.real = real;
                o.imag = imag;
            } else {
                o.real = e.real;
                o.imag = e.imag;
            }
            return o;       
        }
        ~complex() {
        }
};

complex operator +(complex m, complex l) {
    complex x;
    x.sum_real = m.real + l.real;
    x.sum_imag = m.imag + l.imag;
    return x;
}

int main() {
    complex cn, cn_1, cn_2, cn_3, cn_4;
    int choice;
    char c;
    do {
        cout << "\n\t 1. Prefix(++) operator";
        cout << "\n\t 2. Postfix(++) operator";
        cout << "\n\t 3. + operator";
        cout << "\n\t 4. Less than (&lt) operator";
        cout << "\n\t 5. Multiply *";
        cout << "\n\t Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cn_1.get();
                cout << "\n\t ++";
                cn_1.display();
                cn = ++cn_1;
                cout << " = ";
                cn.display();
                break;
            case 2:
                cn_1.get();
                cout << "\n\t ";
                cn_1.display();
                cn = cn_1++;
                cout << "++ = ";
                cn.display();
                break;
            case 3:
                cn_1.get();
                cn_2.get();
                cn_3 = cn_1 + cn_2;
                cout << "\n\t ";
                cn_1.display(); 
                cout << " + ";
                cn_2.display();
                cout << " = ";
                cn_3.display_sum();
                break;
            case 4:
                cn_1.get();
                cn_2.get();
                cn = cn_1 < cn_2;
                cout << "\n\t Complex number 1: ";
                cn_1.display();
                cout << "\n\t Complex number 2: ";
                cn_2.display();
                cout << "\n\t ";
                cn.display();
                cout << " is smaller";
                break;
            case 5:
            	cn_1.get();
            	cn_2.get();
            	cn_4 = cn_1 * cn_2;
            	cn_4.display();
            default:
                cout << "\n\t Wrong choice";
        }
        cout << "\n\t Do you want to continue(y/n): ";
        fflush(stdin);
        cin >> c;
    }while(c == 'y' || c == 'Y');
    return 0;
}
