#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, j, no_request, request[20];
  int initial;
  int head_moments;

  printf("enter the no of requets");
  scanf("%d", &no_request);

  printf("enter the requuts:");
  for (i = 0; i < no_request; i++)
  {
    scanf("%d", &request[i]);
  }
  printf("enter the initial head moment:");
  scanf("%d", &initial);

  for (i = 0; i < no_request; i++)
  {
    head_moments += abs(request[i] - initial);
    initial = request[i];
  }
  printf("the total head moments required are:%d", head_moments);

  return 1;
}