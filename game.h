#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "board.h"
#include "result.h"

namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    explicit   game(QWidget *parent,result* res) ;
    game(QWidget *parent);
    int score;
    void checkrow();
    void checkcol();
    void align();
    bool checksame();
    bool near(int row1,int col1,int row2,int col2);
    void add();
    ~game();

public slots:
    void refresh();

private:
    Ui::game *ui;
    QWidget * mainWindow;
      int clicktime,checktype1,checktype2,changetimes;
     int rowlocate,collocate;
    result * resWindow;
    Board *board[9][9];
    void mousePressEvent(QMouseEvent *event);
};

#endif // GAME_H
