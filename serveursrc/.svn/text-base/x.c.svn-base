/*
** x.c for  in /home/capot_r//public/irc/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Apr 21 11:09:46 2011 romain capot
** Last update Thu Apr 21 11:16:53 2011 romain capot
*/

#include <sys/select.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	*X(void *err, void *res, char *str)
{
  if (res == err)
    {
      fprintf(stderr, "Error with %s : %s\n",
	      str, strerror(errno));
      exit(EXIT_FAILURE);
    }
  return (res);
}

void	*_X(void *err, void *res, char *str)
{
  if (res == err)
    fprintf(stderr, "Error with %s : %s\n",
	    str, strerror(errno));
  return (res);
}

void	*xmalloc(int size, char *file, int line)
{
  void	*p;

  if (!(p = malloc(size)))
    {
      fprintf(stderr, "Can't alloc memory() (in %s, line %d) : %s\n",
	      file, line, strerror(errno));
      exit(EXIT_FAILURE);
    }
  memset(p, 0, size);
  return (p);
}
