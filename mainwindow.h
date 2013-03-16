#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include "lattice.h"
#include "i.h"
#include "j.h"
#include "l.h"
#include "o.h"
#include "s.h"
#include "t.h"
#include "z.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
signals:
    void gameStart();
    void hitGround();
    void gameOver();
private slots:
    void startNewGame();
    void nextRound();
    Lattice* newShape();
private:
    Lattice* base;
    Lattice* currentShape;
    Lattice* nextShape;
    QTimer* timer;
    QPixmap background;
    QImage temp;
    QImage board;
    QRect gameBoard;
    QRect previewWin;
    unsigned int score;
};

#endif // MAINWINDOW_H
