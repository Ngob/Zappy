/*
** request_count.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jul  6 16:17:02 2011 romain capot
** Last update Wed Jul  6 16:17:41 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"request.h"

int		request_count(t_data * d, int fd)
{
  t_request	*tmp;
  int		nb;

  tmp = d->req;
  nb = 0;
  while (tmp)
    {
      if (tmp->fd == fd)
	++nb;
      tmp = tmp->next;
    }
  return nb;
}
