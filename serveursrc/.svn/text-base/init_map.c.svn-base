/*
** init_map.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 13:29:16 2011 romain capot
** Last update Sun Jul 10 13:29:17 2011 romain capot
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"zappy.h"
#include	"x.h"

int		rand_a_b(int a, int b)
{
  if (a == 0)
    return b;
  else
    return rand() % a + b;
}

void		init_map(t_data *d, t_args *args)
{
  int		i;
  int		max;
  t_box		new;

  i = 0;
  max = args->sizeX * args->sizeY;
  while (i < max)
    {
      new.pierres.linemate = rand_a_b(RDM_LINEMATE, 0);
      new.pierres.deraumere = rand_a_b(RDM_DERAUMERE, 0);
      new.pierres.sibur = rand_a_b(RDM_SIBUR, 0);
      new.pierres.mendiane = rand_a_b(RDM_MENDIANE, 0);
      new.pierres.phiras = rand_a_b(RDM_PHIRAS, 0);
      new.pierres.thystame = rand_a_b(RDM_THYSTAME, 0);
      new.food = rand_a_b(RDM_FOOD, 0);
      d->map[i] = new;
      ++i;
    }
}
