#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class DMA {
private:
    Node* head;

public:
    DMA() {
        head = nullptr;
    }

    // Destructor to free memory
    ~DMA() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    // Insert at beginning
    void insert(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Search element
    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Display linked list
    void display() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    // Reverse linked list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        cout << "List reversed.\n";
    }

    // Delete node by value
    void delete_node(int key) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found.\n";
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        cout << "Node deleted.\n";
    }
};

int main() {
    DMA a;
    int choice, value;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Search Element\n";
        cout << "3. Delete Node\n";
        cout << "4. Reverse List\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            a.insert(value);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> value;
            if (a.search(value))
                cout << "Element " << value << " found in list.\n";
            else
                cout << "Element " << value << " not found.\n";
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            a.delete_node(value);
            break;
        case 4:
            a.reverse();
            break;
        case 5:
            a.display();
            break;
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

