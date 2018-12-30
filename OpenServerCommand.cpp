//
// Created by liran-baruch on 12/24/18.
//

#include <utility>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <complex>
#include "Command.h"
#include "ShuntingYard.h"

arg_struct argsForServer;

using namespace std;

int OpenServerCommand :: execute(vector<string> vec, int i/*, struct argsForServer* a*/){


    ShuntingYard shuntingYard;
    pthread_t pthrd;

    int port = shuntingYard.expressionEvaluate(vec.at(i + 1))->calculate();
    int hz = shuntingYard.expressionEvaluate(vec.at(i + 2))->calculate();
    argsForServer.arg1 = port;
    argsForServer.arg2 = hz;
    pthread_create(&pthrd, nullptr ,&SocketCreator,(void*) &argsForServer);


    return i+3;
}


void*  SocketCreator(void* args) {
    arg_struct* argsT = (arg_struct*)args;
    int sockfd, newsockfd, portno, clilen;

    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;


    //First call to socket() function

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }


/* Initialize socket structure */

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = argsT->arg1;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);


/* Now bind the host address using bind() call.*/

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }


// Now start listening for the clients, here process will
// * go in sleep mode and will wait for the incoming connection


    listen(sockfd, 5);
    clilen = sizeof(cli_addr);


/* Accept actual connection from the client */

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }


/* If connection is established then start communicating */

    while (true) {
        cout << "opened the socket !!!!!!!!" << endl;

        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Here is the message: %s\n", buffer);


/* Write a response to the client */

        n = write(newsockfd, "I got your message", 18);

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        sleep(1 / argsT->arg2); // optional line.
    }
}

//initialize path array for readThread

/*
int OpenServerCommand :: execute(vector<string> vec, int i) {

    ShuntingYard shuntingYard;
    arg_struct *portAndHz;
    double port = shuntingYard.expressionEvaluate(vec.at(i + 1))->calculate();
    double hz = shuntingYard.expressionEvaluate(vec.at(i + 2))->calculate();
    portAndHz->arg1 = (int) port;
    portAndHz->arg2 = (int) hz;
    pthread_mutex_t *lock;
    pthread_t pthrd;
    //struct argsForServer *argsT = (struct argsForServer*)args;
    */
/* First call to socket() function *//*

    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    */
/* Initialize socket structure *//*

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = portAndHz->arg1;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    */
/* Now bind the host address using bind() call.*//*

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    */
/* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    *//*


    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    */
/* Accept actual connection from the client *//*

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    */
/*pthread_create(&pthrd, nullptr, &SocketCreator, (void *) &argsForServer);*//*

    pthread_create(&pthrd, nullptr, &SocketCreator, nullptr);
    */
/* If connection is established then start communicating *//*


    while (true) {
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Here is the message: %s\n", buffer);

        */
/* Write a response to the client *//*

        n = write(newsockfd, "I got your message", 18);

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        sleep(1 / portAndHz->arg2); // optional line.

        return i + 3;
    }
}
*/



