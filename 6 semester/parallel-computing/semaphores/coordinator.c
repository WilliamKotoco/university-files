#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10

sem_t arrive[N];
sem_t continuee[N];
sem_t mutex_print;

sem_t synch; /// semaphore to guarantee that every thread left the barrier
int arrived_barrier = 0;
void process(void *id) {
  int i = *(int *)id;

  while (1) {

    sem_post(&arrive[i]);

    sem_wait(&mutex_print);

    printf("\n Thread %d arrived the barrier \n", i);
    sem_post(&mutex_print);

    sem_wait(&continuee[i]);

    sem_wait(&mutex_print);
    printf("\n Thread %d left the barrier \n", i);
    sem_post(&mutex_print);
  }
}

void coordinator() {
  while (1) {

    for (int i = 0; i < N; i++) {

     sem_wait(&arrive[i]);
    arrived_barrier++;
    }
    
    if (arrived_barrier != N)
      exit(0);
    printf("\n Passed the barrier %d times!", arrived_barrier);
    arrived_barrier = 0;
    sem_post(&mutex_print);

    for (int i = 0; i < N; i++)
      sem_post(&continuee[i]);
  }
}
int main(int argc, char *argv[]) {
  sem_init(&mutex_print, 0, 1);

  pthread_t processes[N];
  pthread_t coordinator_t;

  for (int i = 0; i < N; i++) {
    sem_init(&arrive[i], 0, 0);
    sem_init(&continuee[i], 0, 0);
  }

  pthread_create(&coordinator_t, NULL, (void *)coordinator, NULL);
  for (int i = 0; i < N; i++) {
    int *id = (int *)malloc(sizeof(int));
    *id = i;
    pthread_create(&processes[i], NULL, (void *)process, id);
  }

  for (int i = 0; i < N; i++) {
    pthread_join(processes[i], NULL);
  }
  pthread_join(coordinator_t, NULL);

  return 0;
}
