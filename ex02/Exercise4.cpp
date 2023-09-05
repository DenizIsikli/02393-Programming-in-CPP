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
                        cout << numbers[n] << endl;
                    } else if (numbers[n] == 1) {
                        cout << numbers[n] << endl;
                    } else {
                        cout << numbers[n] << endl;
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
