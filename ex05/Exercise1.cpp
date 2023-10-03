#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> dataset_a, dataset_b;
    char identifier;
    int value;

    while (cin >> identifier >> value) {
        if (identifier == 'a') {
            dataset_a.push_back(value);
        } else if (identifier == 'b') {
            dataset_b.push_back(value);
        }
    }

    sort(dataset_a.begin(), dataset_a.end());
    sort(dataset_b.begin(), dataset_b.end());

    for (int val : dataset_a) {
        cout << val << " ";
    }

    for (int val : dataset_b) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}
