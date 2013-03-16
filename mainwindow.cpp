#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    base = new Lattice(10, 20);
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(this, SIGNAL(gameStart()),
            timer, SLOT(start()));
    connect(this, SIGNAL(gameStart()),
            this, SLOT(nextRound()));
    connect(this, SIGNAL(hitGround()),
            this, SLOT(nextRound()));
    connect(this, SIGNAL(gameOver()),
            timer, SLOT(stop()));

    board = QImage(10, 20, QImage::Format_ARGB32);
    board.fill(Qt::white);
    background.load(":\background.bmp");

    gameBoard = QRect(10, 10, 200, 400);
    previewWin = QRect(250, 200, 80, 120);

    setMinimumSize(360, 420);
    setMaximumSize(360, 420);
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()) {
    case Qt::Key_Up:
        emit gameStart();
        break;
    case Qt::Key_Down:
        if(!currentShape->moveDown().isHit(base))
            *currentShape = currentShape->moveDown();
        break;
    case Qt::Key_Left:
        if(!currentShape->moveLeft().isHit(base))
            *currentShape = currentShape->moveLeft();
        break;
    case Qt::Key_Right:
        if(!currentShape->moveRight().isHit(base))
            *currentShape = currentShape->moveRight();
        break;
    case Qt::Key_Z:
        if(!currentShape->rotate().isHit(base))
            *currentShape = currentShape->rotate();
        break;
    case Qt::Key_X:
        if(!currentShape->rotate().rotate().rotate().isHit(base))
            *currentShape = currentShape->rotate().rotate().rotate();
        break;
    default:
        break;
    }

    update();
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    if(currentShape->moveDown().isHit(base) ||
            *currentShape == currentShape->moveDown())
        emit hitGround();
    else
        *currentShape = currentShape->moveDown();

    update();
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(gameBoard, background);
    painter.drawImage(gameBoard, board);
}

void MainWindow::nextRound()
{

}
