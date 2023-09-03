#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000

class RememberingNumbers {
    public:
        void rememberingnumbers() {
            vector<int> numbers(MAX, 0);

            while(true) {
                int n;
                cin >> n;

                if (n == 0) {
                    break;
                }

                if (n < 1 || n > 1000) {
                    cout << "Invalid number" << endl;
                } else {
                    if (numbers[n] == 0) {
                        cout << n << " was given 0 times before" << endl;
                    } else {
                        cout << n << " was given " << numbers[n] << " times before" << endl;
                    }
                    numbers[n]++;
                }
            }   
        }
};


int main() {
    RememberingNumbers rememberingnumbers;
    rememberingnumbers.rememberingnumbers();
    return 0;
}