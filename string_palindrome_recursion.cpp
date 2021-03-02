#include <iostream>
#include <string>

using namespace std;

bool isPalRec(char str[], int s, int e) {
    if (s == e) // for only one character
        return true;
    if (str[s] != str[e]) // if last and first do not match
        return false;
    if (s < e + 1) // if more than two characters chaeck for 
        return isPalRec(str, s + 1, e - 1); // middle substring
    return true;
}

bool palindrome(char str[]) {
    if (strlen(str) == 0) // empty string is a plindrome
        return true;
    return isPalRec(str, 0, strlen(str) - 1);
}

int main() {
    char string[20];
    cout << "Enter the string to check for palindrome: ";
    cin >> string;
    if (palindrome(string)) 
        cout << string << " is a palindrome";
    else
        cout << string << " is not a palindrome";
    return 0;
}