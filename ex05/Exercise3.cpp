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
    int scalar_product = 0;

    for (size_t i = 0; i < max_size; i++) {
        if (i < dataset_a.size() && i < dataset_b.size()) {
            scalar_product += dataset_a[i] * dataset_b[i];
        }
    }

    cout << scalar_product << endl;

    return 0;
}
