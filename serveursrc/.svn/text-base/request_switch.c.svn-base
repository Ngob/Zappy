/*
** request_switch.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Tue Jun  7 16:35:41 2011 romain capot
** Last update Thu Jul  7 16:17:08 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"request.h"

void		request_switch(t_data * d, int fd)
{
  t_request	*tmp;

  tmp = d->req;
  while (tmp)
    {
      if (tmp->fd == fd)
	{
	  tmp->active = ACTIVE_ON;
	  return ;
	}
      tmp = tmp->next;
    }
}
