#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include "result.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     resDialog = new result;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     game *Gamewindow = new game(this,resDialog);
    Gamewindow->setFocus();
    Gamewindow->setFocusPolicy(Qt::StrongFocus);
    this->setGeometry(0,0,830,750);

    this->setCentralWidget(Gamewindow);
}
