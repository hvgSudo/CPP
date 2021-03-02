#include<iostream>

using namespace std;

void octal(int);
void hex(int);
void bin(int);

int main() {
	int a;
	char c;
	do {
		cout << "\nEnter the decimal number: ";
		cin >> a;
		octal(a);
		hex(a);
		bin(a);
		cout << "\nDo you want to convert more numbers(y/n): ";
		cin >> c;
	}while(c == 'y' || c == 'Y');
	return 0;
}

void octal(int a) {
	int i = 0;
	int d[10];
	int oct = a;
	cout << "Number in decimal number system: " << a;
	while (oct != 0) {
		d[i] = oct % 8;
		oct = oct / 8.0;
		i++;
	}
	cout << "\nNumber in octal number system: ";
	for (int j = i - 1; j >= 0; j--)
		cout << d[j];
}

void hex(int a) {
	int k = 0, temp;
	int hex = a;
	char b[10];
	while (hex != 0) {
		temp = 0;
		temp = hex % 16;
		if (temp < 10) {
			b[k] = 48 + temp; // ASCII value gets stored in the array
			k++;
		} else {
			b[k] = 55 + temp; // ASCII value gets stored in the array
			k++;
		}	
		hex = hex / 16;
	}
	cout << "\nNumber in hexadecimal number system: ";
	for (int j = k - 1; j >= 0; j--) 
		cout << b[j];
}

void bin(int a) {
	int l = 0, c[10];
	int bin = a;
	while (bin != 0) {
		c[l] = bin % 2;
		bin = bin / 2;
		l++;
	}
	cout << "\nNumber in binary number system: ";
	for (int j = l - 1; j >= 0; j--)
		cout << c[j];
}
