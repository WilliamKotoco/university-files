#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10 // num readers
#define W 3  /// num writers

int writing_pos = 0;
int nr = 0;
int nw = 0;
int buffer[10] = {0};
sem_t mutex;
sem_t read_write;
sem_t print_mutex;

void reader() {
  while (1) {
    sem_wait(&mutex);
    nr++;

    if (nr == 1)
      sem_wait(&read_write);

    sem_post(&mutex);

    sem_wait(&print_mutex);
    printf("\n Read %d \n", buffer[rand() % 10]);
    sem_post(&print_mutex);

    sem_wait(&mutex);
    nr--;

    if (nr == 0) /// if it is the last writer..
      sem_post(&read_write);

    sem_post(&mutex);
  }
}

void writer() {
  while (1) {
    sem_wait(&read_write);

    sem_wait(&print_mutex);
    buffer[writing_pos] = 1;
    printf("\n wrote %d on %d\n", buffer[writing_pos], writing_pos);
    writing_pos++;

    if (writing_pos == 9)
      exit(0);
    sem_post(&print_mutex);
    sem_post(&read_write);
  }
}
int main() {

  sem_init(&print_mutex, 0, 1);
  sem_init(&mutex, 0, 1);

  /// starts available for writing or reading
  sem_init(&read_write, 0, 1);

  pthread_t readers[N];
  pthread_t writers[W];

  for (int i = 0; i < N; i++) {
    pthread_create(&readers[i], NULL, (void *)reader, NULL);
  }

  for (int i = 0; i < W; i++) {
    pthread_create(&writers[i], NULL, (void *)writer, NULL);
  }

  for (int i = 0; i < N; i++) {
      pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < W; i++) {
      pthread_join(writers[i], NULL);
    }
}
