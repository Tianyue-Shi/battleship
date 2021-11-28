#include <stdio.h>
#include <stdlib.h>
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
Boolean isDuplicate; /* Overlap positions */
Boolean playerTurn; /* true: Player 1's turn  /  false: Player 2's turn */
Boolean duplicateHit = false; /* Flag for checking duplicate user hit coordinates during match */



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

void placeShips(struct cell board[row][col], struct ship ships[5], int i, int dir) {
    isDuplicate = false;
    isValidPlacement = false;
    switch (dir) {
        case 1:
            if (ships[i].length <= (ships[i].row - 'a' + 1)) {
                for (int j = ships[i].length; j > 0; j--) {
                    if (board[ships[i].row - 'a' - j + 1][ships[i].col].symbol != '~') {
                        printf("\nError: Location is occupied by another ship!\n");
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    isValidPlacement = true;
                    for (int j = ships[i].length; j > 0; j--) {
                        board[ships[i].row - 'a' - j + 1][ships[i].col].symbol = (ships[i]).symbol;
                    }
                }
            } else {
                printf("\nError: Ship will be out of bounds. Please choose again!\n");
            }
            break;
        case 2:
            if ((ships[i].length) <= (row - (ships[i].row - 'a'))) {
                for (int j = (ships[i]).length; j > 0; j--) {
                    if (board[(ships[i].row) - 'a' + j - 1][(ships[i]).col].symbol != '~') {
                        printf("\nError: Location is occupied by another ship!\n");
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    isValidPlacement = true;
                    for (int j = (ships[i]).length; j > 0; j--) {
                        board[(ships[i].row) - 'a' + j - 1][(ships[i]).col].symbol = (ships[i]).symbol;
                    }
                }
            } else {
                printf("\nError: Ship will be out of bounds. Please choose again!\n");
            }
            break;
        case 3:
            if ((ships[i]).length <= ships[i].col + 1) {
                for (int j = (ships[i]).length; j > 0; j--) {
                    if (board[(ships[i]).row - 'a'][ships[i].col - j + 1].symbol != '~') {
                        printf("\nError: Location is occupied by another ship!\n");
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    isValidPlacement = true;
                    for (int j = (ships[i]).length; j > 0; j--) {
                        board[(ships[i]).row - 'a'][ships[i].col - j + 1].symbol = (ships[i]).symbol;
                    }
                }
            } else {
                printf("\nError: Ship will be out of bounds. Please choose again!\n");
            }
            break;
        case 4:
            if ((ships[i]).length <= col - ships[i].col) {
                for (int j = (ships[i]).length; j > 0; j--) {
                    if (board[(ships[i]).row - 'a'][ships[i].col + j - 1].symbol != '~') {
                        printf("\nError: Location is occupied by another ship!\n");
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    isValidPlacement = true;
                    for (int j = (ships[i]).length; j > 0; j--) {
                        board[(ships[i]).row - 'a'][ships[i].col + j - 1].symbol = ships[i].symbol;
                    }
                }
            } else {
                printf("\nError: Ship will be out of bounds. Please choose again!\n");
            }
            break;
        default:
            printf("\nError: Invalid direction. Please choose again!\n");

    }

}

char *assignPosition(struct ship ships[5], int i) {
    char *start = malloc(5);
    printf("\nEnter starting position of length %d %s (i.e. b1, a3, etc.): ", ships[i].length, ships[i].name);
    scanf("%s", start);

    return start;
}

void placeShipsManually(struct cell board[row][col], struct ship ships[5]) {
    for (int i = 0; i < 5; i++) {
        do {
            char *start;
            char *ptr;
            int nums;
            start = assignPosition(ships, i);

            ships[i].row = start[0];
            nums = strtol(start + 1, &ptr, 10);
            ships[i].col = nums - 1;

            printf("\n1. up  2. down  3. left  4. right");
            printf("\nEnter the direction of the %s: ", ships[i].name);
            scanf("%d", &dir);

            placeShips(board, ships, i, dir);
            printf("\n");
            printBoard(board);
            printf("\n");
        } while (isValidPlacement == false);
    }
    printf("\n");
    printBoard(board);
    printf("");
}

void placeShipsRandomly(struct cell board[row][col], struct ship ships[5]) {

}

void gameSetting(struct cell board[row][col], struct ship ships[5]) {
    printf("\nChoose your settings for this Battleship game.\n");
    printf("1. Manually\n");
    printf("2. Randomly\n");
    printf("Enter choice: ");
    scanf("%d", &setting);

    if (setting == 1) {
        placeShipsManually(board, ships);
    } else {
        placeShipsRandomly(board, ships);
    }
}

void checkWinner(struct ship player1Ships[5], struct ship player2Ships[5]) {
    if (player1Ships[0].life == 0 &&
        player1Ships[1].life == 0 &&
        player1Ships[2].life == 0 &&
        player1Ships[3].life == 0 &&
        player1Ships[4].life == 0) {
        printf("\nGAME OVER\n%s WINS!\n", name2);
        end = true;
    } else if (player2Ships[0].life == 0 &&
               player2Ships[1].life == 0 &&
               player2Ships[2].life == 0 &&
               player2Ships[3].life == 0 &&
               player2Ships[4].life == 0) {
        printf("\nGAME OVER\n%s WINS!\n\n", name1);
        end = true;
    }
}

void runStats(struct player players[2], struct ship player1Ships[5], struct ship player2Ships[5]){
    players[0].successfulHits = 17 - player2Ships[0].life
                                - player2Ships[1].life
                                - player2Ships[2].life
                                - player2Ships[3].life
                                - player2Ships[4].life;
    players[1].successfulHits = 17 - player1Ships[0].life
                                - player1Ships[1].life
                                - player1Ships[2].life
                                - player1Ships[3].life
                                - player1Ships[4].life;
    printf("\n%s's Stats:\nSuccessful hit rate: %.2f %%\n", name1, (players[0].successfulHits/players[0].totalHits) * 100);
    printf("%s's Stats:\nSuccessful hit rate: %.2f %%\n\n", name2, (players[1].successfulHits/players[1].totalHits) * 100);
}

void runMatch(struct cell board1[row][col], struct cell board2[row][col], struct ship player1Ships[5],
              struct ship player2Ships[5], struct player players[2]) {
    struct cell radar1[row][col];
    struct cell radar2[row][col];
    initializeBoard(radar1);
    initializeBoard(radar2);
    do {
        if (playerTurn) {
            printf("\n");
            printf("\n%s's radar:\n", name1);
            printBoard(radar1);
            printf("\n%s's turn:\nPick a coordinate to hit (i.e. b1, a3, etc.): ", name1);
            char *start = malloc(5);
            char *ptr;
            int nums;
            scanf("%s", start);
            nums = strtol(start + 1, &ptr, 10) - 1;

            do {
                if (board2[start[0] - 'a'][nums].symbol == 'X' ||
                        board2[start[0] - 'a'][nums].symbol == 'O'){
                    duplicateHit = true;
                    printf("\nError: You've chosen this location before! Please pick again.\n");

                    printf("\n");
                    printBoard(radar1);
                    printf("\n%s's turn:\nPick a coordinate to hit (i.e. b1, a3, etc.): ", name1);
                    scanf("%s", start);
                    nums = strtol(start + 1, &ptr, 10) - 1;
                }else{
                    duplicateHit = false;
                }
            } while(duplicateHit);

            players[0].totalHits++;
            if (board2[start[0] - 'a'][nums].symbol != '~') {
                printf("\nHit on target!\n\n%s's radar: \n", name1);
                switch (board2[start[0] - 'a'][nums].symbol) {
                    case 'c':
                        player2Ships[0].life--;
                        break;
                    case 'b':
                        player2Ships[1].life--;
                        break;
                    case 'r':
                        player2Ships[2].life--;
                        break;
                    case 's':
                        player2Ships[3].life--;
                        break;
                    case 'd':
                        player2Ships[4].life--;
                        break;
                };
                radar1[start[0] - 'a'][nums].symbol = 'X';
                board2[start[0] - 'a'][nums].symbol = 'X';
            } else {
                printf("\nMiss! Better luck next time!\n\n%s's radar: \n", name1);
                radar1[start[0] - 'a'][nums].symbol = 'O';
            }
            printBoard(radar1);
            printf("\n");
            playerTurn = false;
        } else {
            printf("\n");
            printf("\n%s's radar:\n", name2);
            printBoard(radar2);
            printf("\n%s's turn:\nPick a coordinate to hit (i.e. b1, a3, etc.): ", name2);
            char *start = malloc(5);
            char *ptr;
            int nums;
            scanf("%s", start);
            nums = strtol(start + 1, &ptr, 10) - 1;

            do {
                if (board1[start[0] - 'a'][nums].symbol == 'X' ||
                    board1[start[0] - 'a'][nums].symbol == 'O'){
                    duplicateHit = true;
                    printf("\nError: You've chosen this location before! Please pick again.\n");

                    printf("\n");
                    printBoard(radar2);
                    printf("\n%s's turn:\nPick a coordinate to hit (i.e. b1, a3, etc.): ", name2);
                    scanf("%s", start);
                    nums = strtol(start + 1, &ptr, 10) - 1;
                }else{
                    duplicateHit = false;
                }
            } while(duplicateHit);

            players[1].totalHits++;
            if (board1[start[0] - 'a'][nums].symbol != '~') {
                printf("\nHit on target!\n\n%s's radar: \n", name2);
                switch (board1[start[0] - 'a'][nums].symbol) {
                    case 'c':
                        player1Ships[0].life--;
                        break;
                    case 'b':
                        player1Ships[1].life--;
                        break;
                    case 'r':
                        player1Ships[2].life--;
                        break;
                    case 's':
                        player1Ships[3].life--;
                        break;
                    case 'd':
                        player1Ships[4].life--;
                        break;
                };
                radar2[start[0] - 'a'][nums].symbol = 'X';
                board1[start[0] - 'a'][nums].symbol = 'X';
            } else {
                printf("\nMiss! Better luck next time!\n\n%s's radar: \n", name2);
                radar2[start[0] - 'a'][nums].symbol = 'O';
            }
            printBoard(radar2);
            printf("\n");
            playerTurn = true;
        }

        checkWinner(player1Ships, player2Ships);
    } while (!end);
    runStats(players, player1Ships, player2Ships);
}


int main() {

    welcome();
    while (!end) {

        getBoardInfo();
        struct player players[2] = {{name1, 0, 0, 0},
                                    {name2, 0, 0, 0}};
        struct cell board1[row][col];
        struct cell board2[row][col];

        initializeBoard(board1);
        initializeBoard(board2);
        printf("\n\n%s's board:\n", name1);
        printBoard(board1);
        printf("\n%s's board:\n", name2);
        printBoard(board2);

        struct ship player1Ships[5] = {{'c', 5, "Carrier",    5, 0, 'a', 0},
                                       {'b', 4, "Battleship", 4, 0, 'a', 0},
                                       {'r', 3, "Cruiser",    3, 0, 'a', 0},
                                       {'s', 3, "Submarine",  3, 0, 'a', 0},
                                       {'d', 2, "Destroyer",  2, 0, 'a', 0}};
        struct ship player2Ships[5] = {{'c', 5, "Carrier",    5, 0, 'a', 0},
                                       {'b', 4, "Battleship", 4, 0, 'a', 0},
                                       {'r', 3, "Cruiser",    3, 0, 'a', 0},
                                       {'s', 3, "Submarine",  3, 0, 'a', 0},
                                       {'d', 2, "Destroyer",  2, 0, 'a', 0}};
        printf("\nPlayer 1:\n");
        gameSetting(board1, player1Ships);
        for (int i = 0; i < 25; ++i) {
            printf("\n");
        }
        printf("\nPlayer 2:\n");
        gameSetting(board2, player2Ships);
        for (int i = 0; i < 18; ++i) {
            printf("\n");
        }

        runMatch(board1, board2, player1Ships, player2Ships, players);
    }

    return 0;
}
