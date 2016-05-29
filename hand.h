#ifndef HAND_H
#define HAND_H

#include <vector>

#include "base/card.h"


class Hand
{
public:

    std::vector<Card> cards;

    void addCard(Card card);
};

#endif // HAND_H
