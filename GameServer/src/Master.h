/* 
 * File:   Master.h
 * Author: LUCIA Florent
 *
 * Created on February 8, 2014, 10:27 PM
 */

#ifndef MASTER_H
#define	MASTER_H

#include "NetworkModule.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

class Master {
public:
    Master();
    Master(const Master& orig);
    virtual ~Master();
    
    void run();
    
    void startConsole();
    
private:
    NetworkModule _networkModule;
    FILE * _inputDesc;
};

#endif	/* MASTER_H */

