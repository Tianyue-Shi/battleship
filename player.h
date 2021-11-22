
#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

struct player {
    char *name;
    int numHits;
    int numMisses;
};

/*
 *  Functions for player class.
 */
char* getPlayerName(struct player p);
void incHits(struct player p);
void incMisses(struct player p);
int getHits(struct player p);
int getMisses(struct player p);
int getTotalShots(struct player p);
double getHitPercentage(struct player p);

#endif //BATTLESHIP_PLAYER_H
