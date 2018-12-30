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

using namespace std;

int OpenServerCommand :: execute(vector<string> vec, int i){

    ShuntingYard shuntingYard;
    pthread_t pthrd;
    int port = shuntingYard.expressionEvaluate(vec.at(i + 1))->calculate();
    int hz = shuntingYard.expressionEvaluate(vec.at(i + 2))->calculate();
    this->argsForServer.arg1 = port;
    this->argsForServer.arg2 = hz;
//    double argf[2] = {port, hz};
//    int iny = pthread_create(&pthrd, nullptr ,SocketCreator,  );





    //pthread_t serverThread(SocketCreator, nullptr_t ,port, hz);

/*    ▪ int pthread_create(pthread_t *thread, const pthread_attr_t * attr,      ^
                         void *(*start_routine)(void*), void * arg);            |
    ▪ Where thread is a pointer to thread id.                                   |   creating a thread
    ▪ attr is a pointer to attributes structure.                                |
    ▪ start_routine is a pointer to the beginning of the thread’s execution.
    ▪ arg is the threads argument.
    ▪ Attr can, and mostly is NULL, while arg can be null but in many cases is not.
▪ start_routine and thread are necessary.
▪ If successful, the function should return zero.*/

    return i+3;
}

void* OpenServerCommand :: SocketCreator(arg_struct argStruct){
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = argStruct.arg1;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating */
    while (true) {

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
        sleep(1/argStruct.arg2); // optional line.
    }

}

