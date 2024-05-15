#include <stdio.h>

int main()
{

  int n;
  int flag = 0;
  printf("enter the number:");
  scanf("%d", &n);
  for (int i = 2; i <= n / 2; i++)
  {
    if (n % i == 0)
    {
      flag = 1;
      break;
    }
  }
  if (flag == 1)
  {
    printf("its not  prime");
  }
  else if (flag == 0)
  {
    printf("its a prime");
  }
  else
  {
    printf("nothing");
  }
  return 1;
}