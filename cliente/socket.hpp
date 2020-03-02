#ifndef SOCKET_HPP
#define SOCKET_HPP

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
class Socket{
public:
    Socket();
    int sock;
    int crearSocket();
    int conectar(int sock, sockaddr_in hint);
    string comunicar(string userInput);
    void closeSocket(int socket);

};

#endif // SOCKET_HPP
