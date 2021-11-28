#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

///**
// * Set cell symbol to object's symbol.
// * @param board
// * @param symbol
// */
//void setSymbol(struct cell board, char symbol){
//    board.symbol = symbol;
//}


/**
 * Author: Sara Antonijevic
 *
 * Prints welcome message and rules.
 */
void welcome() {
    printf("Welcome to Battleship!\n\n");
    printf("Rules:\n");
    printf("1. Player's take turns guessing by calling out the coordinates.\n");
    printf("2. The opponent responds with \"hit\" or \"miss\" as appropriate.\n");
    printf("3. Both players should mark their board with pegs:  X for hit, O for miss.\n");
    printf("4. When all of the squares that one your ship occupies have been hit, the ship will be sunk.\n");
    printf("5. As soon as all of one player's ship have been sunk, the game ends.\n");
}