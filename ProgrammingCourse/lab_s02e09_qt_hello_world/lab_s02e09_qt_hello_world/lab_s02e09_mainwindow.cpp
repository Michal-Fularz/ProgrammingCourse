#include "lab_s02e09_mainwindow.h"
#include "ui_lab_s02e09_mainwindow.h"

lab_s02e09_MainWindow::lab_s02e09_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lab_s02e09_MainWindow)
{
    ui->setupUi(this);
}

lab_s02e09_MainWindow::~lab_s02e09_MainWindow()
{
    delete ui;
}

void lab_s02e09_MainWindow::on_btn_calculate_clicked()
{
    double value_1 =  ui->lineEdit_value_1->text().toDouble();
    double value_2 =  ui->lineEdit_value_2->text().toDouble();

    double result = value_1 + value_2;

    ui->lbl_result->setText(QString::number(result));
}
