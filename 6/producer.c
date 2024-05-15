#include <stdio.h>
#include <stdlib.h>

int mutex = 1; // open
int full = 0;
int empty = 10;
int x = 0;

void producer()
{
  --mutex; // closed
  ++full;
  --empty;
  x++;
  printf("producer produces item %d", x);
  ++mutex; // open
}

void consumer()
{
  --mutex; // closed
  --full;
  ++empty;
  printf("consumer consumes item %d", x);
  x--;
  ++mutex; // lock opened
}

// driver code

int main()
{
  int n, i;

  printf("\n1.producer"
         "\n2.consumer"
         "\n3.exit");

  while (1)
  {
    printf("\nenter your choice:");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
      if ((mutex == 1) && (empty != 0))
      {
        producer();
      }
      else
      {
        printf("buffer is full");
      }
      break;
    case 2:
      if ((mutex == 1) && (full != 0))
      {
        consumer();
      }
      else
      {
        printf("buffer is empty");
      }
      break;
    case 3:
      exit(0);
      break;
    default:
      printf("enter a valid choice");
    }
  }
  return 1;
}