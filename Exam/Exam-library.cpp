#include <iostream>
#include <random>
#include "Exam-library.h"

using namespace std;

// Task 1(a).  Implement this function
Tile **createSea(unsigned int m, unsigned int n) {
     Tile** sea = new Tile*[m];

     for (int i = 0; i < m; ++i) {
         sea[i] = new Tile[n];
         for (int j = 0; j < n; ++j) {
             sea[i][j].ship = 0;
             sea[i][j].hit = false;
         }
     }

    return sea;
}


// Task 1(b).  Implement this function
void displaySea(Tile **sea, unsigned int m, unsigned int n, bool reveal) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (reveal) {
                if (sea[i][j].ship > 0) {
                    cout << sea[i][j].ship;
                } else {
                    cout << '.';
                }
            } else {
                if (sea[i][j].hit) {
                    if (sea[i][j].ship > 0) {
                        cout << 'X';
                    } else {
                        cout << '*';
                    }
                } else {
                    cout << '?';
                }
            }
        }

        cout << endl;
    }
}

// Task 1(c).  Implement this function
bool placeShip(Tile **sea, unsigned int m, unsigned int n, unsigned int r, unsigned int c, unsigned int number, unsigned int size, bool vertical) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (sea[i][j].ship == number || size < 1 || size > 4) {
                return false;
            }
        }
    }

    if (r >= m || c >= n) {
        return false;
    }

    if (vertical) {
        if (r + size > m) return false;

        for (int i = 0; i < size; ++i) {
            if (sea[r + i][c].ship != 0) return false;
        }
    } else {
        if (c + size > n) return false;
        for (int i = 0; i < size; ++i) {
            if (sea[r][c + i].ship != 0) return false;
        }
    }

    for (int i = 0; i < size; ++i) {
        if (vertical) {
            sea[r + i][c].ship = number;
        } else {
            sea[r][c + i].ship = number;
        }
    }

    return true;
}

// Task 1(d).  Implement this function
bool launchMissile(Tile **sea, unsigned int m, unsigned int n, unsigned int r, unsigned int c) {
    if (r >= m || c >= n) {
        return false;
    }

    if (sea[r][c].hit) {
        return false;
    }

    sea[r][c].hit = true;

    return true;
}

// Do not modify the following function.
void deleteSea(Tile **sea, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] sea[i];
    }
    delete[] sea;
}
