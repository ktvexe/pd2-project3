#ifndef BOARD_H
#define BOARD_H
#include <QObject>
#include <QLabel>
#include <result.h>
#include <QPushButton>

class Board:public QObject
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent, int Row, int Col);
    ~Board();
    void init();
    void disappear();
    void appear(int type);
    int showtype();
    int showtotaltimes();
    bool ifclick=false;
    //static bool change;
    static int totaltimes;
    int num;
private slots:
    void on_button_clicked();
    //void on_pushButton_clicked();

signals:
    void change();

private:
   QLabel *label;
    QPushButton *button;
    static Board* boardptr;
    static int clicktime,checktype1,checktype2;
    int row,col,typenum;
     result* resDialog;
};

#endif // BOARD_H
