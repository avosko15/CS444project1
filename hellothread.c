#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define THREAD_1 "thread 1: "
#define THREAD_2 "thread 2: "

void* run(void* arg) {
    int iteration = 0;
    const char* string_to_print = (const char*) arg;

    while (iteration < 5) {
        printf("%s%d\n", string_to_print, iteration);
        iteration++;
    }

    return NULL;
}

int main() {
    printf("Launching threads\n");
    pthread_t t1, t2;

    pthread_create(&t1, NULL, run, THREAD_1);
    pthread_create(&t2, NULL, run, THREAD_2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Threads complete!\n");
}
