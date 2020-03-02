#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtDebug>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    socket->closeSocket(socket->sock);
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString desde = ui->textEdit->toPlainText();
    QString hasta = ui->textEdit_2->toPlainText();
    ui->label_2->setText("");
    qDebug()<<"Read Data"<< desde << hasta;
    std::string result = "1"+desde.toStdString()+hasta.toStdString();

    std::string resultado = "La ruta desde "+ desde.toStdString() + " hasta " + hasta.toStdString() + " es " + socket->comunicar(result);
    ui->label_2->setText(resultado.c_str());
}
