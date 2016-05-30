#include "blackjackgame.h"
#include "blackjackhandevaluator.h"

BlackJackGame::BlackJackGame(){}

void BlackJackGame::dealCards()
{
    deck.shuffle();

    playerHit();
    dealerHit();
    playerHit();
    dealerHit();
}

void BlackJackGame::playerHit()
{
    playerHand.addCard(deck.popCard());
}

void BlackJackGame::dealerHit()
{
    dealerHand.addCard(deck.popCard());
}

BlackJackGame::HandStatus BlackJackGame::handStatusEvaluation(Hand& hand, bool initial)
{
    int value = BlackjackHandEvaluator::eval(hand);

    if (value == 21)
    {
        if (initial) {
            return HandStatus::BLACKJACK;
        } else {
            return HandStatus::VALUE_21;
        }
    }
    else if (value > 21)
        return HandStatus::BUST;
    else
        return HandStatus::UNDER_21;

}
