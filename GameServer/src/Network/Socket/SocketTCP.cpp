/*
 * File : SocketTCP.cpp
 * Author : LUCIA Florent
 * Version : 0.1
 * Creation date : 7, 2014, 5:13 PM
 */

#include "SocketTCP.h"

SocketTCP::SocketTCP(){
    int sockDesc;
    if((sockDesc = socket(_domain,_sockType,0)) < 0) {
        perror("Socket descriptor creation error");
    } else {
        setDescriptor(sockDesc);
    }
}

SocketTCP::SocketTCP(const SocketTCP& orig) {
}

SocketTCP::~SocketTCP() {
}

void SocketTCP::setDescriptor(int desc){_descriptor = desc;}

int SocketTCP::getDescriptor(){return _descriptor;}

void SocketTCP::bindSocket(int port) {
    _sockAddr.sin_family = _domain;
    _sockAddr.sin_port = htons((short)port);
    _sockAddr.sin_addr.s_addr = INADDR_ANY;
    if(bind(getDescriptor(),(struct sockaddr *)&_sockAddr,sizeof(_sockAddr)) != 0) {
        perror("Bind error");
    }
}

void SocketTCP::listenSocket(int size) {
    if(listen(getDescriptor(), size) != 0) {
        perror("Listen error");
    }
}

int SocketTCP::acceptSocket() {
    int desc;
    socklen_t sockLen = sizeof(_sockAddr);
    if((desc = accept(getDescriptor(),(struct sockaddr *)&_sockAddr,&sockLen)) < 0) {
        perror("Accept error");
    }
    return desc;
}

int SocketTCP::recvSocket(int sock, void * buffer, size_t size) {
    int sizeRecv;
    if((sizeRecv = recv(sock,buffer,size,0)) == 0) {
        std::cout << "Client disconnected" << std::endl;
    } else if(sizeRecv < 0) {
        perror("Recv error");
    }
    return sizeRecv;
}

void SocketTCP::connectSocket(const char* address, int port) {
    struct hostent * hst = gethostbyname((char *)address);
    _sockAddr.sin_addr.s_addr = ((struct in_addr *)(hst->h_addr))->s_addr;    
    _sockAddr.sin_family = _domain;
    _sockAddr.sin_port = htons((short)port);
    
    int con;
    if((con = connect(getDescriptor(),(struct sockaddr *)&_sockAddr,sizeof(_sockAddr))) != 0) {
        perror("Connect error");
    }
}

int SocketTCP::sendSocket(const void * buffer, size_t size) {
    int sizeSent;
    if((sizeSent = send(getDescriptor(), buffer, size, 0)) < 0) {
        perror("Send error");
    }
    return sizeSent;
}