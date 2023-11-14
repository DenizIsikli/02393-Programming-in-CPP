#include <iostream>
#include <vector>

using namespace std;

void fibonacci() {
    vector<int> numbers;
    int n;

    while (cin >> n || !cin.eof()) {
        int t1 = 0;
        int t2 = 1;
        int nextTerm = 0;

        if (n == 0) {
            numbers.push_back(t2);
            continue;
        }

        for (int i = 1; i <= n; ++i) {
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
        }
        numbers.push_back(nextTerm);

        if (cin.peek() == '\n' || cin.peek() == EOF) {
            for (int i : numbers) {
                cout << i << " ";
            }
        }
    }
}


int main() {
    fibonacci();
    return 0;
}
