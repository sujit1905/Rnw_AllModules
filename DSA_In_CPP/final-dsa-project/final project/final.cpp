#include <iostream>
#include <vector>
using namespace std;

//
// ========== Linked List Class ==========
//
class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void deleteValue(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        while (curr->next && curr->next->data != val) {
            curr = curr->next;
        }

        if (curr->next) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }

    void display() const {
        Node* temp = head;
        if (!temp) {
            cout << "Linked List is empty.\n";
            return;
        }

        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    vector<int> toVector() const {
        vector<int> result;
        Node* temp = head;
        while (temp) {
            result.push_back(temp->data);
            temp = temp->next;
        }
        return result;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~LinkedList() {
        clear();
    }
};

//
// ========== Utility Functions (Sorting & Searching) ==========
//
namespace AlgoUtils {

    // Merge Sort
    void merge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++) L[i] = arr[l + i];
        for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2)
            arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    // Quick Sort
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high], i = low - 1;
        for (int j = low; j < high; j++)
            if (arr[j] <= pivot)
                swap(arr[++i], arr[j]);
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    // Binary Search
    bool binarySearch(const vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) return true;
            else if (arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
}

//
// ========== Menu UI Function ==========
//
void showMenu() {
    cout << "\n====== MAIN MENU ======\n";
    cout << "1. Insert values into Linked List\n";
    cout << "2. Delete a value from Linked List\n";
    cout << "3. Display Linked List\n";
    cout << "4. Sort Linked List values (Merge or Quick Sort)\n";
    cout << "5. Binary Search in sorted list\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

//
// ========== Main Program ==========
//
int main() {
    LinkedList list;
    vector<int> sortedArr;
    bool isSorted = false;
    int choice, val;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter values to insert (-1 to stop): ";
            while (true) {
                cin >> val;
                if (val == -1) break;
                list.insertAtEnd(val);
            }
            isSorted = false;
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            list.deleteValue(val);
            isSorted = false;
            break;

        case 3:
            list.display();
            break;

        case 4:
            sortedArr = list.toVector();
            if (sortedArr.empty()) {
                cout << "List is empty. Cannot sort.\n";
                break;
            }

            int sortChoice;
            cout << "Choose sorting algorithm:\n1. Merge Sort\n2. Quick Sort\nEnter: ";
            cin >> sortChoice;

            if (sortChoice == 1) {
                AlgoUtils::mergeSort(sortedArr, 0, sortedArr.size() - 1);
                cout << "Sorted using Merge Sort: ";
            } else if (sortChoice == 2) {
                AlgoUtils::quickSort(sortedArr, 0, sortedArr.size() - 1);
                cout << "Sorted using Quick Sort: ";
            } else {
                cout << "Invalid sorting choice.\n";
                break;
            }

            for (int num : sortedArr)
                cout << num << " ";
            cout << endl;
            isSorted = true;
            break;

        case 5:
            if (!isSorted) {
                cout << "Please sort the list first before searching.\n";
                break;
            }

            cout << "Enter value to search: ";
            cin >> val;
            if (AlgoUtils::binarySearch(sortedArr, val))
                cout << "Value found!\n";
            else
                cout << "Value not found.\n";
            break;

        case 6:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

