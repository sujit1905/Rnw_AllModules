#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Template for holding student data
template <typename T>
class StudentRecord {
    T rollNo;
    string fullName;

public:
    StudentRecord(T r, string n) {
        rollNo = r;
        fullName = n;
    }

    T getRollNo() const { return rollNo; }
    string getFullName() const { return fullName; }

    void show() const {
        cout << "Roll No: " << rollNo << " | Name: " << fullName << endl;
    }
};

// Student Manager to handle all operations
class StudentManager {
    vector<StudentRecord<int>> data;

public:
    void insertStudent(int rollNo, const string& fullName) {
        data.emplace_back(rollNo, fullName);
        cout << "? Student successfully inserted!\n";
    }

    void viewAll() {
        if (data.empty()) {
            cout << "? No student records available.\n";
            return;
        }
        cout << "\n--- Student Records ---\n";
        for (const auto& st : data) {
            st.show();
        }
    }

    void searchByRoll(int rollNo) {
        for (const auto& st : data) {
            if (st.getRollNo() == rollNo) {
                cout << "?? Match found:\n";
                st.show();
                return;
            }
        }
        cout << "? Roll number " << rollNo << " not found.\n";
    }

    void deleteByRoll(int rollNo) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->getRollNo() == rollNo) {
                data.erase(it);
                cout << "?? Student with Roll No " << rollNo << " deleted.\n";
                return;
            }
        }
        cout << "? Roll number " << rollNo << " not found.\n";
    }
};

int main() {
    StudentManager manager;
    int choice;

    while (true) {
        cout << "\n==== Student Record System ====\n";
        cout << "1. Insert Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Find Student by Roll No\n";
        cout << "4. Delete Student by Roll No\n";
        cout << "5. Exit Program\n";
        cout << "Select option (1-5): ";
        cin >> choice;

        int roll;
        string fullName;

        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> roll;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter Full Name: ";
                getline(cin, fullName);
                manager.insertStudent(roll, fullName);
                break;

            case 2:
                manager.viewAll();
                break;

            case 3:
                cout << "Enter Roll Number to search: ";
                cin >> roll;
                manager.searchByRoll(roll);
                break;

            case 4:
                cout << "Enter Roll Number to delete: ";
                cin >> roll;
                manager.deleteByRoll(roll);
                break;

            case 5:
                cout << "?? Exiting... Thank you!\n";
                return 0;

            default:
                cout << "? Invalid choice, try again!\n";
        }
    }
}

