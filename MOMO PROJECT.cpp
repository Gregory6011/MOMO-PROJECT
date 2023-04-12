#include <iostream>
using namespace std;

int main() {
    int balance = 1000;
    int pin = 0;
    int wrong_pin_count = 0;
    bool is_authenticated = false;
    int option;

    while (true) {
        cout << "Welcome to the Mobile Money Service" << endl;
        cout << "1. Authentication" << endl;
        cout << "2. Resetting/Changing PIN" << endl;
        cout << "3. Checking Balance" << endl;
        cout << "4. Sending Money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                if (is_authenticated) {
                    cout << "You are already authenticated." << endl;
                } else {
                    cout << "Enter your PIN: ";
                    cin >> pin;
                    if (pin == 0000) {
                        is_authenticated = true;
                        cout << "Authenticated successfully." << endl;
                        wrong_pin_count = 0;
                    } else {
                        wrong_pin_count++;
                        if (wrong_pin_count == 3) {
                            cout << "You have entered the wrong PIN 3 times. Exiting program." << endl;
                            return 0;
                        } else {
                            cout << "Incorrect PIN. Please try again." << endl;
                        }
                    }
                }
                break;
            case 2:
                if (is_authenticated) {
                    cout << "Enter your new PIN: ";
                    cin >> pin;
                    cout << "PIN changed successfully." << endl;
                } else {
                    cout << "You must authenticate first." << endl;
                }
                break;
            case 3:
                if (is_authenticated) {
                    cout << "Your balance is: " << balance << endl;
                } else {
                    cout << "You must authenticate first." << endl;
                }
                break;
            case 4:
                if (is_authenticated) {
                    int amount;
                    cout << "Enter the amount to send: ";
                    cin >> amount;
                    if (amount > balance) {
                        cout << "Insufficient balance." << endl;
                    } else {
                        cout << "Money sent successfully." << endl;
                        balance -= amount;
                    }
                } else {
                    cout << "You must authenticate first." << endl;
                }
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}

