#include<iostream>

using namespace std;

class op_overload {
    string name;
    public:
        friend istream & operator >>(istream &in, op_overload &op);
        friend ostream & operator <<(ostream &out, op_overload &op);
};

istream & operator >>(istream &in, op_overload &op) {
    cout << "\nEnter your name: ";
    in >> op.name;
    return in;
}

ostream & operator <<(ostream &out, op_overload &op) {
    out << "Hello " << op.name;
    return out;
}

int main() {
    op_overload o;
    cin >> o;
    cout << o;
    return 0;
}