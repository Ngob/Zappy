/*
** drone_food.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jun 16 14:53:41 2011 romain capot
** Last update Thu Jun 16 15:37:03 2011 romain capot
*/

#include	<stdlib.h>
#include	"zappy.h"
#include	"req_cmd.h"

static void	send_die(t_data *d, int id)
{
  int		i;

  i = 0;
  while (i <= d->max)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
	req_edi(d, id, i, NULL);
      ++i;
    }
}

void		drone_food_dec(t_data *d, int diff_time)
{
  t_drone	*tmp;
  t_drone	*save;

  tmp = d->drones.drone;
  save = NULL;
  while (tmp)
    {
      if (tmp->status == ST_EC)
	{
	  tmp->food -= diff_time;
	  if (tmp->food <= 0)
	    {
	      send_die(d, tmp->id);
	      save = tmp;
	    }
	}
      tmp = tmp->next;
      if (save)
	{
	  free(save);
	  save = NULL;
	}
    }
}

int		drone_timeout(t_data *d)
{
  t_drone	*tmp;
  int		min;

  min = 0;
  tmp = d->drones.drone;
  while (tmp)
    {
      if (tmp->status == ST_EC)
	{
	  if (!min || tmp->food < min)
	      min = tmp->food;
	}
      tmp = tmp->next;
    }
  return min;
}
