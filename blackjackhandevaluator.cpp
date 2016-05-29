#include "blackjackhandevaluator.h"

#include <vector>
#include <algorithm>

#include "base/card.h"
#include "hand.h"

int BlackjackHandEvaluator::eval(Hand& hand)
{
    std::vector<int> values {0};

    for (auto handIt = hand.cards.begin(); handIt != hand.cards.end(); ++handIt)
    {
        Card card = *handIt;

        for (auto valueIt = values.begin(); valueIt != values.end(); ++valueIt)
        {

            switch(card.rank)
            {
            case Card::Rank::CR_Ace:
                //values.push_back(*valueIt + 1);
                //values.push_back(*valueIt + 11);
                //values.erase(valueIt);
                break;

            case Card::Rank::CR_Jack:
            case Card::Rank::CR_Queen:
            case Card::Rank::CR_King:
                 *valueIt += 10;
                break;
            default:
                *valueIt += card.rank + 1;
                break;
            }
        }
    }

    //
    sort(values.begin(), values.end(), std::greater<int>());

    auto valueIt = values.begin();
    for (; valueIt != values.end(); ++valueIt)
    {
        int value = *valueIt;
        if (value <= 21)
            return value;
    }
    return *valueIt;
}
