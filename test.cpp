#include<iostream>
using namespace std;
class test2{
	int y;
};
class test{
	int x;
	test2 t2;
	public:
		operator test2() {
			return t2;
		}
		operator int(){
			return x;
		}
};
void fun(int x){cout << "fun(int)";}
void fun(test2 t) {
	cout <<"fun(test2)";
}

int main() {
	test t;
	fun(t);
	
	return 0;
}
