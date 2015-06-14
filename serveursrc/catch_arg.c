/*
** catch_arg.c for  in /home/capot_r//public/irc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Mon Apr 18 14:23:39 2011 romain capot
** Last update Wed Jun  8 16:03:25 2011 romain capot
*/

#include	<stdio.h>
#include	<string.h>
#include	"x.h"

char		*catch_arg(char *str, int nb_arg)
{
  int		i;
  char		*str_tmp;
  char		*arg;

  str_tmp = X(NULL, (void *)strdup(str), "Strdup");
  i = 1;
  strtok(str_tmp, " ");
  arg = str_tmp;
  if (nb_arg == 0)
    return arg;
  while ((arg = strtok(NULL, " ")))
    {
      if (i == nb_arg)
	return arg;
      ++i;
    }
  return arg;
}
