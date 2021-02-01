#include<iostream>

using namespace std;

class person {
    string name, mobile_no;
    public:
        void get_details();
        string name_() {
            return name;
        }
        string mobile_no_() {
            return mobile_no;
        }
};
 
class student : private person {
    string department, batch, prn;
    float gpa;
    int sem;
    public:
        void get_student_details();
        void print_student_details();
};

class employee : protected person {
    string department, sector;
    int employee_id;
    public:
        void get_employee_details();
        void print_employee_details();
};

int main() {
    student s[20];
    employee e[20];
    int choice = 0, i = 0, j = 0;
    char ch;
    while (choice != 4) {
        cout << endl;
        cout << "1. Student data" << endl;
        cout << "2. Employee data" << endl;
        cout << "3. Display data" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        if (choice == 1) {
            s[i].get_student_details();
            i++;
        } else if (choice == 2) {
            e[j].get_employee_details();
            j++;
        } else if (choice == 3) {
            cout << endl << "-----------------------------STUDENT------------------------------" << endl;
            cout << "PRN \t\t Department \t Batch \t Semster \t GPA \t Mobile No \t Name" << endl;
            cout << "------------------------------------------------------------------" << endl;
            for (int m = 0; m < i; m++)
                s[m].print_student_details();
            cout << endl << "------------------------------------------------------------------" << endl;
            cout << endl << "-----------------------------EMPLOYEE-----------------------------" << endl;
            cout << "Employee ID \t Department \t Sector \t Mobile No \t Name" << endl;
            cout << "------------------------------------------------------------------" << endl;
            for (int n = 0; n < j; n++)
                e[n]. print_employee_details();
            cout << endl << "------------------------------------------------------------------" << endl;
        }
    }
    return 0;
}

void person::get_details() {
    cout << "\nEnter name: ";
    fflush(stdin);
    getline(cin, name);
    fflush(stdin);
    cout << "\nEnter mobile number: ";
    getline(cin, mobile_no);
    cout << endl;
}

void student::get_student_details() {
    get_details();
    cout << "\nEnter the prn: ";
    getline(cin, prn);
    fflush(stdin);
    cout << "\nEnter department(eg. IT): ";
    getline(cin, department);
    cout << "\nEnter batch(eg. 2019-23): ";
    getline(cin, batch);
    cout << "\nEnter the semester: ";
    cin >> sem;
    cout << "\nEnter the gpa for this semester: ";
    cin >> gpa;
    cout << endl;
}

void student::print_student_details() {
    cout << endl;
    cout << prn << "\t" << department << "\t\t" << batch << "\t\t" << sem << "\t" << gpa << "\t";
    cout << mobile_no_() << "\t" << name_(); 
}

void employee::get_employee_details() {
    get_details();
    cout << "\nEnter the department: ";
    getline(cin, department);
    cout << "\nEnter sector(private, public or governement): ";
    getline(cin, sector);
    cout << "\nEnter the 5 digit employee id: ";
    cin >> employee_id;
    cout << endl;
}

void employee::print_employee_details() {
    cout << endl;
    cout << employee_id << "\t\t" << department << "\t\t" << sector << "\t";
    cout << "\t" << mobile_no_() << "\t" << name_();
}