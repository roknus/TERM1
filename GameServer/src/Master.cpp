/* 
 * File:   Master.cpp
 * Author: LUCIA Florent
 * 
 * Created on February 8, 2014, 10:27 PM
 */

#include "Master.h"

Master::Master() {
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
}