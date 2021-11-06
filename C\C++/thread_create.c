#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

int n = 100;
void *thread_func(void * unused){}

uint64_t time_in_microsec(){
    struct timeval t;
    gettimeofday(&t, NULL);
    return ((uint64_t)t.tv_sec * 1000000 + (uint64_t)t.tv_usec);
}


int main(int argc,char ** argv){
    int64_t start;
    pthread_t t[n];
    uint64_t start_time, end_time;

    start_time = time_in_microsec();
    for (int i = 0; i < n; i++){
        pthread_create(&t[i], NULL, thread_func, NULL);
    }
    end_time = time_in_microsec();

    printf("%ld\n", end_time-start_time);
    return 0;
}