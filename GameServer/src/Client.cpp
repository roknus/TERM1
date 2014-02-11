/* 
 * File:   Client.cpp
 * Author: LUCIA Florent
 * 
 * Created on February 8, 2014, 10:06 PM
 */

#include "Client.h"
#include "NetworkModule.h"

Client::Client(int id, int desc, NetworkModule * networkModule) {
    _id = id;
    _networkModule = networkModule;
    _socket.setDescriptor(desc);
}
Client::Client(const Client& orig) {
}

Client::~Client() {
}

void Client::startRecv() {
    //struct clientParam * param = (struct clientParam *)malloc(sizeof(struct clientParam));
    struct clientParam * param = new (struct clientParam);
    param->_networkModule = _networkModule;
    param->_socketTCP = &_socket;
    param->id = _id;
    pthread_create(&_threadRecv,NULL,threadRecv,param);
    pthread_detach(_threadRecv);
}

int Client::getId() { return _id; }

void * threadRecv(void * param) {
    struct clientParam * par = (struct clientParam *)param;
    SocketTCP * _socket = par->_socketTCP;
    NetworkModule * _networkModule = par->_networkModule;
    int id = par->id;
    
    short int size;
    struct systemProtocole auth;
    _socket->recvSocket(&size,sizeof(size));
    _socket->recvSocket(&auth,size);
    struct systemProtocole com;
    int recv;
    while((recv = _socket->recvSocket(&size,sizeof(size))) > 0) {
        _socket->recvSocket(&com,size);
        std::cout << com.body << std::endl;
    }    
    _networkModule->removeClient(id);
    
    delete (struct clientParam *)param;
}
