#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int i, int n) {
    int largest = i;

    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(i != largest) {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

void push(vector<int> &arr, int x)
{
    if (arr.empty())
    {
        arr.push_back(x);
        return;
    }

    arr.push_back(x);

    int i = arr.size() - 1;

    while (i != 0)
    {
        int parent = (i - 1) / 2;

        if (arr[parent] < arr[i])
        {
            swap(arr[parent], arr[i]);
            i = parent;
        }
        else
            break;
    }
}

void pop(vector<int> &arr) {
    if(arr.size() == 1) {
        arr.pop_back();
        return;
    }

    arr.front() = arr.back();
    arr.pop_back();

    heapify(arr, 0, arr.size());
}
int main()
{
    vector<int> arr;
    push(arr, 12);
    push(arr, 23);
    push(arr, 9);
    push(arr, 66);
    push(arr, 8);
    push(arr, 32);
    push(arr, 28);
    push(arr, 1);
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        cout << arr.front() << endl;
        pop(arr);
    }

}
