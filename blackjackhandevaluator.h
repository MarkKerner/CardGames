#ifndef BLACKJACKHANDEVALUATOR_H
#define BLACKJACKHANDEVALUATOR_H

#include "base/card.h"
#include "hand.h"


class BlackjackHandEvaluator
{
public:
    /**
     * @brief eval return the highest evaluation for the hand
     * @param hand
     * @return evaluation of the deck as integer
     */
    static int eval(Hand& hand);

};

#endif // BLACKJACKHANDEVALUATOR_H
