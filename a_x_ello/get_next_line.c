#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

char	*join(char *sol, char *buff)
{
	char *solu;

	solu = ft_strjoin(sol, buff);
	free(sol);
	return (solu);
}

int	find_nl(char *s)
{
	int i;

	i = 0;
    if (s[i] == '\n')
      return (1);
	while (s[i] && s[i] != '\n')
	{
		i++;
		if (s[i] == '\n')
			return (1);
	}
	return (0);
}



char	*lecture(char *buff, int fd)
{
  //printf("cuantas veces\n");
	int lec;
	char *sol;
	if (!buff)
    {
      //printf("ey!");
		buff = ft_calloc(1, 1);
    }
	lec = 1;
	sol = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (lec > 0)
	{
		lec = read(fd, sol, BUFFER_SIZE);
        //printf("--%s--", sol);
		if (lec < 0)
		{
          printf("hola?");
			free(sol);
			return (NULL);
		}
        sol[lec] = '\0';
        //if (lec != 0)
        buff = join(buff, sol);
         // printf("--%s--", buff);
		if (find_nl(sol))
			break ;
	}
    free(sol);
    //printf("--%s--", buff);
	return (buff);
}

char	*the_line(char *buff)
{
	char *sol;
	int i;

	i = 0;
    if (!buff[i])
    {
      printf("uno");
      return (NULL);
    }
	while (buff[i] && buff[i] != '\n')
		i++;
	sol = ft_calloc((i + 2) , sizeof(char));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		sol[i] = buff[i];
		i++;
	}
	if (buff[i] &&  buff[i] == '\n')
    {
      //printf("aqui?");
		sol[i] = buff[i];
    }
	i++;
	sol[i] = '\0';
	return (sol);
}

char	*next_line(char *buff)
{
	int i;
	char *sol;
	int y;

	i = 0;
	y = 0;/*
    if (buff[i] == '\n')
    {
      sol = malloc(sizeof(char) * 3);
      sol[y++] = buff[i];
      sol[y] = '\0';
      free(buff);
      return (sol);
    }*/
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
    {
      free(buff);
      printf("do");
		return (NULL);
    }
    else if(buff[i] == '\n')
      i++;
	sol = ft_calloc(i + 1, sizeof(char));
	while(buff[i])
	{
		sol[y] = buff[i];
		y++;
		i++;
	}
	/*if (buff[i] && buff[i] == '\n')
    {
     // printf("aqui");
		sol[y++] = buff[i];
    }*/
	sol[y] = '\0';
    //printf("--sol: %s--", sol);
	free(buff);
	return (sol);
}

char	*get_next_line(int fd)
{
	static char *buff;
	char *sol;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	sol = malloc(sizeof(char) * 1000);

    buff = lecture(buff, fd);
    //printf("--%s--", buff);
    if (!buff)
    {
      free(buff);
      free(sol);
      return (NULL);
    }
	sol = the_line(buff);
    
    //printf("--buff: %s--", buff);
	buff = next_line(buff);
  
    //printf("--%s--", buff);
    //printf("-%s--", buff);
	return (sol);
}

/*

int main()
  {
    int fd;
    char *s;
	char *s2;
  char *s3;
char *s4 ;
char *s5;
char *s6;
	char *s7;
//	char *s8;
//	char *s9;

    fd = open("multiple_nlx5", O_RDONLY);
  s = get_next_line(fd);
   printf("%s", s);
  s2 = get_next_line(fd);
  printf("%s", s2);
 s3 = get_next_line(fd);
 printf("%s", s3);

   //y = n_char_fd(fd);
   //printf("%d", y);
 s4 = get_next_line(fd);
 printf("%s", s4);
 s5 = get_next_line(fd);
 printf("%s", s5);

s6 = get_next_line(fd);
 s7 = get_next_line(fd);
 //s8 = get_next_line(fd);
 //s9 = get_next_line(fd);

 printf("%s", s6);
 printf("%s", s7);
 //printf("%s", s8);
 //printf("%s", s9);
  //system("leaks a.out");
  return (0);
  }*/
