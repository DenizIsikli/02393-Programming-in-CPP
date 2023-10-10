#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class fraction {
private:
    int numerator;
    int denominator;

    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

public:
    fraction(int n, int d) : numerator(n), denominator(d) {
        if (d == 0) {
            cerr << "Error: Denominator can't be zero." << endl;
            exit(1);
        }
    }

    void add(fraction f) {
        numerator = (numerator * f.denominator) + (f.numerator * denominator);
        denominator = denominator * f.denominator;
        simplify();
    }

    void mult(fraction f) {
        numerator = numerator * f.numerator;
        denominator = denominator * f.denominator;
        simplify();
    }

    void div(fraction f) {
        numerator = numerator * f.denominator;
        denominator = denominator * f.numerator;
        simplify();
    }

    void display() const {
        cout << numerator << " / " << denominator;
    }
};

int main() {
    int numerator, denominator;
    string op, line;
    char slash = '/';

    while (getline(cin, line)) {
        stringstream ss(line);
        vector<fraction> fractions;

        if (!(ss >> numerator >> slash >> denominator)) {
            cerr << "Error: Invalid input." << endl;
            exit(1);
        }

        fractions.emplace_back(numerator, denominator);

        while (ss >> op >> numerator >> slash >> denominator) {
            if (op != "+" && op != "*" && op != "div") {
                cerr << "Error: Invalid input." << endl;
                exit(1);
            }
            fractions.emplace_back(numerator, denominator);
        }

        fraction result = fractions[0];

        for (size_t i = 1; i < fractions.size(); i++) {
            if (op == "+") {
                result.add(fractions[i]);
            } else if (op == "*") {
                result.mult(fractions[i]);
            } else if (op == "div") {
                result.div(fractions[i]);
            }
        }
        result.display();
        cout << " " << endl;
    }
}
