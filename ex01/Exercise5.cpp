//Exercise 5. Write a program that reads an integer n, and then reads n floats, and prints
//their sum. For example, if you run the program and type ”4 1 2 3 10.2” the program
//should print ”16.2”.

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
