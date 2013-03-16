#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QIamge>
#include "lattice.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
private:

    I *i;
    J *j;
    L *l;
    O *o;
    S *s;
    T *t;
    Z *z;

    Lattice *base;
    Lattice *currectShape;
    QTimer timer;
    QPixmap background;
    QImage board;
    QWidget gameBoard;
    QWidget previewWin;
    unsigned int score;
};

#endif // MAINWINDOW_H
