/* 
 * File:   Master.h
 * Author: LUCIA Florent
 *
 * Created on February 8, 2014, 10:27 PM
 */

#ifndef MASTER_H
#define	MASTER_H

#include "NetworkModule.h"
#include <iostream>

class Master {
public:
    Master();
    Master(const Master& orig);
    virtual ~Master();
    
    void run();
    
private:
    NetworkModule _networkModule;
};

#endif	/* MASTER_H */

