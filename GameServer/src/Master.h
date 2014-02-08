/* 
 * File:   Master.h
 * Author: LUCIA Florent
 *
 * Created on February 8, 2014, 10:27 PM
 */

#ifndef MASTER_H
#define	MASTER_H

#include <iostream>
#include <vector>
#include "Client.h"

class Master {
public:
    Master();
    Master(const Master& orig);
    virtual ~Master();
    
    /*!
     * \todo
     */
    std::vector<Client> getClientList();
    void setClientList(std::vector<Client> list);
    
    void run();
    
    void addClient(Client newClient);
    
private:
    std::vector<Client> _clientList;

};

#endif	/* MASTER_H */

