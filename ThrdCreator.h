//
// Created by yuval on 12/27/18.
//

#ifndef PROJECTX_THRDCREATOR_H
#define PROJECTX_THRDCREATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <mutex>


class ThrdCreator {

    int trd;
    pthread_t pthreadT;


public:
    ThrdCreator(void* funcToEx, int argToPort, int argToHz) {
        pthread_t main_and_only_thread;

    }

private:
    int pthread_create(pthread_t * thread,
                       nullptr_t ,
                       void * (openDataEX)(void *),
                       void *arg);


    void closeTheThread() {
        pthread_exit;
    }
};


#endif //PROJECTX_THRDCREATOR_H
