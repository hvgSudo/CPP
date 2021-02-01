#include<iostream> 
#include<cmath>
#include<cstring>

using namespace std;

void decimal(int);
void octal(int);
void hexadecimal(char[]);
void binary(int);

int main() {
	int choice, number, n;
	char c, num[10];
	do {
		cout << "\nOnly whole numbers can be used";
		cout << "\n1. Decimal number";
		cout << "\n2. Octal number";
		cout << "\n3. Hexadecimal number";
		cout << "\n4. Binary number";
		cout << "\nWhich type of number do you want to enter: ";
		cin >> choice;
		switch(choice) {
			case 1:
				cout << "\nEnter the decimal number: ";
				cin >> number;
				if (number < 0) {
					cout << "\nOnly whole numbers can be used";
					break;
				}
				decimal(number);
				break;
			case 2:
				cout << "\nEnter the octal number: ";
				cin >> number;
				if (number < 0) {
					cout << "\nOnly whole numbers can be used";
					break;
				}
				octal(number);
				break;
			case 3:
				cout << "\nEnter the hexadecimal number: ";
				cin >> num;
				hexadecimal(num);
				break;
			case 4:
				cout << "\nEnter the binary number: ";
				cin >> number;
				if (number < 0) {
					cout << "\nOnly whole numbers can be used";
					break;
				}
				binary(number);
				break;
			default:
				cout << "\nWrong choice";
		}
		cout << "\nDo you want to continue(y/n): ";
		cin >> c;
	}while(c == 'y' || c == 'Y');
	return 0;
}

void decimal(int number) {
	int oct = number, hex = number, bin = number;
	int i = 0, l = 0, k = 0, temp = 0;
	char d[10], b[10], c[10];
	
	// decimal to octal
	while (oct != 0) {
		temp = 0;
		temp = oct % 8;
		d[i] = 48 + temp; // ASCII value gets stored in the array
		i++;
		oct = oct / 8;
	}
	cout << "\nNumber in octal number system: ";
	for (int j = i - 1; j >= 0; j--) 
		cout << d[j];
		
	// decimal to hexadecimal
	while (hex != 0) {
		temp = 0;
		temp = hex % 16;
		if (temp < 10) {
			c[k] = 48 + temp; // ASCII value gets stored in the array
			k++;
		} else {
			c[k] = 55 + temp; // ASCII value gets stored in the array
			k++;
		}	
		hex = hex / 16;
	}
	cout << "\nNumber in hexadecimal number system: ";
	for (int j = k - 1; j >= 0; j--) 
		cout << c[j];
		
	// decimal to binary
	while (bin != 0) {
		temp = 0;
		temp = bin % 2;
		b[l] = 48 + temp; // ASCII value gets stored in the array
		l++;
		bin = bin / 2;
	}
	cout << "\nNumber in binary number system: ";
	for (int j = l - 1; j >= 0; j--) 
		cout << b[j];
}

void octal(int number) {
	int dec = number, hex, bin;
	int i = 0, l = 0, k = 0;
	int temp = 0, tem = 0, te = 0;
	int d[10];
	char c[10], b[10];
	
	// octal to decimal
	while (dec != 0) {
		d[i] = dec % 10;
		dec = dec / 10;
		i++;
	}
	for (int j = 0; j < i; j++) 
		temp = temp + d[j] * pow(8, j);
	cout << "\nNumber in decimal number system: " << temp;
	
	// octal to binary
	bin = temp;
	while (bin != 0) {
		tem = 0;
		tem = bin % 2;
		b[l] = 48 + tem; // ASCII value gets stored in the array
		l++;
		bin = bin / 2;
	}
	cout << "\nNumber in binary number system: ";
	for (int j = l - 1; j >= 0; j--) 
		cout << b[j];
		
	// octal to hexadecimal
	hex = temp;
	while (hex != 0) {
		te = 0;
		te = hex % 16;
		if (te < 10) {
			c[k] = 48 + te; // ASCII value gets stored in the array
			k++;
		} else {
			c[k] = 55 + te; // ASCII value gets stored in the array
			k++;
		}	
		hex = hex / 16;
	}
	cout << "\nNumber in hexadecimal number system: ";
	for (int j = k - 1; j >= 0; j--) 
		cout << c[j];
}

void hexadecimal(char num[10]) {
	int oct, bin, len = strlen(num);
	int i = 0, l = 0, k = 0, j;
	int temp = 0, tem = 0, te = 0, t = 0, base = 1;
	char c[10], b[10], a[10];
	
	// hexadecimal to decimal
	for (j = len - 1; j >= 0; j--) {
		if (num[j] >= '0' && num[j] <= '9') {
			temp += (num[j] - 48) * base;
			base = base * 16;
		} else if (num[j] >= 'A' && num[j] <= 'F') {
			temp += (num[j] - 55) * base;
			base = base * 16; 
		}
	}
	cout << "\nNumber in decimal number system: " << temp;
			
	// hexadecimal to octal
	oct = temp;
	while (oct != 0) {
		te = 0;
		te = oct % 8;
		a[i] = 48 + te; // ASCII value gets stored in the array
		i++;
		oct = oct / 8;
	}
	cout << "\nNumber in octal number system: ";
	for (int j = i - 1; j >= 0; j--) 
		cout << a[j];
			
	// hexadecimal to binary
	bin = temp;
	while (bin != 0) {
		tem = 0;
		tem = bin % 2;
		b[l] = 48 + tem; // ASCII value gets stored in the array
		l++;
		bin = bin / 2;
	}
	cout << "\nNumber in binary number system: ";
	for (int j = l - 1; j >= 0; j--) 
		cout << b[j];
}

void binary(int number) {
	int dec = number, hex, oct;
	int i = 0, l = 0, k = 0;
	int temp = 0, tem = 0, te = 0;
	int d[10];
	char c[10], b[10];
	
	// binary to decimal
	while (dec != 0) {
		d[i] = dec % 10;
		dec = dec / 10;
		i++;
	}
	for (int j = 0; j < i; j++) 
		temp = temp + d[j] * pow(2, j);
	cout << "\nNumber in decimal number system: " << temp;
	
	// binary to octal
	oct = temp;
	while (oct != 0) {
		tem = 0;
		tem = oct % 8;
		b[l] = 48 + tem; // ASCII value gets stored in the array
		l++;
		oct = oct / 8;
	}
	cout << "\nNumber in octal number system: ";
	for (int j = l - 1; j >= 0; j--) 
		cout << b[j];
		
	// binary to hexadecimal
	hex = temp;
	while (hex != 0) {
		te = 0;
		te = hex % 16;
		if (te < 10) {
			c[k] = 48 + te; // ASCII value gets stored in the array
			k++;
		} else {
			c[k] = 55 + te; // ASCII value gets stored in the array
			k++;
		}	
		hex = hex / 16;
	}
	cout << "\nNumber in hexadecimal number system: ";
	for (int j = k - 1; j >= 0; j--) 
		cout << c[j];
}
   