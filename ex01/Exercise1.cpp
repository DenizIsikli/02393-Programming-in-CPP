#include <iostream>
using namespace std;

class HelloWorld {
    public:
        void helloworld() {
            cout << "Hello World!" << endl;
        }
};


int main() {
    HelloWorld helloworld;

    helloworld.helloworld();
    return 0;
}
