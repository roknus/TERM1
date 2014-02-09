/* 
 * File:   NetworkModule.cpp
 * Author: roknus
 * 
 * Created on February 8, 2014, 11:32 PM
 */

#include "NetworkModule.h"
#include "Client.h"

NetworkModule::NetworkModule() {
    std::cout << "Initializing network module..." << std::endl;  
    recoverPort();
    _socketTCP.bindSocket(_port);
    _socketTCP.listenSocket(WAITING_QUEUE_LENGTH);
}

NetworkModule::NetworkModule(const NetworkModule& orig) {
}

NetworkModule::~NetworkModule() {
    while(pthread_cancel(idMainThread) != 0) {
        perror("Main network thread");
    }
    std::cout << "Main network thread terminated" << std::endl;    
}

void NetworkModule::recoverPort() {
    std::fstream f;
    f.open(NETWORK_CONFIG_PATH, std::fstream::in);
    if(!f.is_open()) {
        std::cout << "Couldn't open Network.config file" << std::endl;
        exit(0);
    }
    char port[6];
    f.getline(port,6);
    f.close();
    _port = atoi(port);
}

void NetworkModule::run() {
    std::cout << "Starting network module..." << std::endl;
    std::cout << "\tListening port : " << _port << std::endl;
    
    struct mainThreadParam param;
    param._clientList = &_clientList;
    param._socketTCP = &_socketTCP;
    
    while(pthread_create(&idMainThread,NULL,mainThread,&param) != 0) {
        perror("Thread creation error");
    }
    while(pthread_detach(idMainThread) != 0) {
        perror("Thread detach error");
    }
    std::cout << "Network module enabled !" << std::endl;
}

void * mainThread(void * param) {
    struct mainThreadParam * par = (struct mainThreadParam *)param;
    SocketTCP * _socketTCP = par->_socketTCP;
    std::vector<Client> * _clientList = par->_clientList;
        
    int desc;
    while(true) {
        if((desc = _socketTCP->acceptSocket()) != -1) {
            std::cout << "New client connection..." << std::endl;
            _clientList->push_back(Client(desc));
        }
    }
}