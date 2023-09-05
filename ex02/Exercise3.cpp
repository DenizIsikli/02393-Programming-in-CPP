#include <iostream>
#include <math.h>
using namespace std;


class ApproximatingPi {
    public:
        void approximatingpi(unsigned int n) {
            double pi = 0;
            double pi_result = 0;

            for (int i = 0; i < n; i++) {
                pi += pow(-1, i) / (2 * i + 1);
            }
            cout << 4 * pi << endl;
        }
};


int main() {
    ApproximatingPi approximatingpi;
    unsigned int n;

    cin >> n;

    approximatingpi.approximatingpi(n);
    return 0;
}
