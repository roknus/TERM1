/* 
 * File:   main.cpp
 * Author: roknus
 *
 * Created on February 9, 2014, 9:33 PM
 */


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int sock;
    if((sock = socket(AF_INET,SOCK_STREAM,0)) < 0) {
        perror("Socket descriptor creation error");
    }  
    struct hostent * hst = gethostbyname((char *)"localhost");
    sockaddr_in _sockAddr;
    _sockAddr.sin_addr.s_addr = ((struct in_addr *)(hst->h_addr))->s_addr;  
    _sockAddr.sin_family = AF_INET;
    _sockAddr.sin_port = htons((short)12345);
    
    int con;
    if((con = connect(sock,(struct sockaddr *)&_sockAddr,sizeof(_sockAddr))) != 0) {
        perror("Connect error");
    }
    int a = 1;
    send(sock,&a,1,0);
    return 0;
}

