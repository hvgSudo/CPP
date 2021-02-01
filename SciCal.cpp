#include <iostream>
#include <cmath>
#define PI 3.141592
using namespace std;
int main()
{
    int f, s, o = 1;
    char a;
    float fn, sn;
    cout << "\n\t ------------ Briefing ------------\n";
    cout << "\n\t Enter one of the operations given below";
    cout << "\n\t Enter the first number and then the second number";
    cout << "\n\t +        for addition";
    cout << "\n\t -        for subtraction";
    cout << "\n\t *        for multiplication";
    cout << "\n\t /        for division";
    cout << "\n\t #        for remainder";
    cout << "\n\t !        for factorial";
    cout << "\n\t r        for square root";
    cout << "\n\t ^        for power of any number";
    cout << "\n\t l        for logarithm to the base 10";
    cout << "\n\t n        for natural logarithm";
    cout << "\n\t e        for e raised to the power of any number";
    cout << "\n\t s        for sin(x)";
    cout << "\n\t c        for cos(x)";
    cout << "\n\t t        for tan(x)";
    cout << "\n\t i        for sin inverse of x";
    cout << "\n\t o        for cos inverse of x";
    cout << "\n\t a        for tan inverse of x";
    cout << "\n\t 0 to exit the calculator";
    cout << "\nStart entering below";
    while (o == 1)
    {
        cout << "\nOperator: ";
        cin >> a;
        switch(a)
        {
            case '+':cin >> fn;
                     cin >> sn;
                     cout << fn << " + " << sn << " = "<< fn + sn;
                     break;
            case '-':cin >> fn;
                     cin >> sn;
                     cout << fn << " - " << sn << " = "<< fn - sn;
                     break;
            case '*':cin >> fn;
                     cin >> sn;
                     cout << fn << " x " << sn << " = "<< fn * sn;
                     break;
            case '/':cin >> fn;
                     cin >> sn;
                     cout << fn << " / " << sn << " = "<< fn / sn;
                     break;
            case '#':cin >> f;
                     cin >> s;
                     cout << f << " % " << s << " = "<< f % s;
                     break;
            case '!':cin >> fn;
                     cin >> sn;
                     cout << "%f + %f = %f", fn, sn, fn + sn;
                     break;
            case 'r':cin >> fn;
                     cout << "Square Root of " << fn << " = " << sqrt(fn);
                     break;
            case '^':cin >> fn;
                     cin >> sn;
                     cout << fn << " raised to the power " << sn << "=" << pow(fn, sn);
                     break;
            case 'l':cin >> fn;
                     cout << "log ("<< fn << ") = " << log10(fn);
                     break;
            case 'n':cin >> fn;
                     cout << "Natural log(" << fn << ") = " << log(fn);
                     break;
            case 'e':cin >> fn;
                     cout << "e raised to the power " << fn << " = " << exp(fn);
                     break;
            case 's':cin >> fn;
                     cout << "sin (" << fn << ") = " << sin(fn * (PI / 180));
                     break;
            case 'c':cin >> fn;
                     cout << "cos (" <<  fn << ") = " << cos(fn * (PI / 180));
                     break;
            case 't':cin >> fn;
                     cout << "tan (" <<  fn << ") = " << tan(fn * (PI / 180));
                     break;
            case 'i':cin >> fn;
                     cout << "sin inverse of (" << fn << ") = " << asin(fn) * (180 / PI) << " degrees";                    
                     break;
            case 'o':cin >> fn;
                     cout << "cos inverse of (" << fn << ") = " << acos(fn) * (180 / PI) << " degrees";
                     break;
            case 'a':cin >> fn;
                     cout << "tan inverse of (" << fn << ") = " << atan(fn) * (180 / PI) << " degrees";
                     break; 
            case '0':o = 5;
                     break;
            default:cout << "\n\tWrong choice";
        }        
        if (a == 0)
            o = 5;
    }
    cout << "\n\n\t ------------ Thank You ------------";
    return 0;
}