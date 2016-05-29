
#include<array>

#include "deck.h"
#include "card.h"


Deck::Deck()
{
    initCards();
}

void Deck::initCards()
{
    std::array<Card::Suit, 4> suits {Card::Suit::Clubs, Card::Suit::Diamonds, Card::Suit::Hearts, Card::Suit::Spades};

}
