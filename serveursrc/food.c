/*
** food.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Mon Jun 13 09:48:37 2011 romain capot
** Last update Mon Jul  4 11:05:07 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

static void	send_die(t_data *d, int fd)
{
  int		i;

  i = 0;
  printcs(d, fd, "mort\n");
}

void		food_dec(t_data *d, int diff)
{
  int		i;

  i = 0;
  while (i <= d->max)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_IA
	  && d->fd[i].team)
	{
	  d->fd[i].food -= diff;
	  if (d->fd[i].food <= 0)
	    {
	      send_die(d, i);
	      del_fd(d, i);
	    }
	}
      ++i;
    }
}

int		food_timeout(t_data *d)
{
  int		i;
  int		min;
  int		init;

  i = 0;
  min = 0;
  init = 0;
  while (i <= d->max)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_IA
	  && d->fd[i].team)
	{
	  if (!init || min > d->fd[i].food)
	    {
	      min = d->fd[i].food;
	      init = 1;
	    }
	}
      ++i;
    }
  return min;
}
