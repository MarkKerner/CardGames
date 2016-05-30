#include <string>
#include <iostream>
#include <sstream>

#include "card.h"

std::string to_string(const Card::Suit& suit)
{
    static const char* values[Card::Suit::CS_Max] =
    {
        "Hearts", "Diamons", "Clubs", "Spades"
    };

    return 0 <= suit && suit < Card::Suit::CS_Max ? values[suit] : "<invalid>";
}

std::string to_string(const Card::Rank& rank)
{
    static const char* values[Card::Rank::CR_Max] =
    {
        "Ace", "Two", "Three",
        "Four", "Five", "Six",
        "Seven", "Eight", "Nine",
        "Ten", "Jack", "Queen",
        "King"
    };

    return 0 <= rank && rank < Card::Rank::CR_Max ? values[rank] : "<invalid>";
}

std::string to_string(const Card& c)
{
    std::stringstream ss;
    ss << to_string(c.rank) << " of " << to_string(c.suit);
    return ss.str();
}


std::ostream &operator<<(std::ostream &stream,
                         const Card &c)
{
    return stream << to_string(c);
}
