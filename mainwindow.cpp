#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    base = new Lattice(10, 20);
    board = QImage(10, 20, QImage::Format_RGB32);
    board.fill();
    background.load(":\background.bmp");
    gameBoard.setGeometry(10, 10, 100, 200);
    previewWin.setGeometry(150, 200, 20, 40);
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::keyPressEvent(QKeyEvent *)
{

}

void MainWindow::timerEvent(QTimerEvent *)
{

}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(gameBoard);
    painter.drawPixmap(gameBoard.geometry(),background);
    painter.drawImage(gameBoard.geometry(), board);
}
