#include <iostream>
using namespace std;

void heapify(int *array, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}

void heapSort(int *array, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void my_sort(int n, int *array) {
    heapSort(array, n);
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(array) / sizeof(array[0]);

    my_sort(n, array);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}
