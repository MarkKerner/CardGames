#include <string>

#include "card.h"

Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank)
{

}

std::string Card::suitString(const Suit &suit) const
{
    switch (suit)
    {
    case Suit::Hearts:
        return "Hearts";
    case Suit::Diamonds:
        return "Diamonds";
    case Suit::Clubs:
        return "Clubs";
    case Suit::Spades:
        return "Spades";
    default:
        return nullptr;
    }
}

std::string Card::rankString(const Rank &rank) const
{
    switch(rank)
    {
    case Rank::Ace:
        return "Ace";
    case Rank::Two:
        return "Two";
    case Rank::Three:
        return "Three";
    case Rank::Four:
        return "Four";
    case Rank::Five:
        return "Five";
    case Rank::Six:
        return "Six";
    case Rank::Seven:
        return "Seven";
    case Rank::Eight:
        return "Eight";
    case Rank::Nine:
        return "Nine";
    case Rank::Ten:
        return "Ten";
    case Rank::Jack:
        return "Jack";
    case Rank::Queen:
        return "Queen";
    case Rank::King:
        return "King";
    default:
        return nullptr;
    }
}


std::ostream &operator<<(std::ostream &stream,
                         const Card &c)
{
    return stream << c.rankString(c.rank) << " of " << c.suitString(c.suit);
}
