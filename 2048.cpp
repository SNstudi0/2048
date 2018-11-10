#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <iomanip>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define DIRECTION 224
using namespace std;
//void go_to_xy(int, int);
void output();
void new_num();
void up();
void down();
void left();
void right();
void copy();
int win();
int list[4][4];
int checklist[4][4];

int main() {
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            list[x][y] = 0;
            checklist[x][y] = 0;
        }
    }
    checklist[0][0] = 1;
    new_num();
    copy();
    int input;
    //cout << "debug 1";
    output();
    while(input = getch()) {
        if (input == DIRECTION) {
            input = getch();
            copy();
            switch (input) {
                case UP:
                    up();
                    break;
                case DOWN:
                    down();
                    break;
                case LEFT:
                    left();
                    break;
                case RIGHT:
                    right();
                    break;
            }
            new_num();
            int next_action = win();
            output();
            if (next_action == 1) {
                cout << "you win! :)";
            } else if (next_action == 0) {
                cout << "you lose! :(";
            }
        }
    }


}

void copy() {
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            checklist[x][y] = list[x][y];
        }
    }
}

void output() {
    system("cls");
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            cout << setw(5) << list[x][y];
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
}

void new_num() {
    bool check = 0;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (checklist[x][y] != list[x][y]) {
                check = 1;
            }
        }
    }
    if (check) {
        srand((unsigned) time(NULL));
        while (1) {
            int xy = rand() % 16;
            int x = xy / 4;
            int y = xy % 4;
            if (list[x][y] != 0) {
                continue;
            } else {
                int newnum = rand() % 4;
                if (newnum < 3) {
                    list[x][y] = 2;
                } else {
                    list[x][y] = 4;
                }
                break;
            }
        }
    }
}

void up() {
    for (int i = 0; i < 3; i++) {
        for (int x = 1; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                if (list[x - 1][y] == 0) {
                    list[x - 1][y] = list[x][y];
                    list[x][y] = 0;
                }
            }
        }
    }
    for (int x = 1; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (list[x - 1][y] == list[x][y]) {
                list[x - 1][y] += list[x][y];
                list[x][y] = 0;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int x = 1; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                if (list[x - 1][y] == 0) {
                    list[x - 1][y] = list[x][y];
                    list[x][y] = 0;
                }
            }
        }
    }
}

void down() {
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 4; y++) {
                if (list[x + 1][y] == 0) {
                    list[x + 1][y] = list[x][y];
                    list[x][y] = 0;
                }
            }
        }
    }
    for (int x = 2; x >= 0; x--) {
        for (int y = 0; y < 4; y++) {
            if (list[x + 1][y] == list[x][y]) {
                list[x + 1][y] += list[x][y];
                list[x][y] = 0;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 4; y++) {
                if (list[x + 1][y] == 0) {
                    list[x + 1][y] = list[x][y];
                    list[x][y] = 0;
                }
            }
        }
    }
}

void left() {
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 4; x++) {
            for (int y = 1; y < 4; y++) {
                if (list[x][y - 1] == 0) {
                    list[x][y - 1] = list[x][y];
                    list[x][y] = 0;
                }
            }
        }
    }
    for (int x = 0; x < 4; x++) {
        for (int y = 1; y < 4; y++) {
            if (list[x][y - 1] == list[x][y]) {
                list[x][y - 1] += list[x][y];
                list[x][y] = 0;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 4; x++) {
            for (int y = 1; y < 4; y++) {
                if (list[x][y - 1] == 0) {
                    list[x][y - 1] = list[x][y];
                    list[x][y] = 0;
                }
            }
        }
    }
}

void right() {
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 3; y++) {
                if (list[x][y + 1] == 0) {
                    list[x][y + 1] = list[x][y];
                    list[x][y] = 0;
                }
            }
        }
    }
    for (int x = 0; x < 4; x++) {
        for (int y = 2; y >= 0; y--) {
            if (list[x][y + 1] == list[x][y]) {
                list[x][y + 1] += list[x][y];
                list[x][y] = 0;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 3; y++) {
                if (list[x][y + 1] == 0) {
                    list[x][y + 1] = list[x][y];
                    list[x][y] = 0;
                }
            }
        }
    }
}

int win() {
    bool full = 1;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (full == 0) {
                break;
            } else if (list[x][y] == 0) {
            	full = 0;
                break;
            }
        }
    }
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (list[x][y] == 2048) {
                return 1;
            } else if (full == 1) {
                return 0;
            } else {
                return 2;
            }
        }
    }
}

/*void go_to_xy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
}*/
