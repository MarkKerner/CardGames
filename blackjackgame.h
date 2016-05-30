#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "base/deck.h"
#include "hand.h"


class BlackJackGame
{
public:

    enum HandStatus
    {
        BUST = 0,
        UNDER_21 = 1,
        VALUE_21 = 2,
        BLACKJACK = 3
    };

    Deck deck;

    Hand playerHand;
    HandStatus playerHandStatus;

    Hand dealerHand;
    HandStatus dealerHandStatus;

    BlackJackGame();

    void dealCards();

    void playerHit();
    void dealerHit();

    HandStatus handStatusEvaluation(Hand& hand, bool initial = false);
};

#endif // BLACKJACKGAME_H
