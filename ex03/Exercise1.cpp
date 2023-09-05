#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000

class FunWithBags {
    public:
        void funwithbags() {
            vector<int> numbers(MAX, 0);

            while (true) {
                string command;
                cin >> command;

                int n;
                cin >> n;

                if (n < 1 || n > 1000) {
                    return;
                } else {
                    if (command == "add") {
                        numbers[n]++;
                    } else if (command == "del" && numbers[n] > 0) {
                        numbers[n] = 0;
                    } else if (command == "qry") {
                        // check if n is in the bag
                        if (numbers[n] > 0) {
                            cout << "T";
                        } else {
                            cout << "F";
                        }
                    } else if (command == "quit") {
                        return;
                    }
                }
            }
        } 
};


int main() {
    FunWithBags funwithbags;
    funwithbags.funwithbags();
    return 0;
}
