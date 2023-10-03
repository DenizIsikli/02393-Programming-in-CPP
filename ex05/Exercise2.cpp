#include <iostream>
#include <vector>
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

    size_t max_size = max(dataset_a.size(), dataset_b.size());

    for (size_t i = 0; i < max_size; i++) {
        if (i < dataset_a.size()) {
            cout << dataset_a[i] << " ";
        }

        if (i < dataset_b.size()) {
            cout << dataset_b[i] << " ";
        }
    }

    cout << endl;

    return 0;
}
