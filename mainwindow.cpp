#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(ui->red,SIGNAL(valueChanged(int)),ui->widget,SLOT(setColorRed(int)));
//    connect(ui->green,SIGNAL(valueChanged(int)),ui->widget,SLOT(setColorGreen(int)));
//    connect(ui->blue,SIGNAL(valueChanged(int)),ui->widget,SLOT(setColorBlue(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
