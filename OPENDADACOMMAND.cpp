//
// Created by yuval on 12/26/18.
//

int sockfd = socket(domain, type, protocol)  //create socket cmd

OpenDataServer::OpenDataServer(vector<string> vec, int i) {
    ShuntingYard shuntingYard;
    int portFromVec = vec.at[i + 1];
    int hzFromVec = vec.at[i + 2];
    this->port = shuntingYard.expressionEvaluate(portFromVec)->calculate();
    this->hz = shuntingYard.expressionEvaluate(hzFromVec)->calculate();
}

