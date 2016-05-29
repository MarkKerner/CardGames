#ifndef DECK_H
#define DECK_H

#include <vector>

#include "card.h"

class Deck
{
public:
    std::vector<Card> cards;

    Deck();

private:
    void initCards();
};

#endif // DECK_H
