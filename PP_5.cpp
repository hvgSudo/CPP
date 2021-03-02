#include<iostream>
   
using namespace std;

class student { // class to generate student report card
    string name, branch, batch, sem, prn;
    int n, f = 0;
    float total, marks[10];
    public:
        void get_data();
        void get_marks() { // taking input marks in n subjects
            total = 0;
            cout << "\nEnter the number of subjects: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "\nEnter marks of subject " << i + 1 << " out of 100: ";
                cin >> marks[i];
                if (marks[i] <= 40)
                    f = f + 1;
                if (marks[i] < 0)
                	i--;
                total = total + marks[i];
            }
        }
        float percentage() { // calculating percentage
            return (total / n);
        }
        float cgpa() { // calculating CGPA
            return (percentage() / 9.5);
        }
        void print_data();
};

void student::get_data() { // taking student credentials as the input
    cout << "\nPRN: ";
    fflush(stdin);
    getline(cin, prn);
    cout << "\nName: ";
    fflush(stdin);
    getline(cin, name);
    cout << "\nBranch(short form like IT): ";
    fflush(stdin);
    getline(cin, branch);
    cout << "\nBatch(like 2019-23): ";
    fflush(stdin);
    getline(cin, batch);
    cout << "\nSemester no: ";
    fflush(stdin);
    getline(cin, sem);
    get_marks();
}

void student::print_data() { // printing the report card
    float per;
    cout << "\n--------------------------REPORT CARD---------------------------" << endl;
    cout << "\n----------------------------------------------------------------" << endl;
    cout << "PRN: " << prn << "\t" << "Name: " << name << endl;
    cout << "\nBranch: " << branch << "\tBatch: " << batch << endl;
    cout << "\nSemester no: " << sem << endl;
    for (int i = 0; i < n; i++)
        cout << "\nSubject " << i + 1 << ": "<< marks[i] << " / 100";
    cout << "\n\nTotal marks obtained: " << total << " out of " << n * 100 << endl;
    if (f == 0) {
        per = percentage();
        cout << "\nPercentage obtained: " << per << "%";
        cout << "\nCGPA: " << cgpa();
        if (per >= 75)
            cout << "\nPassed in First Division";
        else if (per >= 60 && per < 75)
            cout << "\nPassed in Second Division";
        else if (per >= 40 && per < 60)
            cout << "\nPassed in Third Division";
    } else {
        if (f == 1)
            cout << "\nStudent has failed in 1 subject";
        else if (f == 2)
            cout << "\nStudent has failed in 2 subject";
        else if (f > 2)
            cout << "\nStudent has failed in more than 2 subjects";
        cout << "\nThe cutoff marks are 40";
    }
    cout << "\n----------------------------------------------------------------" << endl;
}

int main() {
    char a;
    do {    
        student st;
        st.get_data();
        st.print_data();
        cout << "\nEnter y to get the percentage for another student and ";
        cout << "n to exit: ";
        cin >> a;
    }while(a == 'y' || a == 'Y');
    return 0;
}
