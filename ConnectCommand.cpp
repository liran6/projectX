#include <cstring>
#include "Command.h"
#include "ShuntingYard.h"


int ConnectCommand::execute(vector<string> vec, int i) {
    ShuntingYard shuntingYard;
    auto argsForClient = new arg_struct2;

    argsForClient->ip = vec.at(i + 1);
    argsForClient->port = shuntingYard.expressionEvaluate(vec.at(i + 2))->calculate();

    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    portno = argsForClient->port;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    argsForClient->socket=sockfd;

    server = gethostbyname(argsForClient->ip.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    argsForClient->connectOrNot= true;

    OpenConnection((void*)argsForClient);

    return i+3;
}

void* ConnectCommand::OpenConnection(void *param) {

    /* Now ask for a message from the user, this message
       * will be read by server
    */
        char buffer[256];
        bzero(buffer, 256);
        ssize_t n;
        auto *argsT = (arg_struct2 *) param;
        arg_struct2 argsToConnect;
        argsToConnect.port = argsT->port;
        argsToConnect.ip = argsT->ip;
        argsToConnect.socket = argsT->socket;
        argsToConnect.dataMaps = argsT->dataMaps;
        argsToConnect.connectOrNot = argsT->connectOrNot;
        delete (argsT);

        /* Send message to the server */
        writeToServer(argsToConnect.socket, buffer);
/*        n = write(argsToConnect.socket, buffer, strlen(buffer));

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        printf("%s\n", buffer);*/

        return 0;
}

void ConnectCommand::writeToServer(int sock, char buffer[256]){
    ssize_t n;
    int socket = sock;
    n = write(socket, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    printf("%s\n", buffer);
}