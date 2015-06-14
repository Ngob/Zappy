/*
** request.c for  in /home/capot_r//tek2/c/zappy
**
** Made by romain capot
** Login   <capot_r@epitech.net>
**
** Started on  Thu May 19 10:31:24 2011 romain capot
** Last update Sun Jul 10 19:23:49 2011 romain capot
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"zappy.h"
#include	"request.h"
#include	"graphic_info.h"
#include	"x.h"

void		request_add(t_data *d, t_cmd *tab, int fd, char *cmd)
{
  t_request	*new;
  t_request	*tmp;

  tmp = d->req;
  if ((new = malloc(sizeof(*new))) != NULL)
    {
      new->time = tab->time * USEC / d->args->act_time;
      new->fd = fd;
      new->cmd = _X(NULL, (void *)strdup(cmd), "Strdup");
      new->ptr_func = tab->ptr_func;
      request_active(d, fd, new, tab->active);
      new->next = NULL;
      if (!tmp)
	d->req = new;
      else
	{
	  while (tmp->next)
	    tmp = tmp->next;
	  tmp->next = new;
	}
    }
}

int		request_size(t_data *d)
{
  t_request	*tmp;
  int		i;

  i = 0;
  tmp = d->req;
  while (tmp)
    {
      ++i;
      tmp = tmp->next;
    }
  return i;
}

void		request_check(t_data *d)
{
  t_request	*tmp;
  int		fd;

  tmp = d->req;
  while (tmp)
    {
      if (tmp->time <= 0 && tmp->active == ACTIVE_ON)
	{
	  fd = tmp->fd;
	  tmp->ptr_func(d, tmp->fd, tmp->fd, tmp->cmd);
	  request_erase(d, tmp);
	  if (request_search_fd(d, fd))
	    {
	      while (request_next(d, fd))
		{
		}
	      if (!request_search_fd_active(d, fd))
		request_switch(d, fd);
	    }
	}
      tmp = tmp->next;
    }
}

void		request_erase(t_data *d, t_request *erase)
{
  t_request	*tmp;
  t_request	*save;

  tmp = d->req;
  if (tmp && erase == tmp)
    {
      d->req = tmp->next;
      free(tmp);
    }
  else if (tmp)
    {
      while (tmp->next && tmp->next != erase)
	tmp = tmp->next;
      save = tmp->next;
      if (tmp->next)
	tmp->next = tmp->next->next;
      free(save);
    }
}

void		request_dec(t_data *d, int time_dec)
{
  t_request	*tmp;

  tmp = d->req;
  while (tmp)
    {
      if (tmp->active == ACTIVE_ON)
	tmp->time -= time_dec;
      tmp = tmp->next;
    }
}
