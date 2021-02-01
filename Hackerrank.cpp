#include<iostream>

using namespace std;

void swap(int*, int*);
void bubble_sort(int, int[]);

int main() {
        int n, arr[20];
        cin >> n;
        for (int i = 0; i < n; i++) 
                cin >> arr[i];
        bubble_sort(n, arr);
        return 0;
}

void swap(int *a, int *b) { 
        int temp = *a; 
        *a = *b;
        *b = temp;
}

void bubble_sort(int size, int num[]) {
        int count = 0;
        for (int i = 0; i < size; i++) {
                if (num[i] > num[i + 1]) {
                        swap(&num[i], &num[i + 1]);
                        count = count + 1;
                }
        }
        cout << "Array is sorted in " << count - 1 << " swaps.";
        cout << endl << "First element: " << num[0];
        cout << endl << "Last element: " << num[size - 1] << endl;
}
