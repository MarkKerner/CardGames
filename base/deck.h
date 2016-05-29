#ifndef DECK_H
#define DECK_H

#include <vector>

#include "card.h"

class Deck
{
public:
    static const int numSuits = Card::CS_Max;
    static const int numRanks = Card::CR_Max;

    Card deck [numSuits * numRanks];
    unsigned short deckSize;

    Deck();

private:
    void initCards();
};

#endif // DECK_H
