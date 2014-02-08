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

#include "src/Master.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    Master master = Master();
    master.run();
    return 0;
}

