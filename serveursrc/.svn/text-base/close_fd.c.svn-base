/*
** close_fd.c for  in /home/capot_r//public/irc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Tue Apr 19 15:43:23 2011 romain capot
** Last update Thu Jun 30 13:22:47 2011 romain capot
*/

#include	<stdlib.h>
#include	<string.h>
#include	"zappy.h"
#include	"x.h"

void		close_fd(t_data * d)
{
  int		i;

  i = 0;
  while (i < d->maxfd)
    {
      if (d->fd[i].type == FD_CLT)
	{
	  _X((void *)-1, (void *)close(i), "Close");
	}
      else if (d->fd[i].type == FD_SERV)
	_X((void *)-1, (void *)close(i), "Close");
      ++i;
    }
  free(d->fd);
}
