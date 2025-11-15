#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;       
    int topIndex;  
    int capacity;   

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push element into stack
    void push(int element) {
        if (isFull()) {
            cout << "Stack overflow!\n";
            return; 
        }
        arr[++topIndex] = element;
        cout << element << " pushed successfully.\n";
    }

    // Pop element from stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!\n";
            return -1;
        }
        int value = arr[topIndex--];
        cout << value << " popped successfully.\n";
        return value;
    }

    // View top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element.\n";
            return -1;
        }
        return arr[topIndex];
    }

    // Check if stack is empty
    bool isEmpty() {
        return (topIndex == -1);
    }

    // Check if stack is full
    bool isFull() {
        return (topIndex == capacity - 1);
    }
};

int main() {
    Stack s(10);
    s.push(25);
    s.push(33);
    s.pop();
    cout << "Top element: " << s.top() << endl;
    return 0;
}

