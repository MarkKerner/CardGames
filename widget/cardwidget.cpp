#include <string>

#include <QPainter>

#include "cardwidget.h"
#include "base/card.h"
#include "hand.h"
#include "blackjackhandevaluator.h"


CardWidget::CardWidget(QWidget* parent) :
    QWidget(parent),
    drawCards(false)
{

}

void CardWidget::setHand(Hand& hand)
{

    this->cards = &(hand.cards);
    this->handValue = std::to_string(BlackjackHandEvaluator::eval(hand));

    drawCards = true;

    update();
}

void CardWidget::clear()
{
    this->drawCards = false;
    this->cards = nullptr;
    update();
}

void CardWidget::paintEvent(QPaintEvent *)
{
    if (drawCards)
    {

        QPainter painter(this);
        QFont font;
        font.setPixelSize(12);
        painter.setFont(font);

        unsigned short numCards = cards->size();
        int startingX = width() / 2 - (numCards * (CARD_WIDTH + CARD_MARGIN) - CARD_MARGIN) / 2;

        for (unsigned short i = 0; i < numCards; ++i)
        {
            QPoint cardTopLeftPoint(startingX + i * (CARD_WIDTH + CARD_MARGIN), CARD_MARGIN);
            QRect cardFrame (
                        cardTopLeftPoint,
                        cardSize
                        );

            Card& card = cards->at(i);


            QString qRankName = QString::fromStdString(to_string(card));
            painter.drawRect(cardFrame);

            painter.drawText(cardTopLeftPoint.x() + 10,
                             cardTopLeftPoint.y() + 20,
                             qRankName
                             );
        }

        int middleWidth = startingX + (numCards * (CARD_WIDTH + CARD_MARGIN) - CARD_MARGIN) / 2;
        painter.drawText(
                    middleWidth,
                    CARD_MARGIN/2,
                    QString::fromStdString(handValue));

    }
}
