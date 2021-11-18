#include <stdio.h>
#include <MacTypes.h>
#include "ship.h"
#include "cell.h"
#include "player.h"

int row, col;
char name1[20], name2[20];  /* Player's name */
Boolean end = false; /* End game flag */
int setting; /* 1. Manually  2. Randomly  */

void getBoardInfo() {
    printf("\nPlayer 1 name: ");
    scanf("%s", name1);
    printf("Player 2 name: ");
    scanf("%s", name2);
    printf("Number of rows: ");
    scanf("%d", &row);
    printf("Number of columns: ");
    scanf("%d", &col);
}

void initializeBoard(struct cell board[][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j].row = row;
            board[i][j].col = col;
            board[i][j].symbol = '~';
        }
    }
}

void printBoard(struct cell board[][col]) {
    printf("    ");
    for (int j = 0; j < col; j++) {
        printf("%d  ", j + 1);
    }
    printf("\n   ---------------");

    for (int i = 0; i < row; ++i) {
        printf("\n%c ", 'A' + i);
        printf("|");
        for (int j = 0; j < col; j++) {
            printf(" %c ", board[i][j].symbol);
        }
        printf("|");
    }
    printf("\n   ---------------\n");

}

void gameSetting(){
    printf("\nChoose your settings for this Battleship game.");
    printf ("1. Manually\n");
    printf ("2. Randomly\n");
    printf ("Enter choice: ");
    scanf ("%d", &setting);
}

int main() {

    welcome();
    while (end != true) {

        getBoardInfo();
        struct player players[2] = {{name1, 0, 0},
                                    {name2, 0, 0}};
        struct cell board1[row][col];
        struct cell board2[row][col];

        initializeBoard(board1);
        initializeBoard(board2);
        printf("\n\n%s's board:\n", name1);
        printBoard(board1);
        printf("\n%s's board:\n", name2);
        printBoard(board2);

        gameSetting();
        struct ship ships[5] = {{'c', 5, "Carrier", 5, 0},
                                {'b', 4, "Battleship", 4, 0},
                                {'r', 3, "Cruiser", 3, 0},
                                {'s', 3, "Submarine", 3, 0},
                                {'d', 2, "Destroyer", 2, 0}};


    }


    return 0;
}
