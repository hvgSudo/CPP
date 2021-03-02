#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int arr[] = {1, 2, 3, 4, 5};

    for (int len = 1; len <= n; ++len)
    {
        for (int i = 0; i < (n - len + 1); ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                cout << arr[i + j] << " ";
            }

            cout << endl;
        }
    }
}