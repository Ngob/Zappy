/*
** check_free_space.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 14:43:56 2011 romain capot
** Last update Thu Jul  7 14:46:44 2011 romain capot
*/

#include	"zappy.h"

int		check_free_space(t_data *d)
{
  int		i;

  i = 4;
  while (i < d->maxfd)
    {
      if (d->fd[i].type == FD_FREE)
	return 1;
      ++i;
    }
  return 0;
}
