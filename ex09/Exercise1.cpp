#include <iostream>
#include <vector>

using namespace std;

void ReverseList() {
    vector<int> numbers;
    int num;

    while (cin >> num) {
        numbers.push_back(num);

        if (cin.get() == '\n') {
            for (size_t i = numbers.size(); i > 0; --i) {
                cout << numbers[i- 1] << " ";
            }
        }
    }
}


int main() {
    ReverseList();
    return 0;
}
