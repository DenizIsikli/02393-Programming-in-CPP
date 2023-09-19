#include <iostream>
#include <vector>

using namespace std;

struct Contact {
    string firstName;
    string middleName;
    string lastName;
    string phoneNumber;
    string streetAddress;
    string houseNumber;
    string zipCode;
    string region;
};

class AddressBook {
public:
    vector<Contact> addressBook;

    AddressBook() : addressBook(50) {}

    void addressbook() {
        string command;

        while (cin >> command) {
            if (command == "add") {
                int n;
                cin >> n;
                n--;

                if (n >= 0 && n < 50 && addressBook[n].firstName.empty()) {
                    Contact &contact = addressBook[n];
                    cin >> contact.firstName >> contact.middleName >> contact.lastName
                        >> contact.phoneNumber >> contact.streetAddress >> contact.houseNumber
                        >> contact.zipCode >> contact.region;
                }
            } else if (command == "clr") {
                int n;
                cin >> n;
                n--;

                if (n >= 0 && n < 50) {
                    addressBook[n] = Contact();
                }
            } else if (command == "qry") {
                int n;
                cin >> n;
                n--;

                if (n >= 0 && n < 50) {
                    Contact &contact = addressBook[n];

                    if (!contact.firstName.empty()) {
                        cout << contact.firstName << "," << contact.middleName << ","
                             << contact.lastName << "," << contact.phoneNumber << ","
                             << contact.streetAddress << "," << contact.houseNumber << ","
                             << contact.zipCode << "," << contact.region << endl;
                    }
                } else if (command == "quit") {
                    break;
                }
            }
        }
    }
};


int main () {
    AddressBook addressbook;
    addressbook.addressbook();
    return 0;
}
