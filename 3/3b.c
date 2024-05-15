#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

int main()
{
  int pid;
  pid = fork();

  if (pid <= -1)
  {
    printf("error in process creation");
    exit(1);
  }
  if (pid != 0)
  {
    printf("the parent process id is:%d", getpid());
  }
  else
  {
    printf("the child process id is:%d", getpid());
  }
  return 1;
}