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
#include <cstring>
#include "Command.h"
#include "ShuntingYard.h"

arg_struct1 argsForServer;

using namespace std;

int OpenServerCommand :: execute(vector<string> vec, int i){

    ShuntingYard shuntingYard;
    pthread_t pthrd;
    DataMaps* dataMaps = DataMaps::getInstance();
    dataMaps->initializePaths();


    auto argsForServer = new arg_struct1;

    int port = shuntingYard.expressionEvaluate(vec.at(i + 1))->calculate();
    int hz = shuntingYard.expressionEvaluate(vec.at(i + 2))->calculate();

    argsForServer->arg1 = port;
    argsForServer->arg2 = hz;
    argsForServer->dataMaps = dataMaps;
    argsForServer->connectOrNot = false;
/*    cout << "hhhh" << endl;
    scanf("%d", &gh);*/
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
    //portno = argsT->arg1;
    argsForServer->socket = sockfd;
    portno = argsForServer->arg1;
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

    argsForServer->socket = sockfd;
/* Accept actual connection from the client */

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    argsForServer->socket = newsockfd;
    argsForServer->connectOrNot= true;

    //pthread_create(&pthrd, nullptr ,&SocketCreator,(void*) &argsForServer);
    pthread_create(&pthrd, nullptr ,&OpenServerCommand::readFromServer,(void*) argsForServer);



    return i+3;
}

void *OpenServerCommand::readFromServer(void *args) {

    auto * argsT = (arg_struct1*)args;
    arg_struct1 argsToSocket;
    argsToSocket.arg2 = argsT->arg2;
    argsToSocket.arg1 = argsT->arg1;
    argsToSocket.socket = argsT->socket;
    argsToSocket.dataMaps = argsT->dataMaps->getInstance();
    argsToSocket.connectOrNot = argsT->connectOrNot;

    delete argsT;
    //char buffer[256];
    string buffer;
    char c;
    ssize_t n = 0;
    while (argsToSocket.connectOrNot) {
        do {
            n = read(argsToSocket.socket, &c, 1);
            buffer += c;
            if (n < 0) {
                perror("Eroor reading from socket");
                exit(1);
            }   else if (n == 0)    {
                exit(1);
            }
        } while (c != '\n');
        argsToSocket.dataMaps->setPathToVal(buffer);
        //data.setPathValues(buffer);
        buffer = "";
/*        bzero(buffer, sizeof(buffer));
        n = read(argsToSocket.socket, buffer, sizeof(buffer));

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Here is the message from the buffer: %s\n", buffer);*/
//        argsToSocket.dataMaps->setPathToVal(buffer);
        sleep(1 / argsToSocket.arg2); // optional line?.
    }

/*    while (data.getRunning()) {
        do {
            n = read(params.socket, &c, 1);
            buffer += c;
            if (n < 0) {
                perror("Eroor reading from socket");
                exit(1);
            }   else if (n == 0)    {
                exit(1);
            }
        } while (c != '\n');
        dataMap.setPathValues(buffer);
        buffer = "";*/
    }

/*
void*  SocketCreator(void* args) {
    auto * argsT = (arg_struct*)args;
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


/* Initialize socket structure

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = argsT->arg1;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);


/* Now bind the host address using bind() call.

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }


// Now start listening for the clients, here process will
// * go in sleep mode and will wait for the incoming connection


    listen(sockfd, 5);
    clilen = sizeof(cli_addr);


/* Accept actual connection from the client

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    bool ifConnection = true;

/* If connection is established then start communicating

    while (ifConnection) {
        cout << "opened the socket !!!!!!!!" << endl;

        bzero(buffer, 256);
        n = read(newsockfd, buffer, sizeof(buffer)-1);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Here is the message: %s\n", buffer);


/* Write a response to the client

        //n = write(newsockfd, "I got your message", strlen(buffer));

       // if (n < 0) {
        //    perror("ERROR writing to socket");
        //    exit(1);
       // }
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

/* First call to socket() function

    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }


/* Initialize socket structure

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = portAndHz->arg1;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);


/* Now bind the host address using bind() call.

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

/* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection



    listen(sockfd, 5);
    clilen = sizeof(cli_addr);


/* Accept actual connection from the client

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

/*pthread_create(&pthrd, nullptr, &SocketCreator, (void *) &argsForServer);

    pthread_create(&pthrd, nullptr, &SocketCreator, nullptr);

/* If connection is established then start communicating


    while (true) {
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Here is the message: %s\n", buffer);


/* Write a response to the client

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



