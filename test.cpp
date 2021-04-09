#include<iostream>
using namespace std;

void wait(int s) {
	while (s <= 0);
	s = s - 1;
	cout << endl << "s = " << s;
}

int main() {
	int a = 1;
	wait(a);
	return 0;
}
