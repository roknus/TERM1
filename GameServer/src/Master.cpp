/* 
 * File:   Master.cpp
 * Author: LUCIA Florent
 * 
 * Created on February 8, 2014, 10:27 PM
 */

#include "Master.h"

Master::Master() {
    if((_inputDesc = fopen("/dev/pts/1","r+")) == NULL) {
        perror("Console file descriptor open error");
        exit(0);
    }
    fprintf(_inputDesc,"\nType ? for help...\n");
}

Master::Master(const Master& orig) {
}

Master::~Master() {
}

void Master::run() {
    std::cout << "Starting master..." << std::endl;
    _networkModule.run();
    startConsole();
}

void Master::startConsole() {
    /*bool exit = false;
    while(!exit) {
        char command[256] = "";
        fgets(command,23,_inputDesc);
        std::cout << command << std::endl;
    }
     */
}