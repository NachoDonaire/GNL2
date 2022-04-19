#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  int fd;
  int lec;
  char *buff;
   fd = open("41_no_nl", O_RDONLY);
   lec = read(fd, buff, 41);
   printf("%s, %d\n", buff, lec);
   lec = read(fd, buff, 41);
   printf("%s\n, %d", buff, lec);

   lec = read(fd, buff, 41);

   printf("%s, %d", buff, lec);
}


