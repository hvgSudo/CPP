#include<iostream>

using namespace std;

class op {
    public:
        int s;
        void get() {
            cout << "\nEnter the integer: ";
            cin >> s;
        }
        int operator <(op x) {
            if (s < x.s)
                return 1;
            return 0;
        } 
};

int main() {
    op o;
    op p;
    o.get();
    p.get();
    int ret = o < p;
    if (ret == 1)
        cout << o.s << " < " << p.s;
    else
        cout << o.s << " > " << p.s;
    return 0;
}