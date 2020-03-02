#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;



/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 *
 * Método principal que crea la ventana de la GUI
 */
int main(int argc, char *argv[]){

    QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();

    return 0;
}



