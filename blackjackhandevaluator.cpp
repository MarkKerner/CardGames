#include "blackjackhandevaluator.h"

#include <vector>
#include <algorithm>

#include "base/card.h"
#include "hand.h"

int BlackjackHandEvaluator::eval(Hand& hand)
{

    //    int value = 0;
    //    int numAces = 0;
    //    for (Card card : hand.cards)
    //    {
    //        switch (card.rank)
    //        {
    //        case CR_Ace:
    //            value += 11;
    //            numAces += 1;
    //            break;
    //        default:
    //            value += card.rank + 1;
    //            break;
    //        case CR_Jack:
    //        case CR_Queen:
    //        case CR_King:
    //            value += 10;
    //            break;
    //        }
    //    }

    //    while (value > 21 && numAces > 0)
    //    {
    //        value -= 10;
    //        --numAces;
    //    }
    //    return value;

    int value = 0;
    int numAces = 0;

    for (Card card : hand.cards)
    {
        switch (card.rank)
        {
        case Card::CR_Ace:
            value += 11;
            ++numAces;
            break;
        case Card::CR_Jack:
        case Card::CR_Queen:
        case Card::CR_King:
            value += 10;
            break;
        default:
            value += card.rank + 1;
            break;
        }
    }

    while (value > 21 && numAces > 0)
    {
        value -= 10;
        --numAces;
    }
    return value;
}
