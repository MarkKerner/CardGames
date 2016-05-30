#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>

#include "base/card.h"
#include "hand.h"


class CardWidget : public QWidget
{
public:
    explicit CardWidget(QWidget* parent = 0);

    std::vector<Card>* cards;
    std::string handValue;

public slots:
    void setHand(Hand& hand);
    void clear();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:

    static const int CARD_HEIGHT = 160;
    static const int CARD_WIDTH = 100;
    static const int CARD_MARGIN = 20;

    bool drawCards;
    const QSize cardSize{CARD_WIDTH, CARD_HEIGHT};
};

#endif // CARDWIDGET_H
