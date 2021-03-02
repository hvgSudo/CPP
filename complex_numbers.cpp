/* Addtion, Subtraction, Multiplication
   and Division of Complex number
   */
#include<iostream>

using namespace std;

struct complex_number {
	float real_1, real_2, real_sum, real_diff, real_product, real_div;
	float imag_1, imag_2, imag_sum, imag_diff, imag_product, imag_div;
}com;

void input() {
	cout << "\nEnter the real part of the complex number 1: ";
	cin >> com.real_1;
	cout << "\nEnter the imaginary part of the complex number 1: ";
	cin >> com.imag_1;
	cout << "\nEnter the real part of the complex number 2: ";
	cin >> com.real_2;
	cout << "\nEnter the imaginary part of the complex number 2: ";
	cin >> com.imag_2;
}

void display() {
	cout << "\nComplex number 1: " << com.real_1 << " + " << com.imag_1 << "i";
	cout << "\nComplex number 2: " << com.real_2 << " + " << com.imag_2 << "i";
}

void display_sum() {
	cout << "\n(" << com.real_1 << " + " << com.imag_1 << "i)";
	cout << " + (" << com.real_2 << " + " << com.imag_2 << "i) = ";
	if (com.imag_sum < 0)
		cout << "(" << com.real_sum << " - " << com.imag_sum * -1 << "i)";
	else
		cout << "(" << com.real_sum << " + " << com.imag_sum << "i)";
}

void display_diff() {
	cout << "\n(" << com.real_1 << " + " << com.imag_1 << "i)";
	cout << " - (" << com.real_2 << " + " << com.imag_2 << "i) = ";
	if (com.imag_diff < 0)
		cout << "(" << com.real_diff << " - " << com.imag_diff * -1 << "i)";
	else
		cout << "(" << com.real_diff << " + " << com.imag_diff << "i)";
}

void display_product() {
	cout << "\n(" << com.real_1 << " + " << com.imag_1 << "i)";
	cout << " x (" << com.real_2 << " + " << com.imag_2 << "i) = ";
	if (com.imag_product < 0)
		cout << "(" << com.real_product << " - " << com.imag_product * -1 << "i)";
	else
		cout << "(" << com.real_product << " + " << com.imag_product << "i)";
}

void display_div() {
	cout << "\n(" << com.real_1 << " + " << com.imag_1 << "i)";
	cout << " / (" << com.real_2 << " + " << com.imag_2 << "i) = ";
	if (com.imag_div < 0)
		cout << "(" << com.real_div << " - " << com.imag_div * -1 << "i)";
	else
		cout << "(" << com.real_div << " + " << com.imag_div << "i)";
}

void addition() {
	com.real_sum = com.real_1 + com.real_2;
	com.imag_sum = com.imag_1 + com.imag_2;
	display_sum();
}

void subtraction() {
	com.real_diff = com.real_1 - com.real_2;
	com.imag_diff = com.imag_1 - com.imag_2;
	display_diff();
}

void product() {
	com.real_product = com.real_1 * com.real_2 - com.imag_1 * com.imag_2;
	com.imag_product = com.real_1 * com.imag_2 + com.imag_1 * com.real_2;
	display_product();
}

void div() {
	float div_1, div_2, div_3, div_4;
	if (com.imag_1 == 0 || com.imag_2 == 0) {
		printf("\nDivision is not possible");
		return;
	} else {
	div_1 = (com.real_1 * com.real_2 + com.imag_1 * com.imag_2);
	div_2 = (com.real_2 * com.real_2 + com.imag_2 * com.imag_2);
	com.real_div = div_1 / div_2;
	div_3 = (com.imag_1 * com.real_2 - com.real_1 * com.imag_2);
	div_4 = (com.real_2 * com.real_2 + com.imag_2 * com.imag_2);
	com.imag_div = div_3 / div_4;
	display_div();
	}
}

int main() {
	char cha;
	do {
		input();
		display();
		addition();
		subtraction();
		product();
		div();
		cout << "\nDo you want to perform operations once again(y/n): ";
		cin >> cha;
	}while(cha == 'y' || cha == 'Y');
	return 0;
}
    