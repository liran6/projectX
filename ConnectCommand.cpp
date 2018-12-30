#include <cstring>
#include "Command.h"
#include "ShuntingYard.h"


arg_struct2 argsForClient;

/*ConnectCommand::ConnectCommand() {
    this->argsForConnect;
    this->ip = "";
    this->port = 0;
}*/
int ConnectCommand::execute(vector<string> vec, int i) {
    ShuntingYard shuntingYard;
/*    this->ip = vec.at(i + 1);
    this->port = shuntingYard.expressionEvaluate(vec.at(i + 2))->calculate();*/
    argsForClient.arg1 = vec.at(i + 1);
    argsForClient.arg2 = shuntingYard.expressionEvaluate(vec.at(i + 2))->calculate();
    OpenConnection(&argsForClient);

    return 0;
}

void* ConnectCommand::OpenConnection(void *param) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    void *args = param;
    char buffer[256];
    arg_struct2* argsT = (arg_struct2*)param;

/*    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }*/

    portno= argsT->arg2;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argsT->arg1.c_str());

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* Now ask for a message from the user, this message
       * will be read by server
    */

    bzero(buffer,256);

    /* Send message to the server */
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Now read server response */
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n",buffer);
    return 0;
}



