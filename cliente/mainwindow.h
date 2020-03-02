#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include "socket.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class
 * Clase que controla el lado del cliente brindando una interfaz y creando el socket para la conexión
 */
class MainWindow : public QMainWindow{
    Q_OBJECT


public:
    /**
     * @brief MainWindow
     * @param parent
     * Método encargaro de crear la GUI
     */
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
    /**
     * @brief socket
     * Variable de tipo socket con la cual el cliente puede conectarse con el servidor
     */
    Socket* socket = new Socket();


private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

