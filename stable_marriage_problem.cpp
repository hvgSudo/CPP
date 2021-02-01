/* The code is written following the Gale-Shapley Algorithm.
   Boys are numbered from 0 to 3 and Girls from 4 to 7 .
   The dimensions of the 2D array: 2*n by n, where n = number of men and women.
   In this case n = 4 by default. 
   Preferences for men are from o to n - 1, i.e., 0 to 3.
   Preferences for women are from n to 2n - 1, i.e., 4 to 7. */

#include<iostream>
#include<cstring>

using namespace std;

#define n 4

bool preference_of_girls(int preference[2 * n][n], int girl_1, int boy_2, int boy_3) {
    for (int i = 0; i < n; i++) {
        if (preference[girl_1][i] == boy_3)
            return true;
        if (preference[girl_1][i] == boy_2)
            return false;
    }
}

void stable_marriage_problem_girls(int preference[2 * n][n]) {
    int girl_partner[n];
    bool boy_free[n];
    memset(girl_partner, -1, sizeof(girl_partner));
    memset(boy_free, false, sizeof(boy_free));
    int free_count = n;
    while (free_count > 0) {
        int boy;
        for (boy = 0; boy < n; boy++)
            if (boy_free[boy] == false)
                break;
        for (int i = 0; i < n && boy_free[boy] == false; i++) {
            int girl = preference[boy][i]; // checking the preference of girl for boy
            if (girl_partner[girl - n] == -1) {
                girl_partner[girl - n] = boy;
                boy_free[boy] = true;
                free_count = free_count - 1;
            } else {
                int boy_1 = girl_partner[girl - n];
                if (preference_of_girls(preference, girl, boy, boy_1) == false) {
                    girl_partner[girl - n] = boy;
                    boy_free[boy] = true;
                    boy_free[boy_1] = false;
                }
            }
        }        
    }
    cout << "\n\t Stable Marriage Result\n";
    cout << "\n\tGirls   Boys";
    for (int i = 0; i < n; i++)
        cout << "\n\t" << i + n << "\t" << girl_partner[i];
}

int main() {
    int preference[2 * n][n];
    char ch;
    cout << "\n\tThe code is written following the Gale-Shapley Algorithm.";
    cout << "\n\tBoys are numbered from 0 to 3 and Girls from 4 to 7 .";
    cout << "\n\tThe dimensions of the 2D array: 2*n by n, where n = number of men and women.";
    cout << "\n\tIn this case n = 4 by default. " << endl;
    do {
        cout << "\n\tBoys are numbered from 0 to 3";
        cout << "\n\tGirls are numbered from 4 to 7\n";
        cout << "\n\tEnter 4 preferences for the 4 boys\n";
        for (int i = 0; i < n; i++) {
            cout << "\n\t4 Preferences of " << i << " from 4, 5, 6, 7: ";
            for (int j = 0; j < n; j++)
                cin >> preference[i][j];
        }
        cout << "\n\tEnter 4 preferences for the 4 girls\n";
        for (int i = n; i < 2 * n; i++) {
            cout << "\n\t4 prefernces of " << i << " from 0, 1, 2, 3: ";
            for (int j = 0; j < n; j++)
                cin >> preference[i][j];
        }
        cout << "\n\n\tPreferences of boys\n\t";
        for (int i = 0; i < 2 * n; i++) {
            if (i == n)
                cout << "\n\tPreferences of girls\n\t";
            for (int j = 0; j < n; j++)
                cout << preference[i][j] << " ";
            cout << "\n\t";
        }
        stable_marriage_problem_girls(preference);
        cout << "\n\tDo you want to start again(y/n): ";
        cin >> ch;
    }while(ch == 'y' || ch == 'Y');
    return 0;
}