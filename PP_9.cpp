#include<iostream>
#include<cmath>

using namespace std;

class polygon {
    public:
        float width, height;
        void set_values() {
            cout << "\nEnter the width: ";
            cin >> width;
            cout << "\nEnter the height: ";
            cin >> height;
        }
        virtual void area() = 0;
};

class rectangle : public polygon {
    public:
        void area() {
            cout << "\nWidth: " << width;
            cout << "\nHeight: " << height;
            cout << "\nArea of the rectangle: " << round(width * height);
        }
};

class triangle : public polygon {
    public:
        void area() {
            cout << "\nWidth: " << width;
            cout << "\nHeight: " << height;
            cout << "\nArea of the triangle: " << round((width * height) / 2);
        }
};

int main() {
    rectangle r;
    triangle t;
    polygon *p;
    char ch;
    short int choice;
    do {
        cout << "\n1. Area of rectangle";
        cout << "\n2. Area of triangle";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                p = &r;
                p->set_values();
                p->area();
                break;
            case 2:
                p = &t;
                p->set_values();
                p->area();
                break;
            default:
                cout << "\nWrong choice";
        }
        cout << "\nDo you want to redo(y/n): ";
        cin >> ch;
    }while(ch == 'y' || ch == 'Y');
    return 0;
}