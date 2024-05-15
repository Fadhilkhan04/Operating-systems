#include <stdio.h>

int main()
{
  int i, n;
  int n1 = 0;
  int n2 = 1;
  int temp = n1 + n2;
  printf("enter the number:");
  scanf("%d", &n);
  if (n == 1)
  {
    printf("%d", n1);
  }
  else
  {
    printf("%d", n1);
    printf("%d", n2);
    for (i = 3; i <= n; i++)
    {
      printf("%d", temp);
      n1 = n2;
      n2 = temp;
      temp = n1 + n2;
    }
  }
  return 0;
}