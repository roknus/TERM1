/* 
 * File:   Client.cpp
 * Author: LUCIA Florent
 * 
 * Created on February 8, 2014, 10:06 PM
 */

#include "Client.h"

Client::Client(int desc) {
    _socket.setDescriptor(desc);
}
Client::Client(const Client& orig) {
}

Client::~Client() {
}

