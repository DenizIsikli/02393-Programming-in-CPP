#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ReverseList() {
    vector<int> numbers;
    int num;

    while (cin >> num) {
        numbers.push_back(num);
    }

    reverse(numbers.begin(), numbers.end());

    for (int i : numbers) {
        cout << i;
    }

    return 0;
}

int main() {
    ReverseList();
    return 0;
}
