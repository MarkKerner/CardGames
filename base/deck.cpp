#include <array>
#include <algorithm>

#include "deck.h"
#include "card.h"


Deck::Deck() : size{0}
{
    generate();
}

void Deck::generate()
{
    for (int suit = 0; suit < Card::CS_Max; ++suit)
    {
        for (int rank = 0; rank < Card::CR_Max; ++rank)
        {
            cards[size++] = {static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank)};
        }
    }
}

void Deck::shuffle()
{
    std::random_shuffle(cards, cards + size);
}

Card Deck::popCard()
{
    return cards[--size];
}
