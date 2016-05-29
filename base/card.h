#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Card
{
public:
    enum class Suit
    {
        Hearts,
        Diamonds,
        Clubs,
        Spades
    };

    enum class Rank
    {
        Ace,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King
    };

    Suit suit;
    Rank rank;

    Card(Suit suit, Rank rank);

protected:
    std::string suitString(const Suit &suit) const;
    std::string rankString(const Rank &rank) const;

    friend std::ostream &operator<<(std::ostream &stream,
                                    const Card &c);
};

#endif // CARD_H
