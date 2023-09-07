#include <iostream>
#include <vector>
using namespace std;

struct Contact {
    string firstName;
    string middleName;
    string lastName;
    int phoneNumber;
    string streetAddress;
    string houseAddress;
    int zipCode;
    string region;
};

class AddressBook {
public:
    void addressbook() {
        vector<Contact> contacts(50);

        while (true) {
            string command;
            cin >> command;

            if (command == "add") {
                int n;
                cin >> n; 

                if (n >= 1 && n <= 50) {
                    Contact contact;
                    cin >> contact.firstName >> contact.middleName >> contact.lastName >> contact.phoneNumber
                        >> contact.streetAddress >> contact.houseAddress >> contact.zipCode >> contact.region;
                    contacts[n - 1] = contact;
                } else {
                    cout << "Invalid page number" << endl;
                }
            } else if (command == "qry") {
                int n;
                cin >> n;

                if (n >= 1 && n <= 50) {
                    if (!contacts[n - 1].firstName.empty()) {
                        cout << contacts[n - 1].firstName << ", "
                            << contacts[n - 1].middleName << ", "
                            << contacts[n - 1].lastName << ", "
                            << contacts[n - 1].phoneNumber << ", "
                            << contacts[n - 1].streetAddress << ", "
                            << contacts[n - 1].houseAddress << ", "
                            << contacts[n - 1].zipCode << ", "
                            << contacts[n - 1].region << endl;
                    } else {
                        cout << "Contact does not exist" << endl;
                    }
                } else {
                    cout << "Invalid page number" << endl;
                }
            } else if (command == "quit") {
                return;
            } else {
                cout << "Invalid command" << endl;
            }
        }
    }
};

int main () {
    AddressBook addressbook;
    addressbook.addressbook();
    return 0;
}
