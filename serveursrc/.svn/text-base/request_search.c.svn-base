/*
** request_search.h for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Tue Jun  7 16:42:11 2011 romain capot
** Last update Thu Jul  7 16:47:38 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"request.h"

int		request_search_fd(t_data * d, int fd)
{
  t_request	*tmp;

  tmp = d->req;
  while (tmp)
    {
      if (tmp->fd == fd)
	return 1;
      tmp = tmp->next;
    }
  return 0;
}

int		request_search_fd_active(t_data * d, int fd)
{
  t_request	*tmp;

  tmp = d->req;
  while (tmp)
    {
      if (tmp->fd == fd && tmp->active == ACTIVE_ON)
	return 1;
      tmp = tmp->next;
    }
  return 0;
}
