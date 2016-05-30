#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QPushButton>
#include <QHBoxLayout>

#include "base/deck.h"
#include "hand.h"
#include "blackjackhandevaluator.h"

#include "widget/cardwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    initWindow();
    initButtons();

    startGame();
}

void MainWindow::initWindow()
{
    setFixedSize(800, 600);

    QGridLayout* layout = new QGridLayout();

    dealerCardWidget = new CardWidget();
    layout->addWidget(dealerCardWidget, 0, 0);

    QWidget* middleWidget = new QWidget();
    middleLayout = new QHBoxLayout(middleWidget);
    layout->addWidget(middleWidget, 1, 0);

    playerCardWidget = new CardWidget();
    layout->addWidget(playerCardWidget, 2, 0);


    QWidget* window = new QWidget();
    window->setLayout(layout);
    setCentralWidget(window);
}

void MainWindow::initButtons()
{
    dealBtn = new QPushButton("Deal");
    hitBtn = new QPushButton("Hit");
    standBtn = new QPushButton("Stand");
    restartBtn = new QPushButton("Play again");


    connect(dealBtn, SIGNAL (released()), this, SLOT(handleDealBtn()));
    connect(hitBtn, SIGNAL (released()), this, SLOT(handleHitBtn()));
    connect(standBtn, SIGNAL (released()), this, SLOT(handleStandBtn()));
    connect(restartBtn, SIGNAL (released()), this, SLOT(handleRestartBtn()));


    middleLayout->addWidget(dealBtn);
    middleLayout->addWidget(hitBtn);
    middleLayout->addWidget(standBtn);
    middleLayout->addWidget(restartBtn);

    dealBtn->hide();
    hitBtn->hide();
    standBtn->hide();
    restartBtn->hide();
}

void MainWindow::startGame()
{
    game = BlackJackGame();

    dealBtn->show();
}

void MainWindow::handleDealBtn()
{

    dealBtn->hide();
    hitBtn->show();
    standBtn->show();

    game.dealCards();

    dealerCardWidget->setHand(game.dealerHand);
    playerCardWidget->setHand(game.playerHand);

    game.playerHandStatus = game.handStatusEvaluation(game.playerHand, true);

    handlePlayerHandStatus(game.playerHandStatus);
}

void MainWindow::handleHitBtn()
{
    game.playerHit();

    playerCardWidget->setHand(game.playerHand);

    game.playerHandStatus = game.handStatusEvaluation(game.playerHand, false);
    handlePlayerHandStatus(game.playerHandStatus);
}

void MainWindow::handleStandBtn()
{
    this->startDealerTurn();
}

void MainWindow::startDealerTurn()
{
    hitBtn->hide();
    standBtn->hide();

    game.dealerHandStatus = game.handStatusEvaluation(game.dealerHand, true);
    handleDealerHandStatus(game.dealerHandStatus);
}

void MainWindow::dealerHit()
{
    game.dealerHit();
    dealerCardWidget->setHand(game.dealerHand);

    game.dealerHandStatus = game.handStatusEvaluation(game.dealerHand, false);
    handleDealerHandStatus(game.dealerHandStatus);
}


void MainWindow::handlePlayerHandStatus(BlackJackGame::HandStatus handStatus)
{
    switch (handStatus)
    {
    case BlackJackGame::HandStatus::BLACKJACK:
        this->endGame("BLACKJACK!?!?!?!?w0000t");
        break;
    case BlackJackGame::HandStatus::BUST:
        this->endGame("You are bust!");
        break;
    case BlackJackGame::HandStatus::VALUE_21:
        this->startDealerTurn();
        break;
    }
}

void MainWindow::handleDealerHandStatus(BlackJackGame::HandStatus handStatus)
{
    switch (handStatus) {
    case BlackJackGame::HandStatus::BLACKJACK:
    case BlackJackGame::HandStatus::VALUE_21:
    case BlackJackGame::HandStatus::UNDER_21:

        compareHands(game.playerHand, game.playerHandStatus,
                     game.dealerHand, game.dealerHandStatus);
        break;
    case  BlackJackGame::HandStatus::BUST:
        this->endGame("Dealer went bust! Player wins!!");
    }
}

void MainWindow::compareHands(Hand& playerHand, BlackJackGame::HandStatus playerHandStatus,
                              Hand& dealerHand, BlackJackGame::HandStatus dealerHandStatus)
{
    if (dealerHandStatus > playerHandStatus)
    {
        this->endGame("You lose!");
    } else if (dealerHandStatus < playerHandStatus)
    {
        this->dealerHit();
    } else if (dealerHandStatus == playerHandStatus)
    {
        if (dealerHandStatus == BlackJackGame::HandStatus::VALUE_21)
        {
            this->endGame("You win");
        } else if (dealerHandStatus == BlackJackGame::HandStatus::UNDER_21)
        {
            if (BlackjackHandEvaluator::eval(dealerHand) > BlackjackHandEvaluator::eval(playerHand))
                this->endGame("You lose!");
            else
                this->dealerHit();
        }
    }
}

void MainWindow::endGame(std::string message)
{
    hitBtn->hide();
    standBtn->hide();


    this->inEndState = true;
    this->endMessage = message;
    update();

    restartBtn->show();
}

void MainWindow::handleRestartBtn()
{
    this->restartBtn->hide();
    this->inEndState = false;
    this->playerCardWidget->clear();
    this->dealerCardWidget->clear();
    update();
    this->startGame();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    if (inEndState)
    {
        QPainter painter(this);

        painter.drawText(QPoint(width() / 2, height() / 2 - 50), QString::fromStdString(this->endMessage));
    }
}
