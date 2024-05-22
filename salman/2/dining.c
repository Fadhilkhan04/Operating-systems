#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_CHOPSTICKS 5
#define NUM_PHILOSOPHERS 5

void dine(int n);

pthread_t philosopher[NUM_PHILOSOPHERS];
pthread_mutex_t chopsticks[NUM_CHOPSTICKS];

int main()
{
  int i, status_message;
  void *msg;

  for (i = 1; i <= NUM_CHOPSTICKS; i++)
  {
    status_message = pthread_mutex_init(&chopsticks[i], NULL);
    if (status_message != 0)
    {
      printf("initialization failed");
      exit(0);
    }
  }
  for (i = 1; i <= NUM_CHOPSTICKS; i++)
  {
    status_message = pthread_create(&philosopher[i], NULL, (void *)dine, (int *)i);
    if (status_message != 0)
    {
      printf("creation failed");
      exit(0);
    }
  }
  for (i = 1; i <= NUM_CHOPSTICKS; i++)
  {
    status_message = pthread_join(philosopher[i], &msg);
    if (status_message != 0)
    {
      printf("join failed");
      exit(0);
    }
  }
  for (i = 1; i <= NUM_CHOPSTICKS; i++)
  {
    status_message = pthread_mutex_destroy(&chopsticks[i]);
    if (status_message != 0)
    {
      printf("destroyed");
      exit(0);
    }
  }
  return 1;
}
void dine(int n)
{
  printf("\nphilosopher %d is thinking", n);

  pthread_mutex_lock(&chopsticks[n]);

  pthread_mutex_lock(&chopsticks[(n + 1) % NUM_CHOPSTICKS]);

  printf("\nphilosopher %d is eating", n);
  sleep(3);

  pthread_mutex_unlock(&chopsticks[n]);

  pthread_mutex_unlock(&chopsticks[(n + 1) % NUM_CHOPSTICKS]);

  printf("\nphilosopher %d is finished eating");
}
