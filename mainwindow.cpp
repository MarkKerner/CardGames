#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "base/deck.h"
#include "hand.h"
#include "blackjackhandevaluator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setFixedSize(800, 600);

}
