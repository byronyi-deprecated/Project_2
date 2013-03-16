#include "mainwindow.h"

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
    board.fill(Qt::transparent);
    background.load(":\background.bmp");

    gameBoard = new QWidget(this);
    previewWin = new QWidget(this);
    gameBoard->setGeometry(10, 10, 100, 200);
    previewWin->setGeometry(150, 200, 20, 40);
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
    QPainter painter;

    painter.begin(gameBoard);
    painter.drawPixmap(gameBoard->geometry(), background);
    painter.drawImage(gameBoard->geometry(), board);
}

void MainWindow::nextRound()
{

}
