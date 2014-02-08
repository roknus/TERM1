#ifndef SOCKETTCP_H
#define SOCKETTCP_H

/*!
 * \file SocketTCP.h
 * \brief TCP Socket class
 * \author LUCIA Florent
 * \version 0.1
 * \date 5, 2014, 2:37
 *
 * Implement a TCP Socket class   
 *
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

/*!
 * \class SocketTCP
 * \brief TCP Socket class
 * 
 * TCP Socket class
 *
 */
class SocketTCP {
public:
   
    /*!
     * \brief Constructor
     *
     * Socket constructor. 
     * Get a descriptor file associated to a TCP socket with 
     *
     */
    SocketTCP();
   
    /*!
     * \brief Constructor with descriptor
     * \param desc Descriptor that will be assigned to the socket
     */
    SocketTCP(int desc);
    
    /*!
     * \brief Copy constructor
     * \param Socket : The socket to copy
     * 
     * Socket copy constructor
     *
     */
    SocketTCP(const SocketTCP& orig);
    
    /*!
     * \brief Destructor
     * 
     * Socket destructor
     * 
     */
    virtual ~SocketTCP();
    
    /*!
     * \bried Descriptor setter
     * \param desc The descriptor assigned to the socket
     */
    void setDescriptor(int desc);
    
    /*!
     * \brief Descriptor getter
     * \return Return the socket descriptor 
     */
    int getDescriptor();
    
    /*!
     * \brief Method that bind the socket to its port
     * \param port Bind the socket to that port
     */
    void bindSocket(int port);
    
    /*!
     * \brief Create the waiting queue of the socket
     * \param size Size of the waiting queue
     */
    void listenSocket(int size);
    
    /*!
     * \brief Accept the next socket trying to connect to this socket
     * \return Return the descriptor associated to the new client descriptor, -1 if an error occurred.
     */
    int acceptSocket();
    
    /*!
     * \brief Method trying to receive information in the socket
     * \return Return the number of bytes received, 0 if the client disconnected, -1 if an error occurred
     * \param sock Socket descriptor we are trying to read
     * \param buffer Buffer we are trying to write the informations
     * \param size Number of bytes we are trying to read
     */
    int recvSocket(int sock, void * buffer, size_t size);
    
    /*!
     * \brief Connect to a distant socket
     * \param address Address we are trying to connect to
     * \param port Port on which the distant socket is listening
     */
    void connectSocket(const char * address, int port);
    
    /*!
     * \brief Send message to a distant socket
     * \return Return the number of bytes that has been sent
     * \param buffer Buffer that has to be send
     * \param size Number of bytes that has to be send
     */
    int sendSocket(const void * buffer, size_t size);
    
    
    /*!
     * \brief Close the socket descriptor
     */
    void closeSocket();
    
private:
    static const int _domain = AF_INET; /*!< Address domain */
    static const int _protocol = PF_INET; /*!< Protocol family */
    static const int _sockType = SOCK_STREAM; /*!< Socket type, DGRAM, STREAM, ... */
    int _descriptor; /*!< Socket descriptor */
    struct sockaddr_in _sockAddr; /*!< Socket sockaddr_in struct */
};

#endif    /* SOCKET_H */