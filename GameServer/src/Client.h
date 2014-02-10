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
    Client(int desc, NetworkModule * networkModule);
    Client(const Client& orig);
    virtual ~Client();
 
    void startRecv();
    
private:
    SocketTCP _socket;
    pthread_t _threadRecv;
    NetworkModule * _networkModule;
};

void * threadRecv(void * param);

struct systemProtocole {
    short int size;
    short int id;
    short int type;
    char * body;
    static const char emptyString = '\0';
};

#endif	/* CLIENT_H */

