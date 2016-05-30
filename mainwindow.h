#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>

#include "widget/cardwidget.h"

#include "blackjackgame.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private slots:
    void handleDealBtn();
    void handleHitBtn();
    void handleStandBtn();
    void handleRestartBtn();

private:
    CardWidget* dealerCardWidget;
    CardWidget* playerCardWidget;

    QHBoxLayout* middleLayout;

    QPushButton* dealBtn;
    QPushButton* hitBtn;
    QPushButton* standBtn;

    QPushButton* restartBtn;

    BlackJackGame game;

    bool inEndState;
    std::string endMessage;

    void initWindow();
    void initButtons();

    void drawCards(const Hand& hand, QWidget* widget);

    void startGame();
    void dealCards();

    void startDealerTurn();
    void dealerHit();

    void handlePlayerHandStatus(BlackJackGame::HandStatus handStatus);
    void handleDealerHandStatus(BlackJackGame::HandStatus handStatus);

    void compareHands(Hand& playerHand, BlackJackGame::HandStatus playerHandStatus,
                            Hand& dealerHand, BlackJackGame::HandStatus dealerHandStatus);

    void endGame(std::string message);
};

#endif // MAINWINDOW_H
