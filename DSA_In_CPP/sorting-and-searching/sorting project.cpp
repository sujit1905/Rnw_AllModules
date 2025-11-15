#include <iostream>
#include <vector>
using namespace std;

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Merge Sort helper
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0, j = 0, k = left;

    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < L.size())
        arr[k++] = L[i++];
    while (j < R.size())
        arr[k++] = R[j++];
}

// Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Linear Search
int linearSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search (array must be sorted)
int binarySearch(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Display Array
void displayArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter array\n";
        cout << "2. Display array\n";
        cout << "3. Selection Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Linear Search\n";
        cout << "6. Binary Search\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            arr.clear();
            int n, val;
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++) {
                cin >> val;
                arr.push_back(val);
            }
            break;
        }
        case 2:
            cout << "Array: ";
            displayArray(arr);
            break;
        case 3: {
            vector<int> temp = arr;
            selectionSort(temp);
            cout << "Sorted (Selection Sort): ";
            displayArray(temp);
            break;
        }
        case 4: {
            vector<int> temp = arr;
            mergeSort(temp, 0, temp.size() - 1);
            cout << "Sorted (Merge Sort): ";
            displayArray(temp);
            break;
        }
        case 5: {
            int key;
            cout << "Enter element to search: ";
            cin >> key;
            int index = linearSearch(arr, key);
            if (index != -1)
                cout << "Element found at index " << index << endl;
            else
                cout << "Element not found." << endl;
            break;
        }
        case 6: {
            vector<int> temp = arr;
            mergeSort(temp, 0, temp.size() - 1);
            cout << "Sorted for Binary Search: ";
            displayArray(temp);
            int key;
            cout << "Enter element to search: ";
            cin >> key;
            int index = binarySearch(temp, key);
            if (index != -1)
                cout << "Element found at index " << index << endl;
            else
                cout << "Element not found." << endl;
            break;
        }
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}

