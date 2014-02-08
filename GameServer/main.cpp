/* 
 * File:   main.cpp
 * Author: roknus
 *
 * Created on February 4, 2014, 5:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#include "src/Network/Socket/SocketTCP.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    //int sockR = socket(AF_INET,SOCK_STREAM,0);
    SocketTCP sockE = SocketTCP();
    SocketTCP sockR = SocketTCP();
    sockR.bindSocket(12345);
    cout << "bind success" << endl;
    sockR.listenSocket(10);
    cout << "listen success" << endl;
    /*
    struct sockaddr_in address;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_family = AF_INET;
    address.sin_port = htons((short)12345);
    bind(sockR,(struct sockaddr *)&address,sizeof(address));
    listen(sockR,10);
    
    struct sockaddr_in address2;
    address2.sin_family = AF_INET;
    struct hostent * hst = gethostbyname("localhost");
    address2.sin_addr.s_addr = ((struct in_addr *)(hst->h_addr))->s_addr;
    address2.sin_port = htons((short)12345);
    connect(sockE,(struct sockaddr *)&address2,sizeof(address2));
    */
    //sockE.connectSocket("localhost",12345);
    //socklen_t socklg =sizeof(address);
    int a;
    a = sockR.acceptSocket();
    cout << "accept success" << endl;
    //cout << (a = accept(sockR,(struct sockaddr *)&address,&socklg)) << endl;
    
    //sockE.sendSocket("salut", 6);
    char test[5];
    sockR.recvSocket(a,test,6);
    cout << test << endl;
    
    
    
    
    return 0;
}

