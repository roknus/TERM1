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
#include <string.h>
#include <iostream>

#include "src/SocketTCP.h"

using namespace std;

struct systemProtocole {
    short int id;
    short int type;
    char body[256];
};

/*
 * 
 */
int main(int argc, char** argv) {
    cout << endl << "\tGame administration terminal" << endl << endl;;
    cout << "> Game server IP : ";
    cout.flush();
    char ip[256];
    cin >> ip;
    char port[256];
    cout << "> Game server port : ";
    cout.flush();
    cin >> port;
    SocketTCP _sock = SocketTCP();
    if(_sock.connectSocket(ip,atoi(port)) != 0) {
        cout << "Could not establish connection with the game server." << endl;
        exit(0);             
    }
    cout << "Connection established" << endl;
    cout << "> Authentification password : ";
    cout.flush();
    char pass[256];
    cin >> pass;
    
    struct systemProtocole auth;
    auth.id = 0;
    auth.type = 0;
    strcpy(auth.body,pass);
    
    short int size = 5 + strlen(auth.body);
    _sock.sendSocket(&size,sizeof(size));
    _sock.sendSocket(&auth,size);
    
    char command[256] = "";
    struct systemProtocole com;
    int id = 1;
    com.type = 2;
    
    while(strcmp("exit",command) != 0) { 
        cout << "> ";
        cout.flush();
        cin >> command;
        com.id = id;
        strcpy(com.body,command);
        size = 5 + strlen(command);
        
        _sock.sendSocket(&size,sizeof(short int));
        _sock.sendSocket(&com,size); 
    }
    
    return 0;
}

