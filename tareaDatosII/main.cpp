#include "mainwindow.h"
#include "Graph.hpp"
#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <QApplication>

int main(int argc, char *argv[])
{
    int listening = socket(AF_INET,SOCK_STREAM,0);

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    if(bind(listening, (sockaddr*)&hint, sizeof(hint)) == -1){
        printf("Error");
        return -2;
    }

    if(listen(listening, SOMAXCONN)){
        printf("Error");
        return -3;
    }

    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    char host[NI_MAXHOST];
    char svc[NI_MAXSERV];

    int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    if(clientSocket == -1){
        printf("Error");
        return -4;
    }

    close(listening);

    memset(host, 0, NI_MAXHOST);
    memset(svc, 0, NI_MAXSERV);

    int result = getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, svc, NI_MAXSERV,0);

    if(result){
        printf("Conetado");
    }else{
        inet_ntop(AF_INET,&client.sin_addr, host, NI_MAXHOST);
        printf("connected on");
    }


    char buf[4096];
    while(true){

        memset(buf,0,4096);

        int bytesRecv = recv(clientSocket,buf,4096,0);
        if(bytesRecv== -1){
            printf("HUbo un error de conección");
            break;
        }
        if(bytesRecv == 0){
            printf("Cliente desconectado");
            break;
        }

        printf("Received");

        send(clientSocket,buf,bytesRecv+1,0);


    }
    close(clientSocket);

    /*Graph* grafo = new Graph();
    grafo->insertarNodo('A');
    grafo->insertarNodo('B');
    grafo->insertarNodo('C');
    grafo->insertarNodo('D');
    grafo->insertarNodo('E');
    grafo->insertarNodo('F');
    grafo->insertarNodo('G');
    grafo->insertarNodo('H');
    grafo->insertarNodo('I');
    grafo->insertarArista(5,'A','B');
    grafo->insertarArista(1,'A','G');
    grafo->insertarArista(2,'B','E');
    grafo->insertarArista(6,'B','C');
    grafo->insertarArista(3,'G','E');
    grafo->insertarArista(10,'G','H');
    grafo->insertarArista(1,'E','F');
    grafo->insertarArista(2,'C','D');
    grafo->insertarArista(3,'C','F');
    grafo->insertarArista(3,'F','H');
    grafo->insertarArista(2,'H','I');
    grafo->insertarArista(1,'H','D');
    grafo->insertarArista(2,'D','I');
    grafo->dijkstra('A', 'I');*/
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}