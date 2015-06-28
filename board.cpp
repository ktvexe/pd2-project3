#include "board.h"
#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <string>

#include <QKeyEvent>

Board::Board(QWidget *parent,  int Row, int Col) : QObject(parent)
{
    row=Row;
    col=Col;

    button=new QPushButton(parent);
    button->setGeometry(74*col+140,74*row+10,74,74);
    //button->setStyleSheet("border-style:dashed ;");
     connect(button, SIGNAL (clicked()), this, SLOT (on_button_clicked()));
}

int Board::clicktime =0;
int Board::checktype1=0;
int Board::checktype2=0;
int Board::totaltimes=10;
//bool Board::change=false;
Board*  Board::boardptr;


Board::~Board()
{
    delete button;
}

void Board::init( ){

    //srand((unsigned)time(NULL));
    int type = random() % 6;


    switch (type) {
    case 0:
    {
        //button->setStyleSheet("border-style:dashed ;");
        typenum=1;
       button->setStyleSheet("background-image: url(:/1.png);");

         break;
    }
    case 1:
    {
        button->setStyleSheet("background-image: url(:/2.png);");
        typenum=2;
            //button->setStyleSheet("background-image: url(:/pic/2.png);");
        break;
    }
    case 2:
    {
        button->setStyleSheet("background-image: url(:/3.png);");
        typenum=3;
        // button->setStyleSheet("background-image: url(:/pic/3.png);");
        break;
    }
    case 3:
    {
        button->setStyleSheet("background-image: url(:/4.png);");
        typenum=4;
        //button->setStyleSheet("background-image: url(:/pic/4.png);");
       break;
    }
    case 4:
    {
        button->setStyleSheet("background-image: url(:/5.png);");
        typenum=5;
        //button->setStyleSheet("background-image: url(:/pic/5.png);");
       break;
    }
    case 5:
    {
        button->setStyleSheet("background-image: url(:/6.png);");
        typenum=6;
        //button->setStyleSheet("background-image: url(:/pic/5.png);");
       break;
    }
    }
}

void Board::on_button_clicked()
{
     ifclick =true;
     change();
}
/*
void Board::on_pushButton_clicked(){
     ifclick =true;
}
*/
void Board::disappear(){
     typenum=0;
     button->setStyleSheet("background-image: none;");

     //label->clear();
    //label->setStyleSheet("border:1px solid;");
}

void Board::appear(int type){
    typenum =type;
    switch (typenum-1) {
    case 0:
    {
        //button->setStyleSheet("border-style:dashed ;");
        typenum=1;
       button->setStyleSheet("background-image: url(:/1.png);");
         break;
    }
    case 1:
    {
        button->setStyleSheet("background-image: url(:/2.png);");
        typenum=2;
            //button->setStyleSheet("background-image: url(:/pic/2.png);");
        break;
    }
    case 2:
    {
        button->setStyleSheet("background-image: url(:/3.png);");
        typenum=3;
        // button->setStyleSheet("background-image: url(:/pic/3.png);");
        break;
    }
    case 3:
    {
        button->setStyleSheet("background-image: url(:/4.png);");
        typenum=4;
        //button->setStyleSheet("background-image: url(:/pic/4.png);");
       break;
    }
    case 4:
    {
        button->setStyleSheet("background-image: url(:/5.png);");
        typenum=5;
        //button->setStyleSheet("background-image: url(:/pic/5.png);");
       break;
    }
    case 5:
    {
        button->setStyleSheet("background-image: url(:/6.png);");
        typenum=6;
        //button->setStyleSheet("background-image: url(:/pic/5.png);");
       break;
    }
    }
}

int Board::showtype(){
    return typenum;
}

int Board::showtotaltimes(){
    int times =(int)totaltimes;
    return times;
}
/*
void Board::on_button_clicked()
{
    clicktime++;
    if(clicktime==1){
        checktype1=typenum;
        boardptr =this;
        //change =false;
    }
    else if (clicktime==2){
        checktype2=typenum;
       // if(near(rowlocate,collocate,i,j)){
            appear(checktype1);
            boardptr->appear(checktype2);

           /*
            if(checksame()){
                do{
                 checkrow();
                 checkcol();
                 align();
                add();
                }while(checksame());
            }
            else{
                board[i][j]->appear(checktype2);
                board[rowlocate][collocate]->appear(checktype1);
            }

            change();
            clicktime=0;
            //change =true;
            totaltimes--;
       // }

    }

  //  ifclick =true;
}
*/
