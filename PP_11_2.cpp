#include<iostream>

using namespace std;

class student {
    string name, prn;
    public:
        void get_data();
        void print_data() {
            cout << endl << "Name: " << name << "\t";
            cout << "PRN: " << prn << endl;
        }
};
 
class UT_Marks : private student {
    float subject[10], total, percentage;
    int f;
    public: 
        UT_Marks() {
            f = 0;
            total = 0.0;
            percentage = 0.0;
        }
        void get_marks();
        void print_marks();
        float gpa();
        void print_details() {
            print_data();
        }
};

class sports : private student {
    string sport[10], name_of_sport[10], name_of_competition[10];
    int number;
    public:
        sports() {
            number = 0;
        }
        void get_sports();
        void print_sports();
};

class result : private UT_Marks, private sports {
    public:
        void get_info();
        void print_result();
};

int main() {
    result r[20];
    int choice = 0, count = 0;
    while (choice != 3) {
        cout << endl << "1. Enter data";
        cout << endl << "2. Print result";
        cout << endl << "3. Exit";
        cout << endl << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            r[count].get_info();
            count = count + 1;
        } else if (choice == 2) {
            for (int i = 0; i < count; i++)
                r[i].print_result();
        }
    }
    return 0;
}

void student::get_data() {
    cout << endl << "Enter name of the student: ";
    fflush(stdin);
    getline(cin, name);
    fflush(stdin);
    cout << endl << "Enter the prn: ";
    fflush(stdin);
    getline(cin, prn);
}

void UT_Marks::get_marks() {
    get_data();
    cout << endl << "Enter the marks for five subjects out of 100";
    for (int i = 0; i < 5; i++) {
        cout << endl << "Subject " << i + 1 << ": ";
        cin >> subject[i];
        if (subject[i] < 40)
            f = f + 1;
        total = subject[i] + total;
    }
}

float UT_Marks::gpa() {
    if (f > 0)
        return -1;
    else
        return ((total / 5) * 0.1);
}

void UT_Marks::print_marks() {
    for (int i = 0; i < 5; i++) {
        cout << endl << "Subject " << i + 1 << ": " << subject[i] << "/100";
    }
    cout << endl << "Total Marks obtained: " << total << "/500";
    if (gpa() == -1)
        cout << endl << "Student has obtained less than 40 marks in one or more subjects" << endl;
    else
        cout << endl << "GPA: " << gpa() << endl;
}

void sports::get_sports() {
    int choice;
    cout << endl << "1. Participated in any sports competition";
    cout << endl << "2. Not participated in any sports competition";
    cout << endl << "Enter your choice: ";
    cin >> choice;
    if (choice == 1) {
        cout << endl << "Enter number of sports competitions participated in: ";
        cin >> number;
        for (int i = 0; i < number; i++) {
            cout << endl << "Enter name of sport " << i + 1 << ": ";
            fflush(stdin);
            getline(cin, name_of_sport[i]);
            fflush(stdin);
            cout << endl << "Enter name of competition for " << name_of_sport[i] << ": ";
            fflush(stdin);
            getline(cin, name_of_competition[i]);
        }

    } else if (choice == 2) {
        name_of_sport[0] = "None";
    }
}

void sports::print_sports() {
    if (number == 0) 
        cout << endl << "Sports and competitions participated in: " << name_of_sport[0];
    else 
        for (int i = 0; i < number; i++) {
            cout << endl << "Sport: " << name_of_sport[i] << "\t";
            cout << "Competition: " << name_of_competition[i];
        }
}

void result::get_info() {
    get_marks();
    get_sports();
}

void result::print_result() {
    cout << endl << "--------------------------- RESULT -----------------------------";
    cout << endl;
    print_details();
    cout << endl;
    cout << endl << "                       -- Academics --" << endl;
    print_marks();
    cout << endl;
    cout << endl << "                         -- Sports --" << endl;
    print_sports();
    cout << endl;
    cout << endl << "----------------------------------------------------------------" << endl;
}