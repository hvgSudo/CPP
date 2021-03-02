/* The multiplicative inverse of an expression of the form 'a modulo b' 
   is being calculated. 
*/
#include<iostream>

using namespace std;

int inverse(int a, int m) {
    for (int i = 1; i < m; i++)
        if ((a * i) % m == 1)
            return i;
}

int main() {
    int a, m;
    char ch;
    do {
        cout << "\n\ta modulo m" << endl;
        cout << "\n\tEnter a: ";
        cin >> a;
        cout << "\n\tEnter m: ";
        cin >> m;
        cout << "\n\tMultiplicative inverse: " << inverse(a, m);
        cout << "\n\tDo you want to start again(y/n): ";
        cin >> ch;
    }while(ch == 'y' || ch == 'Y');
    return 0;
}