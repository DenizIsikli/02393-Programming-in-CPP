#include <iostream>
using namespace std;


class ThreeDouble {
    public:
        void threedouble(double x, double y, double z) {
            cout << (x+y)-z << endl;
        }
};


int main() {
    ThreeDouble threedouble;
    double x;
    double y;
    double z;

    cin >> x;
    cin >> y;
    cin >> z;

    threedouble.threedouble(x, y, z);
    return 0;
}
