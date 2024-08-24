#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10 // num readers
#define W 3  /// num writers

int writing_pos = 0;
int nr = 0;
int nw = 0;
int dr = 0;
int dw = 0;
int buffer[100] = {0};
sem_t mutex;
sem_t writer_sem;
sem_t reader_sem;

sem_t print_mutex;

void reader() {
  while (1) {
    sem_wait(&mutex);
    if (nw > 0) /// there are writers, cannot read
    {
      dr++;
      sem_post(&mutex);
      sem_wait(&reader_sem);
    }

    nr++;

    /// signal
    if (nw == 0 && dr > 0) {
      dr--;
      sem_post(&reader_sem);
    } else if (nr == 0 && nw == 0 && dw > 0) {
      dw--;
      sem_post(&writer_sem);
    } else {
      sem_post(&mutex);
    }

    /// end signal

    sem_wait(&print_mutex);
    printf("\n read %d \n", buffer[rand() % 100]);
    sem_post(&print_mutex);

    sem_wait(&mutex);
    nr--;
    /// signal
    if (nw == 0 && dr > 0) {
      dr--;
      sem_post(&reader_sem);
    } else if (nr == 0 && nw == 0 && dw > 0) {
      dw--;
      sem_post(&writer_sem);
    } else {
      sem_post(&mutex);
    }
    /// end signal
  }
}

void writer() {
  while (1) {
    sem_wait(&mutex);
    if (nr > 0 && nw > 0) {
      dw++;
      sem_post(&mutex);
      sem_wait(&writer_sem);
    }

    nw++;
    /// signal
    if (nw == 0 && dr > 0) {
      dr--;
      sem_post(&reader_sem);
    } else if (nr == 0 && nw == 0 && dw > 0) {
      dw--;
      sem_post(&writer_sem);
    } else {
      sem_post(&mutex);
    }
    /// end signal

    sem_wait(&print_mutex);
    buffer[writing_pos] = 1;
    printf("\n Writing %d on %d", buffer[writing_pos], writing_pos);
    writing_pos++;

    if (writing_pos == 100)
      exit(0);
    sem_post(&print_mutex);

    sem_wait(&mutex);
    nw--;

    /// signal
    if (nw == 0 && dr > 0) {
      dr--;
      sem_post(&reader_sem);
    } else if (nr == 0 && nw == 0 && dw > 0) {
      dw--;
      sem_post(&writer_sem);
    } else {
      sem_post(&mutex);
    }
    /// end signal
  }
}
int main() {

  sem_init(&print_mutex, 0, 1);
  sem_init(&mutex, 0, 1);

  /// starts available for writing or reading
  sem_init(&writer_sem, 0, 1);
  sem_init(&reader_sem, 0, 1);

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
