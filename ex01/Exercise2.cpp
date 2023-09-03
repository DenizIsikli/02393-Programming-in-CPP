#include <iostream>
using namespace std;


class HelloName {
public:
    void helloname(string name) {
        cout << "Hello " << name << "!" << endl;
    }
};


int main() {
    HelloName helloname;
    string name;

    cin >> name;

    helloname.helloname(name);
    return 0;
}
