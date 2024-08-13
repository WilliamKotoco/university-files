#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 10
sem_t empty;
sem_t full;

sem_t producer_mutex;
sem_t consumer_mutex;
sem_t print_mutex;
int next_slot_production;
int next_slot_consumer;

int total_produced = 100;
int total_consumed = 0;

int buffer[N] = {0};

void print_slots() {

  printf("SLOTS: \n");
  for (int i = 0; i < N; i++)
    printf("%d ", buffer[i]);
  printf("\n \n \n \n \n");
}

void produce() {

  while (1) {

    sem_wait(&empty); // wait for an empty slot
    sem_wait(&producer_mutex);

    if (total_produced == 0)
      break;

    total_produced--;
    buffer[next_slot_production] = 1;
    next_slot_production = (next_slot_production + 1) % (N - 1);

    sem_wait(&print_mutex);
    printf("Produced on slot: %d\nTotal produced: %d\n ", next_slot_production,
           total_produced);
    print_slots();
    sem_post(&print_mutex);

    sem_post(&producer_mutex);
    sem_post(&full);
  }
}

void consume() {

  while (1) {

    sem_wait(&full); // wait for at least one full slot
    sem_wait(&consumer_mutex);

    if (total_consumed == 100)
      break;
    buffer[next_slot_consumer] = 0;
    next_slot_consumer = (next_slot_consumer + 1) % (N - 1);
    total_consumed++;

    sem_wait(&print_mutex);
    printf("Consumed slot: %d\nTotal consumed: %d\n ", next_slot_consumer,
           total_consumed);
    print_slots();
    sem_post(&print_mutex);

    sem_post(&consumer_mutex);
    sem_post(&empty);
  }
}
int main(int argc, char *argv[]) {
  sem_init(&empty, 0, N);
  sem_init(&full, 0, 0);
  sem_init(&producer_mutex, 0, 1);
  sem_init(&consumer_mutex, 0, 1);
  sem_init(&print_mutex, 0, 1);
  pthread_t consumer[N / 2];
  pthread_t producer[N / 2];

  for (int i = 0; i < N / 2; i++) {
    pthread_create(&consumer[i], NULL, (void *)consume, NULL);

    pthread_create(&producer[i], NULL, (void *)produce, NULL);
  }

  for (int i = 0; i < N / 2; i++) {
    pthread_join(consumer[i], NULL);
  }

  for (int i = 0; i < N / 2; i++) {
    pthread_join(producer[i], NULL);
  }

  sem_destroy(&empty);
  sem_destroy(&full);
  sem_destroy(&producer_mutex);
  sem_destroy(&consumer_mutex);
  return 0;
}
