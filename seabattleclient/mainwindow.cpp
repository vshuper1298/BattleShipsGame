#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pictures = new Images;
    pictures->load();
    QPainter painter(this);
    painter.drawImage(0, this->menuBar()->geometry().height(), pictures->get("field"));
    field1 = new Field(pictures, 23, 42, 259, 252);
    field2 = new Field(pictures, 358, 43, 260, 252);
    
    field1->redraw();
    field2->redraw();
    
    state = PLACING_SHIPS;
}

MainWindow::~MainWindow()
{
    delete pictures;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, this->menuBar()->geometry().height(), pictures->get("field"));
    painter.drawImage(field1->x(), this->menuBar()->geometry().height()+field1->y(), field1->Image());
    painter.drawImage(field2->x(), this->menuBar()->geometry().height()+field2->y(), field2->Image());
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint position = event->pos();
    position.setY(position.y() - this->menuBar()->geometry().height());
    switch (state)
    {
        case PLACING_SHIPS:
        {
            QPoint point = field1->coordinates(position.x(), position.y());
            if (point.x() == -1)
            {
                return;
            }
            qDebug() << "Ship at" << point.x() << point.y();
            field1->setCell(point.x(), point.y(), INJURED);
            field1->redraw();
            this->update();
            break;
        }
        case MAKING_STEP:
        {
            QPoint point = field2->coordinates(position.x(), position.y());
            if (point.x() == -1)
            {
                return;
            }
            qDebug() << "Going to" << point.x() << point.y();
            field2->setCell(point.x(), point.y(), DOT);
            field2->redraw();
            this->update();
            break;
        }
//        case WAITING_STEP:

//            break;
//        default:
//            break;
    }
}
void MainWindow::slotActionStart()
{

}
