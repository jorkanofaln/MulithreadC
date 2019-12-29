#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <pthread.h>

void  *print_hello(void *tid) {
	printf("Executing thread:  %d\n",(int)tid);
	pthread_exit(0);
}

int main(int argc, char *argv[]) {
        int nb_threads;
        printf("Insert a number of threads to execute: ");
	scanf("%d", &nb_threads);
	pthread_t threads[nb_threads];
	int status, i;
	for (i=0; i < nb_threads; i++) {
		printf("Main(): creating thread: %d\n",i);
		status = pthread_create(&threads[i], NULL, print_hello, (void *)i);
		if (status != 0) {
			printf("pthread failed with error code: %d\n",status);
			exit(-1);
		}
		pthread_join(threads[i], NULL);
	}
	sleep(1);
	exit(0);
}
