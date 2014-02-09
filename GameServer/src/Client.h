/* 
 * File:   Client.h
 * Author: LUCIA Florent
 *
 * Created on February 8, 2014, 10:06 PM
 */

#ifndef CLIENT_H
#define	CLIENT_H

#include "SocketTCP.h"

class Client {
public:
    Client(int desc);
    Client(const Client& orig);
    virtual ~Client();
    
    SocketTCP getSocket();
    void setSocket();
    
private:
    SocketTCP _socket;
};

#endif	/* CLIENT_H */

