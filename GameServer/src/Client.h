/* 
 * File:   Client.h
 * Author: LUCIA Florent
 *
 * Created on February 8, 2014, 10:06 PM
 */

#ifndef CLIENT_H
#define	CLIENT_H

#include "SocketTCP.h"
#include <pthread.h>

class NetworkModule;

class Client {
public:
    Client(int id, int desc, NetworkModule * networkModule);
    Client(const Client& orig);
    virtual ~Client();
 
    void startRecv();
    
    int getId();
    
private:
    int _id;
    SocketTCP _socket;
    pthread_t _threadRecv;
    NetworkModule * _networkModule;
};

void * threadRecv(void * param);

struct clientParam {
    int id;
    NetworkModule * _networkModule;
    SocketTCP * _socketTCP;
};

struct systemProtocole {
    short int id;
    short int type;
    char body[256];
};

#endif	/* CLIENT_H */

