#ifndef LAB_S02E09_MAINWINDOW_H
#define LAB_S02E09_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class lab_s02e09_MainWindow;
}

class lab_s02e09_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit lab_s02e09_MainWindow(QWidget *parent = 0);
    ~lab_s02e09_MainWindow();

private slots:
    void on_btn_calculate_clicked();

private:
    Ui::lab_s02e09_MainWindow *ui;
};

#endif // LAB_S02E09_MAINWINDOW_H
