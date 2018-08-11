#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "constants.h"
#include "field.h"
#include "images.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void slotActionStart();
private:
    Ui::MainWindow *ui;
    State state;
    Images *pictures;
    Field *field1;
    Field *field2;
};

#endif // MAINWINDOW_H
