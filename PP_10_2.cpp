#include<iostream>

using namespace std;

class student {
    string name, branch, batch, prn, sem;

public:
    void input();
    void display();
};
 
class marks : protected student {
    int student_marks[5], tot, f = 0;
    public:
        marks() {
            tot = 0;
        }
        void input_marks();
        void display_marks();
        float percentage() {
            if (f == 0)
                return (tot / 5);
            else 
                return (1.0);
        }
};

class result : protected marks {
    public: 
        void print();
};

void student::input() {
    cout << "\nEnter PRN of student: ";
    getline(cin, prn);
    cout << "\nEnter Name of student: ";
    getline(cin, name);
    cout << "\nEnter Branch of student (eg. IT): ";
    getline(cin, branch);
    cout << "\nEnter Batch (eg. 2019-23) of the student: ";
    getline(cin, batch);
    cout << "\nEnter the semester: ";
    getline(cin, sem);
}

void student::display() {
    cout << "\n\t\t\t RESULT";
    cout << "\n----------------------------------------------------";
    cout << "\nPRN: " << prn << "\t";
    cout << "Name: " << name << endl;
    cout << "Branch: " << branch << "\t\t";
    cout << "Batch: " << batch << endl;
    cout << "Semester: " << sem;
    cout << "\n----------------------------------------------------";
}

void marks::input_marks() {
    for (int i = 0; i < 5; i++) {
        cout << "\nMarks of subject " << i + 1 << " out of 100: ";
        cin >> student_marks[i];
        if (student_marks[i] < 40)
            f = f + 1;
        else
            tot = tot + student_marks[i];
    }
}

void marks::display_marks() {
    for (int i = 0; i < 5; i++) {
        cout << "\nSubject " << i + 1 << ": ";
        cout << student_marks[i] << "/100";
    }
    if (f == 0)
        cout << "\n\nTotal marks obtained: " << tot << "/100";
}

void result::print() {
    input();
    input_marks();
    display();
    display_marks();
    if (percentage() != 1.0)
        cout << "\nPercentage obtained: " << percentage() << "%";
    else 
        cout << "\nStudent has failed";
    cout << "\n----------------------------------------------------";
}

int main() {
    result r;
    char ch;
    do {
        r.print();
        cout << "\nDo you want another result(y/n): ";
        cin >> ch;
    }while(ch == 'y' || ch == 'Y');
    return 0;
}