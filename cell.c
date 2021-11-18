//
// Created by Tianyue Shi on 11/16/21.
//
#include <stdio.h>
#include <stdlib.h>

void welcome() {
    printf("Welcome to Battleship!\n\n");
    printf("Rules:\n");
    printf("1. Player's take turns guessing by calling out the coordinates.\n");
    printf("2. The opponent responds with \"hit\" or \"miss\" as appropriate.\n");
    printf("3. Both players should mark their board with pegs:  X for hit, O for miss.\n");
    printf("4. When all of the squares that one your ship occupies have been hit, the ship will be sunk.\n");
    printf("5. As soon as all of one player's ship have been sunk, the game ends.\n");
}