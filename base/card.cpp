#include <string>

#include "card.h"

Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank)
{

}

std::string Card::suitString(const Suit &suit) const
{
    switch (suit)
    {
    case Suit::CS_Hearts:
        return "Hearts";
    case Suit::CS_Diamonds:
        return "Diamonds";
    case Suit::CS_Clubs:
        return "Clubs";
    case Suit::CS_Spades:
        return "Spades";
    default:
        return nullptr;
    }
}

std::string Card::rankString(const Rank &rank) const
{
    switch(rank)
    {
    case Rank::CR_Ace:
        return "Ace";
    case Rank::CR_Two:
        return "Two";
    case Rank::CR_Three:
        return "Three";
    case Rank::CR_Four:
        return "Four";
    case Rank::CR_Five:
        return "Five";
    case Rank::CR_Six:
        return "Six";
    case Rank::CR_Seven:
        return "Seven";
    case Rank::CR_Eight:
        return "Eight";
    case Rank::CR_Nine:
        return "Nine";
    case Rank::CR_Ten:
        return "Ten";
    case Rank::CR_Jack:
        return "Jack";
    case Rank::CR_Queen:
        return "Queen";
    case Rank::CR_King:
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
