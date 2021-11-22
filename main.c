#include <stdio.h>
#include <MacTypes.h>
#include "ship.h"
#include "cell.h"
#include "player.h"

/**
 * Global variables
 */
int row, col;
char name1[20], name2[20];  /* Player's name */
Boolean end = false; /* End game flag */
int setting; /* 1. Manually  2. Randomly  */
int dir; /* 1. up  2. down  3. left  4. right */
Boolean isValidPlacement; /* Validity of ship placement on the board */


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

void placeShips(struct cell board[row][col], struct ship ships[5], int i, int dir){
    switch(dir){
        case 1:
            if(getLength(ships[i]) <= (getRow(ships[i]) - 'a')){
                isValidPlacement = true;
                for(int j = getLength(ships[i]); j > 0; j--){
                    setSymbol(board[getRow(ships[i]) - 'a' - j + 1][getCol(ships[i])], getSymbol(ships[i]));
                }
            }
            break;
        case 2:
            if(getLength(ships[i]) <= (row - getRow(ships[i]))){
                isValidPlacement = true;
                for(int j = getLength(ships[i]); j > 0; j--){
                    setSymbol(board[getRow(ships[i]) - 'a' + j - 1][getCol(ships[i])], getSymbol(ships[i]));
                }
            }
            break;
        case 3:
            if(getLength(ships[i]) <= getCol(ships[i])){
                isValidPlacement = true;
                for(int j = getLength(ships[i]); j > 0; j--){
                    setSymbol(board[getRow(ships[i]) - 'a'][getCol(ships[i]) - j + 1], getSymbol(ships[i]));
                }
            }
            break;
        case 4:
            if(getLength(ships[i]) <= col - getCol(ships[i])){
                isValidPlacement = true;
                for(int j = getLength(ships[i]); j > 0; j--){
                    setSymbol(board[getRow(ships[i]) - 'a'][getCol(ships[i]) + j - 1], getSymbol(ships[i]));
                }
            }
            break;
        default:
            isValidPlacement = false;
            printf("\nError: Ship will be out of bounds. Please choose again!\n");

    }

}

void placeShipsManually(struct cell board[row][col], struct ship ships[5]){
    for(int i = 0; i < 5; i++){
        do{
            char start[2];
            printf("\nEnter starting position of length %d %s (i.e. b1, a3, etc.): ", getLength(ships[i]), getShipName(ships[i]));
            scanf("%s", start);
            setRow(ships[i], start[0]);
            setCol(ships[i], start[1]);

            printf("\n1. up  2. down  3. left  4. right");
            printf("\nEnter the direction of the %s: ", getShipName(ships[i]));
            scanf("%d", &dir);

            placeShips(board, ships, i, dir);
            printf("\n");
            printBoard(board);
        }while(isValidPlacement == false);
    }
    printf("\n");
    printBoard(board);
    printf("");
}

void placeShipsRandomly(struct cell board[row][col], struct ship ships[5]){

}

void gameSetting(struct cell board[row][col], struct ship ships[5]){
    printf("\nChoose your settings for this Battleship game.\n");
    printf ("1. Manually\n");
    printf ("2. Randomly\n");
    printf ("Enter choice: ");
    scanf ("%d", &setting);

    if(setting == 1){
        placeShipsManually(board, ships);
    }
    else{
        placeShipsRandomly(board, ships);
    }
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

        struct ship ships[5] = {{'c', 5, "Carrier", 5, 0, 'a', 0},
                                {'b', 4, "Battleship", 4, 0, 'a', 0},
                                {'r', 3, "Cruiser", 3, 0, 'a', 0},
                                {'s', 3, "Submarine", 3, 0, 'a', 0},
                                {'d', 2, "Destroyer", 2, 0, 'a', 0}};
        gameSetting(board1, ships);
        gameSetting(board2, ships);


    }

    return 0;
}
