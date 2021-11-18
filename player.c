//
// Created by Tianyue Shi on 11/17/21.
//
#include "player.h"

/**
 * Returns player's name.
 * @param p
 * @return *name
 */
char *getName(struct player p) {
    return p.name;
}

/**
 * Increments player's number of hits.
 * @param p
 */
void incHits(struct player p){
    p.numHits++;
}

/**
 * Increments player's number of misses.
 * @param p
 */
void incMisses(struct player p){
    p.numMisses++;
}

/**
 * Returns player's number of hits.
 * @param p
 * @return numHits
 */
int getHits(struct player p) {
    return p.numHits;
}

/**
 * Returns player's number of misses.
 * @param p
 * @return numMisses
 */
int getMisses(struct player p) {
    return p.numMisses;
}

/**
 * Returns player's total number of calls (hits + misses).
 * @param p
 * @return total calls
 */
int getTotalShots(struct player p) {
    return p.numHits + p.numMisses;
}

/**
 * Returns player's hit percentage ( hits/total ).
 * @param p
 * @return hit percentage
 */
double getHitPerctage(struct player p) {
    return (p.numHits / getTotalShots(p)) * 100;
}