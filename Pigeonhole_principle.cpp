/* Pigeonhole principle states that if 'N' objects are put in 'B' boxes where n > m
   then atleast one box will contain two or more objects or [(N - 1) / B] + 1 objects.
*/
#include<iostream>

using namespace std;

int number_of_objects_in_one_box(int, int);
int total_number_of_objects(int, int);

int main() {
    int n, N, B, choice, ret = 0;
    char ch;
    do {
        cout << "\n\t1. To find number of objects in one box 'n' if there are";
        cout << "\n\t   'N' objects in 'B' boxes";
        cout << "\n\t2. To find total number of objects 'N' if there are";
        cout << "\n\t   'n' objects in one box and total 'B' boxes given";
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "\n\t1. To find number of objects in one box 'n' if there are";
            cout << "\n\t'N' objects in 'B' boxes" << endl;
            cout << "\n\tEnter N: ";
            cin >> N;
            cout << "\n\tEnter B: ";
            cin >> B;
            ret = number_of_objects_in_one_box(N, B);
            cout << "\n\tNumber of objects in one box: " << ret;
        } else {
            cout << "\n\t2. To find total number of objects 'N' if there are";
            cout << "\n\t   'n' objects in one box and total 'B' boxes given" << endl;
            cout << "\n\tEnter n: ";
            cin >> n;
            cout << "\n\tEnter B: ";
            cin >> B;
            ret = total_number_of_objects(n, B);
            cout << "\n\tNumber of objects in one box: " << ret;
        }
        cout << "\n\tDo you want to continue(y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}

int number_of_objects_in_one_box(int N, int B) {
    return (((N - 1) / B) + 1);
}

int total_number_of_objects(int n, int B) {
    return (((n - 1) * B) + 1);
}