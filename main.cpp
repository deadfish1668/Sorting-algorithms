#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {9, 7, 5, 3, 1, 8, 6, 4, 2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    int choice;
    cout << "Choose the sorting algorithm (1 = Insertion, 2 = Bubble, 3 = Selection): ";
    cin >> choice;

    switch (choice) {
        case 1:
            insertionSort(arr, size);
            cout << "Array after Insertion Sort: ";
            printArray(arr, size);
            break;
        case 2:
            bubbleSort(arr, size);
            cout << "Array after Bubble Sort: ";
            printArray(arr, size);
            break;
        case 3:
            selectionSort(arr, size);
            cout << "Array after Selection Sort: ";
            printArray(arr, size);
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }

    return 0;
}
