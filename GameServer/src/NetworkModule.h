/* 
 * File:   NetworkModule.h
 * Author: roknus
 *
 * Created on February 8, 2014, 11:32 PM
 */

#ifndef NETWORKMODULE_H
#define	NETWORKMODULE_H

#define WAITING_QUEUE_LENGTH 10
#define NETWORK_CONFIG_PATH "cfg/Network.config"

#include "Client.h"
#include "SocketTCP.h"
#include <pthread.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

class NetworkModule {
public:
    NetworkModule();
    NetworkModule(const NetworkModule& orig);
    virtual ~NetworkModule();
    
    void recoverPort();
    
    void run();
    
    void removeClient(int id);
    
private:
    SocketTCP _socketTCP;
    int _port;
    pthread_t _idMainThread;
    std::vector<Client *> _clientList;

};

struct mainThreadParam {
    std::vector<Client *> * _clientList;
    SocketTCP * _socketTCP;
    NetworkModule * _networkModule;
};

void * mainThread(void * param);

#endif	/* NETWORKMODULE_H */

