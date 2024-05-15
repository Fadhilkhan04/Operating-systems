#include <stdio.h>

int main()
{
  int a, b, c;
  printf("enter number:");
  scanf("%d", &a);
  printf("enter number:");
  scanf("%d", &b);
  printf("enter number:");
  scanf("%d", &c);

  if (a > b && a > c)
  {
    printf("a is the greatest");
  }
  else if (b > a && b > c)
  {
    printf("b is the greatest");
  }
  else if (c > a && c > b)
  {
    printf("c is the greatest");
  }
  else
  {
    printf("enter properly");
  }

  return 0;
}