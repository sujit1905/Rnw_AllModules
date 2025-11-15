#include <iostream>
#include <string>
using namespace std;

//  Base Class 
class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

protected:
    void addToBalance(double amount) { balance += amount; }
    bool subtractFromBalance(double amount) {
        if (amount <= balance) { balance -= amount; return true; }
        return false;
    }

public:
    BankAccount(string accNo, string name, double bal = 0.0)
        : accountNumber(accNo), accountHolderName(name), balance(bal) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\n[+] Deposited: " << amount << "\n";
        } else {
            cout << "\n[!] Invalid deposit amount.\n";
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "\n[-] Withdrawn: " << amount << "\n";
        } else {
            cout << "\n[!] Insufficient balance or invalid amount!\n";
        }
    }

    double getBalance() const { return balance; }

    virtual void displayAccountInfo() const {
        cout << "\n=========================================\n";
        cout << "       ACCOUNT INFORMATION\n";
        cout << "------------------------------------------\n";
        cout << " Account Number : " << accountNumber << "\n";
        cout << " Account Holder : " << accountHolderName << "\n";
        cout << " Balance        : " << balance << "\n";
        cout << "=========================================\n";
    }

    virtual void calculateInterest() {
        cout << "\n[!] Interest calculation not applicable for base account.\n";
    }

    virtual ~BankAccount() {}
};

// ================= Derived Class: Savings ==================
class SavingsAccount : public BankAccount {
private:
    double interestRate; // in %

public:
    SavingsAccount(string accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal), interestRate(rate) {}

    void calculateInterest() {
        double interest = getBalance() * (interestRate / 100.0);
        cout << "\n[??] Savings Interest (@ " << interestRate << "%): " << interest << "\n";
    }

    void displayAccountInfo() const {
        BankAccount::displayAccountInfo();
        cout << " Type          : Savings\n";
        cout << " Interest Rate : " << interestRate << "%\n";
        cout << "=========================================\n";
    }
};

// ================= Derived Class: Checking ==================
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal), overdraftLimit(limit) {}

    void withdraw(double amount) {
        double available = getBalance() + overdraftLimit;
        if (amount > 0 && amount <= available) {
            if (!subtractFromBalance(amount)) {
                double need = amount - getBalance();
                subtractFromBalance(getBalance()); // sets to 0
                cout << "\n[??] Withdrew using overdraft: " << need << "\n";
            }
            cout << "[-] Withdrawn: " << amount << "\n";
        } else {
            cout << "\n[!] Withdrawal exceeds overdraft limit!\n";
        }
    }

    void checkOverdraft(double amount) {
        if (amount > getBalance() + overdraftLimit)
            cout << "\n[!] Overdraft limit exceeded!\n";
        else
            cout << "\n[?] Within overdraft limit.\n";
    }

    void displayAccountInfo() const {
        BankAccount::displayAccountInfo();
        cout << " Type            : Checking\n";
        cout << " Overdraft Limit : " << overdraftLimit << "\n";
        cout << "=========================================\n";
    }
};

// ================= Derived Class: Fixed Deposit ==================
class FixedDepositAccount : public BankAccount {
private:
    int term;          // months
    double interestRate; // annual %

public:
    FixedDepositAccount(string accNo, string name, double bal, int t, double rate)
        : BankAccount(accNo, name, bal), term(t), interestRate(rate) {}

    void calculateInterest() {
        double years = term / 12.0;
        double interest = getBalance() * (interestRate / 100.0) * years;
        cout << "\n[??] Fixed Deposit Interest (" << term << " months @ "
             << interestRate << "% p.a.): " << interest << "\n";
    }

    void displayAccountInfo() const {
        BankAccount::displayAccountInfo();
        cout << " Type          : Fixed Deposit\n";
        cout << " Term          : " << term << " months\n";
        cout << " Interest Rate : " << interestRate << "% p.a.\n";
        cout << "=========================================\n";
    }
};

// ================= Menu-Driven Demo ==================
int main() {
    BankAccount* account = 0;
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "         BANKING SYSTEM MENU\n";
        cout << "=========================================\n";
        cout << " 1. Create Savings Account\n";
        cout << " 2. Create Checking Account\n";
        cout << " 3. Create Fixed Deposit Account\n";
        cout << " 4. Deposit Money\n";
        cout << " 5. Withdraw Money\n";
        cout << " 6. Display Account Info\n";
        cout << " 7. Calculate Interest\n";
        cout << " 8. Check Overdraft (Checking only)\n";
        cout << " 9. Exit\n";
        cout << "=========================================\n";
        cout << " Enter choice: ";
        cin >> choice;

        if (!cin) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n[!] Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            string no, name; double bal, rate;
            cout << "\n Enter Account No: "; cin >> no;
            cout << " Enter Name: ";  cin >> name;
            cout << " Opening Balance: "; cin >> bal;
            cout << " Interest Rate (%): "; cin >> rate;
            delete account;
            account = new SavingsAccount(no, name, bal, rate);
            cout << "\n[?] Savings Account Created!\n";
        } else if (choice == 2) {
            string no, name; double bal, limit;
            cout << "\n Enter Account No: "; cin >> no;
            cout << " Enter Name: ";  cin >> name;
            cout << " Opening Balance: "; cin >> bal;
            cout << " Overdraft Limit: "; cin >> limit;
            delete account;
            account = new CheckingAccount(no, name, bal, limit);
            cout << "\n[?] Checking Account Created!\n";
        } else if (choice == 3) {
            string no, name; double bal, rate; int term;
            cout << "\n Enter Account No: "; cin >> no;
            cout << " Enter Name: ";  cin >> name;
            cout << " Deposit Amount: "; cin >> bal;
            cout << " Term (months): "; cin >> term;
            cout << " Interest Rate (% p.a.): "; cin >> rate;
            delete account;
            account = new FixedDepositAccount(no, name, bal, term, rate);
            cout << "\n[?] Fixed Deposit Account Created!\n";
        } else if (choice == 4) {
            if (account) {
                double amt; cout << "\n Enter amount to deposit: "; cin >> amt;
                account->deposit(amt);
            } else cout << "\n[!] Create an account first.\n";
        } else if (choice == 5) {
            if (account) {
                double amt; cout << "\n Enter amount to withdraw: "; cin >> amt;
                account->withdraw(amt);
            } else cout << "\n[!] Create an account first.\n";
        } else if (choice == 6) {
            if (account) account->displayAccountInfo();
            else cout << "\n[!] Create an account first.\n";
        } else if (choice == 7) {
            if (account) account->calculateInterest();
            else cout << "\n[!] Create an account first.\n";
        } else if (choice == 8) {
            if (account) {
                CheckingAccount* chk = dynamic_cast<CheckingAccount*>(account);
                if (chk) {
                    double amt; cout << "\n Enter amount to test overdraft: "; cin >> amt;
                    chk->checkOverdraft(amt);
                } else {
                    cout << "\n[!] Current account is not Checking.\n";
                }
            } else cout << "\n[!] Create an account first.\n";
        } else if (choice == 9) {
            cout << "\n[?] Exiting... Thank you for banking with us!\n";
        } else {
            cout << "\n[!] Invalid choice!\n";
        }
    } while (choice != 9);

    delete account;
    return 0;
}

