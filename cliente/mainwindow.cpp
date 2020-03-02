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
    socket.closeSocket(socket.sock);
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString desde = ui->textEdit->toPlainText();
    QString hasta = ui->textEdit_2->toPlainText();

    qDebug()<<"Read Data"<< desde << hasta;
    std::string resultado = "1"+desde.toStdString()+hasta.toStdString();
    socket.crearSocket();
    socket.comunicar(resultado);
    ui->label_2->setText(socket.comunicar(resultado).c_str());
}
