#include <iostream>
using namespace std;
int main()
{
    string phrase = "Giraffe Academy";
    phrase[2] = 'B';
    cout << phrase.length();
    cout << phrase[2];
    cout << phrase.find("Academy", 0);
    cout << phrase.substr(8, 3);
    return 0;
}