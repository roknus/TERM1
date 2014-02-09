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

class Client {
public:
    Client(int desc);
    Client(const Client& orig);
    virtual ~Client();
 
    void startRecv();
    
private:
    SocketTCP _socket;
    pthread_t _threadRecv;
};

void * threadRecv(void * param);

#endif	/* CLIENT_H */

