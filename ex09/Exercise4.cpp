#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int levenshtein_distance() {
    string u;
    string v;

    while (cin >> u) {
        cin >> v;

        int size1 = u.size();
        int size2 = v.size();

        vector<vector<int>> matrix(size1+1, vector<int>(size2+1));

        for (int i = 0; i <= size1; ++i) {
            for (int j = 0; j <= size2; ++j) {
                if (i == 0) {
                    matrix[i][j] = j;
                } else if (j == 0) {
                    matrix[i][j] = i;
                } else if (u[i - 1] == v[j - 1]) {
                    matrix[i][j] = matrix[i - 1][j - 1];
                } else {
                    matrix[i][j] = 1 + min({ matrix[i][j - 1],
                                             matrix[i - 1][j],
                                             matrix[i - 1][j - 1] });
                }
            }
        }

        if (cin.peek() == '\n' || cin.peek() == EOF) {
            cout << matrix[size1][size2] << endl;
        }
    }

    return 0;
}


int main() {
    levenshtein_distance();
    return 0;
}
