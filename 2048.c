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
#define intsize 4
using namespace std;
//void go_to_xy(int, int);
void output(int*);
void new_num(int*, int*);
void up(int*);
void down(int*);
void left(int*);
void right(int*);
void copy(int*, int*);
int win(int*, int*);

int main() {
	int list[4][4];
	int checklist[4][4];
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            list[x][y] = 0;
            checklist[x][y] = 0;
        }
    }
    checklist[0][0] = 1;
    new_num(&list[0][0], &checklist[0][0]);
    copy(&checklist[0][0], &list[0][0]);
    int input;
    //cout << "debug 1";
    output(&list[0][0]);
    while(input = getch()) {
        if (input == DIRECTION) {
            input = getch();
            copy(&checklist[0][0], &list[0][0]);
            switch (input) {
                case UP:
                    up(&list[1][0]);
                    break;
                case DOWN:
                    down(&list[0][0]);
                    break;
                case LEFT:
                    left(&list[0][0]);
                    break;
                case RIGHT:
                    right(&list[0][0]);
                    break;
            }
            new_num(&checklist[0][0], &list[0][0]);
            int next_action = win(&checklist[0][0], &list[0][0]);
            output(&list[0][0]);
            if (next_action == 1) {
                cout << "you win! :)";
            } else if (next_action == 0) {
                cout << "you lose! :(";
            }
        }
    }


}

void copy(int *checklist_ptr, int *list_ptr) {
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++, checklist_ptr += intsize, list_ptr += intsize) {
            *checklist_ptr = *list_ptr;
        }
    }
}

void output(int *list_ptr) {
    system("cls");
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++, list_ptr += intsize) {
            cout << setw(5) << *list_ptr;
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
}

void new_num(int *checklist_ptr, int *list_ptr) {
    bool check = false;
    int *list_ptr1 = list_ptr;
	int *checklist_ptr1 =  checklist_ptr;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++, checklist_ptr1 += intsize, list_ptr1 += intsize) {
            if (*checklist_ptr1 != *list_ptr1) {
                check = true;
                break;
            }
        }
    }
    if (check) {
        srand((unsigned) time(NULL));
        while (true) {
            int xy = rand() % 16;
            int x = xy / 4;
            int y = xy % 4;
            if (*(list_ptr + x * 16 + y * 4) != 0) {
                continue;
            } else {
                int newnum = rand() % 4;
                if (newnum < 3) {
                    *(list_ptr + x * 16 + y * 4) = 2;
                } else {
                    *(list_ptr + x * 16 + y * 4) = 4;
                }
                break;
            }
        }
    }
}

void up(int *list_ptr) {
    int *list_ptr1 = list_ptr;
    for (int i = 0; i < 3; i++) {
        for (int x = 1; x < 4; x++) {
            for (int y = 0; y < 4; y++, list_ptr1 += intsize) {
                if (*(list_ptr1 - intsize * 4) == 0) {
                    *(list_ptr1 - intsize * 4) = *list_ptr1;
                    *list_ptr1 = 0;
                }
            }
        }
    }
    list_ptr1 = list_ptr;
    for (int x = 1; x < 4; x++) {
        for (int y = 0; y < 4; y++, list_ptr1 += intsize) {
            if ((*list_ptr1 - intsize * 4) == *list_ptr1) {
                *(list_ptr1 - intsize * 4) += *list_ptr1;
                *list_ptr1 = 0;
            }
        }
    }
    list_ptr1 = list_ptr;
    for (int i = 0; i < 3; i++) {
        for (int x = 1; x < 4; x++) {
            for (int y = 0; y < 4; y++, list_ptr1 += intsize) {
                if (*(list_ptr1 - intsize * 4) == 0) {
                    *(list_ptr1 - intsize * 4) = *list_ptr1;
                    *list_ptr1 = 0;
                }
            }
        }
    }
}

void down(int *list_ptr) {
    int *list_ptr1 = list_ptr;
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 4; y++, list_ptr1 += intsize) {
                if (*(list_ptr1 + intsize * 4) == 0) {
                    *(list_ptr1 + intsize * 4) = *(list_ptr1);
                    *(list_ptr1) = 0;
                }
            }
        }
    }
    list_ptr1 = list_ptr;
    for (int x = 2; x >= 0; x--) {
        for (int y = 0; y < 4; y++, list_ptr1 += intsize) {
            if (*(list_ptr1 + intsize * 4) == *(list_ptr1)) {
                *(list_ptr1 + intsize * 4) += *(list_ptr1);
                *(list_ptr1) = 0;
            }
        }
    }
    list_ptr1 = list_ptr;
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 4; y++, list_ptr1 += intsize) {
                if (*(list_ptr1 + intsize * 4) == 0) {
                    *(list_ptr1 + intsize * 4) = *(list_ptr1);
                    *(list_ptr1) = 0;
                }
            }
        }
    }
}

void left(int *list_ptr) {
    int *list_ptr1 = list_ptr;
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 4; x++, list_ptr1 += intsize) {
            for (int y = 1; y < 4; y++, list_ptr1 += intsize) {
                if (*(list_ptr1 - intsize) == 0) {
                    *(list_ptr1 - intsize) = *(list_ptr1 + x * 16 + y * 4);
                    *(list_ptr1 - intsize) = 0;
                }
            }
        }
    }
    list_ptr1 = list_ptr;
    for (int x = 0; x < 4; x++, list_ptr1 += intsize) {
        for (int y = 1; y < 4; y++, list_ptr1 += intsize) {
            if (*(list_ptr1 - intsize) == *(list_ptr1)) {
                *(list_ptr1 - intsize) += *(list_ptr1);
                *(list_ptr1) = 0;
            }
        }
    }
    list_ptr1 = list_ptr;
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 4; x++, list_ptr1 += intsize) {
            for (int y = 1; y < 4; y++, list_ptr1 += intsize) {
                if (*(list_ptr1 - intsize) == 0) {
                    *(list_ptr1 - intsize) = *(list_ptr1 + x * 16 + y * 4);
                    *(list_ptr1 - intsize) = 0;
                }
            }
        }
    }
}

void right(int *list_ptr) {
    int *list_ptr1 = list_ptr;
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 4; x++, list_ptr1 += intsize) {
            for (int y = 0; y < 3; y++, list_ptr1 += intsize) {
                if (*(list_ptr1 + intsize) == 0) {
                    *(list_ptr1 + intsize) = *(list_ptr1 + x * 16 + y * 4);
                    *(list_ptr1 + intsize) = 0;
                }
            }
        }
    }
    list_ptr1 = list_ptr;
    for (int x = 0; x < 4; x++, list_ptr1 += intsize) {
        for (int y = 0; y < 3; y++, list_ptr1 += intsize) {
            if (*(list_ptr1 - intsize) == *(list_ptr1)) {
                *(list_ptr1 - intsize) += *(list_ptr1);
                *(list_ptr1) = 0;
            }
        }
    }
    list_ptr1 = list_ptr;
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 4; x++, list_ptr1 += intsize) {
            for (int y = 0; y < 3; y++, list_ptr1 += intsize) {
                if (*(list_ptr1 - intsize) == 0) {
                    *(list_ptr1 - intsize) = *(list_ptr1 + x * 16 + y * 4);
                    *(list_ptr1 - intsize) = 0;
                }
            }
        }
    }
}

int win(int *checklist_ptr, int *list_ptr) {
    bool full = 1;
    for (int next_step = 0; next_step < 4; next_step++) {
    	copy(checklist_ptr, list_ptr);
    	if (full == 0)
    		break;
    	switch (next_step) {
                case 0:
                    up(list_ptr + intsize * 4);
                    break;
                case 1:
                    down(list_ptr);
                    break;
                case 2:
                    left(list_ptr);
                    break;
                case 3:
                    right(list_ptr);
                    break;
            }
	    for (int x = 0; x < 4; x++) {
	        for (int y = 0; y < 4; y++) {
				if (*(list_ptr + x * 16 + y * 4) == 0) {
	            	full = 0;
	                break;
	            }
	        }
	    }
	    for (int x = 0; x < 4; x++) {
	        for (int y = 0; y < 4; y++) {
	            *(list_ptr + x * 16 + y * 4) = *(checklist_ptr + x * 16 + y * 4);
	        }
	    }
	}
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (*(list_ptr + x * 16 + y * 4) == 2048) {
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
