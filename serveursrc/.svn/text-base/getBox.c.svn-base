/*
** getBox.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 10:11:50 2011 romain capot
** Last update Thu Jul  7 10:11:50 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"x.h"

t_box		*getBox(t_data *d, int x, int y)
{
  int		i;
  int		mody;
  int		modx;

  modx = 0;
  mody = 0;
  i = 0;
  if (x >=  d->args->sizeX || y >= d->args->sizeY || x < 0 || y < 0)
    return (NULL);
  return (&d->map[d->args->sizeY * y + x]);
}
