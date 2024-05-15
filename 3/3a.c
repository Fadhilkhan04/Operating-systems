#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

int main()
{
  char dir_name[30];
  DIR *dir_ptr;
  struct dirent *read_dir;

  printf("enter the directory name:");
  scanf("%30s", dir_name);

  dir_ptr = opendir(dir_name);

  if (dir_ptr == NULL)
  {
    perror("error opening ");
    return 1;
  }
  while ((read_dir = readdir(dir_ptr)) != NULL)
  {
    if (read_dir->d_type == DT_REG)
    {
      printf("file:%s", read_dir->d_name);
    }
    else if (read_dir->d_type == DT_DIR)
    {
      printf("DIR:%s", read_dir->d_name);
    }
  }
  if (closedir(dir_ptr) == -1)
  {
    perror("error closing the direcctory");
    return 1;
  }
  return 0;
}