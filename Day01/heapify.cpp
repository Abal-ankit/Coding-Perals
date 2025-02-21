#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int i, int n) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[largest] < arr[left]) 
        largest = left;
    if(right < n && arr[largest] < arr[right]) 
        largest = right;

    if(i != largest) {
        swap(arr[largest], arr[i]);
        heapify(arr, largest, n);
    }
}

int main() {
    int arr[] = {12, 7, 9, 23, 5, 19, 27, 46, 97};
    int n = sizeof(arr)/sizeof(int);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    for(int i = (n/2) - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }

    // This will sort the array in ascending order
    for(int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }

    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";
}
