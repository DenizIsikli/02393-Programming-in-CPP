#include <iostream>
using namespace std;


class SumFloats {
    public:
        void sumfloats(int n) {
            float sum = 0;
            float x;
            for (int i = 0; i < n; i++) {
                cin >> x;
                sum += x;
            }
            cout << sum << endl;
        }
};


int main() {
    SumFloats sumfloats;
    int n;

    cin >> n;
    
    sumfloats.sumfloats(n);
    return 0;
}
