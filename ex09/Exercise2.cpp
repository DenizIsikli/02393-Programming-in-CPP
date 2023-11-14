#include <iostream>
#include <vector>

using namespace std;

void fibonacci() {
    int n;

    while (cin >> n || !cin.eof()) {
        int t1 = 0;
        int t2 = 1;
        int nextTerm = 0;

        if (n == 0) {
            cout << t2 << endl;
            continue;
        }

        for (int i = 1; i <= n; ++i) {
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
        }
        cout << nextTerm << endl;

        if (!cin.get()) {
            break;
        }
    }
}


int main() {
    fibonacci();
    return 0;
}
