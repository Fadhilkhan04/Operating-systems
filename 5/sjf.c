#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, n, j;
  int bt[30], wait[30], turn[30];
  int avg_wait = 0, avg_turn = 0;

  printf("enter the number of process:");
  scanf("%d", &n);

  printf("enter the burst time for the processes:");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &bt[i]);
  }
  // sorting
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (bt[j] > bt[j + 1])
      {
        int temp = bt[j];
        bt[j] = bt[j + 1];
        bt[j + 1] = temp;
      }
    }
  }

  wait[0] = 0;
  for (i = 1; i < n; i++)
  {
    wait[i] = 0;
    for (j = 0; j < i; j++)
    {
      wait[i] += bt[j];
    }
  }
  printf("process id\t\tburst time\t\twaiting time\t\tturnaround time\n");

  for (i = 0; i < n; i++)
  {
    turn[i] = wait[i] + bt[i];
    avg_wait += wait[i];
    avg_turn += turn[i];

    printf("\np[%d]\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wait[i], turn[i]);
  }
  avg_wait = avg_wait / n;
  avg_turn = avg_turn / n;

  printf("the avg waiting time is:%d", avg_wait);
  printf("the avg turn around time is:%d", avg_turn);

  return 1;
}