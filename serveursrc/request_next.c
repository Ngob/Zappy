/*
** request_next.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 16:00:47 2011 romain capot
** Last update Thu Jul  7 16:15:06 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"request.h"

int		request_next(t_data * d, int fd)
{
  t_request	*tmp;

  tmp = d->req;
  while (tmp)
    {
      if (tmp->fd == fd)
	{
	  if (tmp->time <= 0 && tmp->active == ACTIVE_ON)
	    {
	      tmp->ptr_func(d, tmp->fd, tmp->fd, tmp->cmd);
	      request_erase(d, tmp);
	      if (request_search_fd(d, fd))
		request_switch(d, fd);
	      return 1;
	    }
	  else
	    return 0;
	}
      tmp = tmp->next;
    }
  return 0;
}
