#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int x = 0;
int empty = 10;
int full = 0;

void producer()
{
  --mutex;
  --empty;
  ++full;
  x++;
  printf("\nproducer produces item %d", x);
  ++mutex;
}
void consumer()
{
  --mutex;
  ++empty;
  --full;
  printf("\nconsumer consumes item %d", x);
  x--;
  ++mutex;
}
int main()
{
  int n;

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
      if (mutex == 1 && empty != 0)
      {
        producer();
      }
      else
      {
        printf("buffer is full");
      }
      break;
    case 2:
      if (mutex == 1 && full != 0)
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
      break;
    }
  }
  return 1;
}