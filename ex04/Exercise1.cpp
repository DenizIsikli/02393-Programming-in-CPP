#include <iostream>

using namespace std;

#define NROWS 12
#define NCOLS 16

typedef enum { wood, stone } material;

struct tile {
    int x, y;
    bool isWall;
    material type;
};

void displayBoard(tile playground[NROWS][NCOLS], int x, int y) {
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            if (playground[i][j].x == x && playground[i][j].y == y) {
                cout << "O";
            } else if (playground[i][j].isWall) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void playerInput(tile playground[NROWS][NCOLS], int x, int y) {
    char command;

    while (cin >> command) {
        // make a switch case
        switch (command) {
            case 'q':
                return;
            case 'l':
                if (!playground[y][x - 1].isWall) {
                    x--;
                }
                break;
            case 'r':
                if (!playground[y][x + 1].isWall) {
                    x++;
                }
                break;
            case 'u':
                if (!playground[y - 1][x].isWall) {
                    y--;
                }
                break;
            case 'd':
                if (!playground[y + 1][x].isWall) {
                    y++;
                }
                break;
            default:
                break;
        }
        displayBoard(playground, x, y);
    }
}

int main() {
    tile playground[NROWS][NCOLS];
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j==0 || i==(NROWS-1) || (i==0 && j!=3) || j==(NCOLS-1));
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }
        }
    }

    int x = 5;
    int y = 5;


    displayBoard(playground, x ,y);
    playerInput(playground, x, y);

    return 0;
}
