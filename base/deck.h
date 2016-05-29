#ifndef DECK_H
#define DECK_H

#include "card.h"

class Deck
{
public:
    static const int numSuits = Card::CS_Max;
    static const int numRanks = Card::CR_Max;

    Card cards [numSuits * numRanks];
    unsigned short size;

    Deck();

    void generate();
    void shuffle();
    Card popCard();
};

#endif // DECK_H
