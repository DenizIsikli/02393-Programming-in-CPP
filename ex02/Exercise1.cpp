#include <iostream>
using namespace std;


class GaussianSum {
    public:
        void gaussiansum(int n) {
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                sum += i;
            }
            cout << sum;
        }
};


int main() {
    GaussianSum gaussiansum;
    int n;

    cin >> n;

    gaussiansum.gaussiansum(n);
    return 0;
}