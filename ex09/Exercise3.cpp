#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void palindrome() {
    vector<int > numbers;
    int n;

    while (cin >> n) {
        numbers.push_back(n);

        if (cin.get() == '\n') {
            vector<int> reversed = numbers;

            reverse(reversed.begin(), reversed.end());

            if (numbers == reversed) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
}


int main() {
    palindrome();
    return 0;
}
