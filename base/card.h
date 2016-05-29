#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Card
{
public:
    enum Suit
    {
        CS_Hearts,
        CS_Diamonds,
        CS_Clubs,
        CS_Spades,
        CS_Max
    };

    enum Rank
    {
        CR_Ace,
        CR_Two,
        CR_Three,
        CR_Four,
        CR_Five,
        CR_Six,
        CR_Seven,
        CR_Eight,
        CR_Nine,
        CR_Ten,
        CR_Jack,
        CR_Queen,
        CR_King,
        CR_Max
    };

    Suit suit;
    Rank rank;

    Card() = default;
    Card(Suit suit, Rank rank);

protected:
    std::string suitString(const Suit &suit) const;
    std::string rankString(const Rank &rank) const;

    friend std::ostream &operator<<(std::ostream &stream,
                                    const Card &c);
};

#endif // CARD_H
