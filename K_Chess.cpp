#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x[n], y[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            cin >> y[i];
        }
        int a, b, flg = 0;
        cin >> a >> b;
        for (int i = 0; i < n; i++)
        {
            if (x[i] == a - 2)
            {
                if (y[i] == b - 1)
                {
                    flg = 1;
                    break;
                }
                else if (y[i] == b + 1)
                {
                    flg = 1;
                    break;
                }
            }
            else if (x[i] == a + 2)
            {
                if (y[i] == b - 1)
                {
                    flg = 1;
                    break;
                }
                else if (y[i] == b + 1)
                {
                    flg = 1;
                    break;
                }
            }
            else if (x[i] == a - 1)
            {
                if (y[i] == b + 2)
                {
                    flg = 1;
                    break;
                }
                else if (y[i] == b - 2)
                {
                    flg = 1;
                    break;
                }
            }
            else if (x[i] == a + 1)
            {
                if (y[i] == b + 2)
                {
                    flg = 1;
                    break;
                }
                else if (y[i] == b - 2)
                {
                    flg = 1;
                    break;
                }
            }
        }
        if (flg == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}