#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "base/deck.h"
#include "hand.h"
#include "blackjackhandevaluator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    for (int i = 0; i < 100; ++i)
    {
        Deck deck;
        deck.shuffle();
        Hand hand;
        Card card1 = deck.popCard();
        Card card2 = deck.popCard();

        hand.addCard(card1);
        hand.addCard(card2);

        std::cout << card1 << '\t' << card2 << '\t' << BlackjackHandEvaluator::eval(hand) << std::endl;
    }

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
