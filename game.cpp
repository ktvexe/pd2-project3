#include "game.h"
#include "board.h"
#include "ui_game.h"
#include <QMouseEvent>



game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
}

game::game(QWidget *parent,result* res) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    mainWindow=parent;
    resWindow=res;
     score =0;
    clicktime =0;
    rowlocate=-1;
    collocate=-1;

    srand((unsigned)time(NULL));

    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
           board[i][j]=new Board(this,i,j);
           board[i][j]->init();
            QObject::connect(board[i][j], SIGNAL(change()), this, SLOT(refresh()));
        }
    }

    ui->label->setText(QString::number(score));
   do{
    checkrow();
    checkcol();
    align();
   add();
   }while(checksame());
    //changetimes=board[0][0]->totaltimes;
    /*
    do{
       // if(changetimes>board[0][0]->showtotaltimes()){
        if(board[0][0]->change)
            do{
                checkrow();
                checkcol();
                align();
                add();
            }while(checksame());
           // changetimes--;
        //}
     }while(true);
    //add();
    */
}

game::~game()
{
    delete ui;
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            delete board[i][j];

        }
    }
}

void game::add(){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if(board[i][j]->showtype()==0){
                board[i][j]->appear((random()%6)+1);
            }
        }
    }
}

void game::refresh(){
           for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if (board[i][j]->ifclick)
                {
                    clicktime++;

                    if(i==rowlocate&&j==collocate){
                        clicktime--;
                    }

                    if(clicktime==1){
                        checktype1=board[i][j]->showtype();
                        rowlocate=i;
                        collocate=j;
                    }
                    else if (clicktime==2){
                        checktype2=board[i][j]->showtype();
                        if(near(rowlocate,collocate,i,j)){
                            board[i][j]->appear(checktype1);
                            board[rowlocate][collocate]->appear(checktype2);
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
                            clicktime=0;
                        }
                        else{
                            clicktime=0;

                        }
                        board[i][j]->ifclick=false;
                        board[rowlocate][collocate]->ifclick=false;
                        rowlocate=-1;
                        collocate=-1;
                    }
                }

                }
            /*
                 if(clicktime ==1){
                     board[rowlocate][collocate]->ifclick=false;
                    clicktime=0;
                }
                */
           }



                for(int j=0;j<9;j++){
                 for(int i=0;i<9;i++){
                     if (board[i][j]->ifclick)
                     {

                         clicktime++;
                         /*
                         if(clicktime==1){
                             checktype1=board[i][j]->showtype();
                             rowlocate=i;
                             collocate=j;
                         }
                         */
                         if(i==rowlocate&&j==collocate){
                             clicktime--;
                         }
                         else if (clicktime==2){
                             checktype2=board[i][j]->showtype();
                             if(near(rowlocate,collocate,i,j)){
                                 board[i][j]->appear(checktype1);
                                 board[rowlocate][collocate]->appear(checktype2);
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
                                 clicktime=0;
                             }
                             else
                                 clicktime=0;
                             board[i][j]->ifclick=false;
                             board[rowlocate][collocate]->ifclick=false;
                             rowlocate=-1;
                             collocate=-1;
                         }
                     }
            }

        ui->label->setText(QString::number(score));

        }

}

void game::align(){
    for(int k =0;k<8;k++){
        for(int j=0;j<9;++j){
            for(int i=8;i>0;--i){
                if (board[i-1][j]->showtype() !=0 && board[i][j]->showtype()==0){
                    board[i][j]->appear(board[i-1][j]->showtype());
                    board[i-1][j]->disappear();
                   // board[i-1][j]->appear(board[i][j]->showlevel(),board[i][j]->showcolor());
                    // board[i][j]->disappear();
                }
            }
        }
    }
}

bool game::checksame(){
    for(int i=0;i<9;i++){
        int same=1;
        for(int j=0;j<8;j++){
            if(board[i][j]->showtype()==board[i][j+1]->showtype()&&board[i][j]->showtype()!=0){
                ++same;
             }
         else{
                if(same>=3){
                   return true;
                }
                else
                    same =1;
          }
        }
        if(same>=3)
            return true;

    }

    for(int j=0;j<9;j++){
        int same=1;
        for(int i=0;i<8;i++){

            if(board[i][j]->showtype()==board[i+1][j]->showtype()&&board[i][j]->showtype()!=0){
                ++same;
             }
             else {
                if(same>=3){
                    return true;
                }
                else
                    same =1;
            }
        }
        if(same>=3)
            return true;
        else
            return false;
    }

}

void game::checkrow()
{
    for(int i=0;i<9;i++){
        int same=1;
        for(int j=0;j<8;j++){
            if(board[i][j]->showtype()==board[i][j+1]->showtype()){
                ++same;
                if(j ==7&&same >=3){
                    score+=same*500;
                    for(int t=same;t>1;--t){
                        board[i][j-t+2]->disappear();
                    }
                    board[i][8]->disappear();
                }
            }
         else{
                if(same>=3){
                    score+=same*500;
                    for(int t=same;t>0;--t){
                        board[i][j-t+1]->disappear();
                    }
                    same=1;
                }
                else
                    same =1;
          }
        }
    }
}

void game::checkcol()
{
    for(int j=0;j<9;j++){
        int same=1;
        for(int i=0;i<8;i++){

            if(board[i][j]->showtype()==board[i+1][j]->showtype()){
                ++same;
                if(i ==7 && same>=3){
                    score+=same*500;
                    for(int t =same;t>1;--t){
                        board[i-t+2][j]->disappear();
                    }
                    board[8][j]->disappear();
                }
            }
             else {
                if(same>=3){
                    score+=same*500;
                    for(int t=same;t>0;--t){
                        board[i-t+1][j]->disappear();

                    }
                    same=1;
                }
                else
                    same =1;
            }
        }
    }

}

bool game::near(int row1,int col1,int row2,int col2){
    if(row1==row2){
        if(col1==col2+1||col1==col2-1){
            return true;
        }
        else
            return false;
    }
    else if(col1==col2){
        if(row1==row2+1||row1==row2-1)
            return true;
        else
            return false;
    }
 }

void game::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
           ui->label->setText(QString::number(8000));
            do{
             checkrow();
             checkcol();
             align();
            add();
            }while(checksame());

}

/*
void game::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if (board[i][j]->ifclick)
                {
                    //board[i][j]->button_clicked();
                    clicktime++;
                    if(clicktime==1){
                        checktype1=board[i][j]->showtype();
                        rowlocate=i;
                        collocate=j;
                    }
                    else if (clicktime==2){
                        checktype2=board[i][j]->showtype();
                        if(near(rowlocate,collocate,i,j)){
                            board[i][j]->appear(checktype1);
                            board[rowlocate][collocate]->appear(checktype2);
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
                            clicktime=0;
                        }
                        else
                            clicktime--;
                    }
                    board[i][j]->ifclick=false;
                    ui->label->setText(QString::number(10000));
                }
                //ui->label->setText(QString::number(8000));
            }
        }
        ui->label->setText(QString::number(10));
    }
}
*/
/*
void game::refresh(){
    do{
     checkrow();
     checkcol();
     align();
    add();
    }while(checksame());
}
*/
