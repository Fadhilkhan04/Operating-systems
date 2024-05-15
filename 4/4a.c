#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("enter only two arguments");
    return 1;
  }
  char source[20], destination[20];
  strcpy(source, argv[1]);
  strcpy(destination, argv[2]);

  char ch;
  FILE *s, *d;

  s = fopen(source, "r");
  d = fopen(destination, "w");

  if (s == NULL || d == NULL)
  {
    printf("cant open");
    return 1;
  }

  while ((ch = fgetc(s)) != EOF)
  {
    fputc(ch, d);
  }

  printf("copied %ssuccsfully %s", source, destination);
  fclose(s);
  fclose(d);

  return 1;
}