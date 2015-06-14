/*
** request_timeout.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun  8 10:08:17 2011 romain capot
** Last update Sun Jul 10 19:31:32 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"request.h"

int		request_timeout(t_data * d)
{
  t_request	*tmp;
  int		min;

  tmp = d->req;
  min = -1;
  while (tmp)
    {
      if ((tmp->time < min && tmp->active == ACTIVE_ON)
	  || (min == -1 && tmp->active == ACTIVE_ON))
	  min = tmp->time;
      tmp = tmp->next;
    }
  return min;
}
