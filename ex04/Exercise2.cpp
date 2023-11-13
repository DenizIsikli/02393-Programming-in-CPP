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

void displayBoard(tile **playground, int x, int y, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
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

void playerInput(tile **playground, int x, int y, int n, int m) {
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
        displayBoard(playground, x, y, n, m);
    }
}


int main() {
    int n, m;
    cin >> n >> m;


    tile **playground = new tile *[n];
    for (int i = 0; i < n; i++) {
        playground[i] = new tile[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j==0 || i==(n-1) || (i==0 && j!=3) || j==(m-1));
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }
        }
    }

    int x = m/2;
    int y = n/2;


    displayBoard(playground, x ,y, n, m);
    playerInput(playground, x, y, n, m);

    return 0;
}
