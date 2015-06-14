/*
** drone_erase.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jun 16 14:41:19 2011 romain capot
** Last update Thu Jun 16 14:49:39 2011 romain capot
*/

#include	<stdlib.h>
#include	"zappy.h"

void		drone_erase(t_data *d, int id_drone)
{
  t_drone	*tmp;
  t_drone	*save;

  tmp = d->drones.drone;
  if (tmp)
    {
      if (tmp->id == id_drone)
	{
	  d->drones.drone = tmp->next;
	  free(tmp);
	}
      while (tmp->next)
	{
	  if (tmp->next->id == id_drone)
	    {
	      save = tmp->next;
	      tmp->next = tmp->next->next;
	      if (save)
		free(save);
	      return ;
	    }
	  tmp = tmp->next;
	}
    }
}
