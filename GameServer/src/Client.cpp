/* 
 * File:   Client.cpp
 * Author: LUCIA Florent
 * 
 * Created on February 8, 2014, 10:06 PM
 */

#include "Client.h"
#include "NetworkModule.h"

Client::Client(int desc, NetworkModule * networkModule) {
    _networkModule = networkModule;
    _socket.setDescriptor(desc);
}
Client::Client(const Client& orig) {
}

Client::~Client() {
}

void Client::startRecv() {
    pthread_create(&_threadRecv,NULL,threadRecv,&_socket);
}

void * threadRecv(void * param) {
    SocketTCP * _socket = (SocketTCP *)param;
    short int size;
    _socket->recvSocket(&size,sizeof(short int));
    if(size == 1){
        std::cout << "New Admin" << std::endl;
    }
    
}
