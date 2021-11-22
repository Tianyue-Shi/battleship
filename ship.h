
#ifndef BATTLESHIP_SHIP_H
#define BATTLESHIP_SHIP_H

struct ship {
    char symbol;
    int length;
    char *name;
    int life;
    int dir;
    char row;
    int col;
};

/*
 * Struct functions
 */
char getSymbol(struct ship ships);
char* getShipName(struct ship ships);
int getLength(struct ship ships);
int getLife(struct ship ships);
int getDirection(struct ship ships);
char getRow(struct ship ships);
int getCol(struct ship ships);
void setRow(struct ship ships, char c);
void setCol(struct ship ships, int col);

#endif //BATTLESHIP_SHIP_H
