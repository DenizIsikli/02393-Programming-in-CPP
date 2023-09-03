#include <iostream>
using namespace std;


class PrimeFactorization {
    public:
        void primefactorization(unsigned int n) {
            for (int i = 2; i <= n; i++) {
                while (n % i == 0) {
                    cout << i;
                    n /= i;
                    if (n > 1) {
                        cout << " * ";
                    }
                }
            }
        }
};


int main() {
    PrimeFactorization primefactorization;
    unsigned int n;

    cin >> n;

    primefactorization.primefactorization(n);
    return 0;
}
