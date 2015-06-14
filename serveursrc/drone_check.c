/*
** drone_check.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jun 16 13:38:58 2011 romain capot
** Last update Thu Jun 16 14:33:32 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"x.h"

int		drone_check(t_data *d, char *cmd)
{
  t_drone	*tmp;

  tmp = d->drones.drone;
  while (tmp)
    {
      if (tmp->status == ST_EC && !strcmp(tmp->team, cmd))
	return tmp->id;
      tmp = tmp->next;
    }
  return -1;
}
