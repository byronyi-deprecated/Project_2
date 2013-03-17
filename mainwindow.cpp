#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    base = new Lattice(10, 20);
    timer = new QTimer(this);
    timer->setInterval(100);

    connect(this, SIGNAL(gameStart()),
            timer, SLOT(start()));
    connect(this, SIGNAL(gameStart()),
            this, SLOT(startNewGame()));

    connect(timer, SIGNAL(timeout()),
            this, SLOT(timeoutAction()));

    connect(this, SIGNAL(hitGround()),
            this, SLOT(nextRound()));

    connect(this, SIGNAL(gameOver()),
            timer, SLOT(stop()));
    connect(this, SIGNAL(gameOver()),
            this, SLOT(stopGame()));

    board = QImage(10, 20, QImage::Format_ARGB32);
    board.fill(Qt::white);
    background.load(":\background.bmp");

    gameBoard = QRect(10, 10, 200, 400);
    previewWin = QRect(240, 80, 100, 180);

    setMinimumSize(360, 420);
    setMaximumSize(360, 420);

    currentShape = 0;
    nextShape = 0;
}

MainWindow::~MainWindow()
{
    if(currentShape)
        delete currentShape;
    if(nextShape)
        delete nextShape;
    delete base;
    delete timer;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(!currentShape)
    {
        if(e->key() == Qt::Key_Up)
            emit gameStart();
        return;
    }

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

void MainWindow::timeoutAction()
{
    if(currentShape->moveDown().isHit(base) ||
            *currentShape == currentShape->moveDown())
        emit hitGround();
    else
        *currentShape = currentShape->moveDown();
    update();
}

void MainWindow::paintEvent(QPaintEvent * /* e */)
{
    temp = board;
    if(currentShape)
        currentShape->paintOnImage(temp);

    QPainter painter(this);
    painter.drawPixmap(gameBoard, background);
    painter.drawImage(gameBoard, temp);

    painter.fillRect(previewWin, QBrush(Qt::white));
}

void MainWindow::startNewGame()
{
    board.fill(Qt::white);
    delete base;
    base = new Lattice(10, 20);

    if(currentShape)
        delete currentShape;
    if(nextShape)
        delete nextShape;
    currentShape = newShape();
    nextShape = newShape();

    update();
}

void MainWindow::nextRound()
{
    *base = *base + *currentShape;
    currentShape->paintOnImage(board);
    delete currentShape;

    currentShape = nextShape;
    nextShape = newShape();

    if(currentShape->isHit(base))
        emit gameOver();
}

void MainWindow::stopGame()
{

}

Lattice* MainWindow::newShape()
{
    Lattice *newShape;
    switch(qrand() % 7){
    case 0:
        newShape = new I(10, 20);
        break;
    case 1:
        newShape = new J(10, 20);
        break;
    case 2:
        newShape = new L(10, 20);
        break;
    case 3:
        newShape = new O(10, 20);
        break;
    case 4:
        newShape = new S(10, 20);
        break;
    case 5:
        newShape = new T(10, 20);
        break;
    case 6:
        newShape = new Z(10, 20);
        break;
    default:
        break;
    }
    return newShape;
}
