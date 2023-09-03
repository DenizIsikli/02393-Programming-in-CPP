#include <iostream>
using namespace std;


class TwoIntegers {
    public:
        void twointegers(int x, int y) {
            if(x == y) {
                cout << "x is equal to y" << endl;
            } else if(x > y) {
                cout <<"x is bigger than y" << endl;
            } else {
                cout << "x is smaller than y" << endl;
            }
        }
};


int main() {
    TwoIntegers twointegers;
    int x;
    int y;

    cin >> x;
    cin >> y;

    twointegers.twointegers(x, y);
    return 0;
}
