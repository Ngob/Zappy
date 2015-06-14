/*
** drone.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 13:28:21 2011 romain capot
** Last update Sun Jul 10 13:28:21 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"x.h"

void		add_drone(t_data *d, int fd)
{
  t_drone	*new;

  if ((new = malloc(sizeof(*new))))
    {
      new->id = d->drones.id_drone;
      ++d->drones.id_drone;
      new->id_creator = fd;
      new->status = ST_OF;
      new->team = _X(NULL, (void *)strdup(d->fd[fd].team), "Strdup");
      new->food = FOOD_TIME * USEC / d->args->act_time * FOOD_DFL;
      new->lvl = 1;
      new->pos_x = d->fd[fd].pos.pos_x;
      new->pos_y = d->fd[fd].pos.pos_y;
      new->dir = DIR_BOT;
      new->next = d->drones.drone;
      d->drones.drone = new;
    }
}

void		active_drone(t_data *d, int id_drone)
{
  t_drone	*tmp;

  tmp = d->drones.drone;
  while (tmp)
    {
      if (id_drone == tmp->id)
	{
	  tmp->status = ST_EC;
	  return ;
	}
      tmp = tmp->next;
    }
}

int		size_drone(t_data *d)
{
  t_drone	*tmp;
  int		i;

  i = 0;
  tmp = d->drones.drone;
  while (tmp)
    {
      ++i;
      tmp = tmp->next;
    }
  return i;
}

t_drone		*getDrone(t_data *d, int id_drone)
{
  t_drone	*tmp;

  tmp = d->drones.drone;
  while (tmp)
    {
      if (id_drone == tmp->id)
	return tmp;
      tmp = tmp->next;
    }
  return NULL;
}

void		drone_ajust_coord(t_data *d, t_drone *dr)
{
  if (dr->pos_x < 0)
    dr->pos_x = d->args->sizeX - 1;
  else if (dr->pos_x >= d->args->sizeX)
    dr->pos_x = 0;
  if (dr->pos_y < 0)
    dr->pos_y = d->args->sizeY - 1;
  else if (dr->pos_y >= d->args->sizeY)
    dr->pos_y = 0;
}
