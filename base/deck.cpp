#include<array>

#include "deck.h"
#include "card.h"


Deck::Deck() : deckSize{0}
{
    initCards();
}

void Deck::initCards()
{
    for (int suit = 0; suit < Card::CS_Max; ++suit)
    {
        for (int rank = 0; rank < Card::CR_Max; ++rank)
        {
            deck[deckSize++] = {static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank)};
        }
    }

}
