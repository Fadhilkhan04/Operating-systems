#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
  char fn[10], pat[10], temp[200];

  FILE *fp;

  int found = 0;

  printf("enter the file name:");
  scanf("%s", &fn);
  printf("enter the pattern name:");
  scanf("%s", &pat);

  fp = fopen(fn, "r");

  while (fgets(temp, sizeof(temp), fp))
  {
    fgets(temp, 1000, fp);
    if (strstr(temp, pat))
      found = 1;
    printf("pattern found at %s", temp);
  }
  if (!found)
  {
    printf("not found");
  }
  fclose(fp);
}
