/*
** eparpille_stone.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 19:36:21 2011 romain capot
** Last update Sun Jul 10 19:36:22 2011 romain capot
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"x.h"

t_assign_stone		tab_assign[] = {
  {LINEMATE, add_linemate},
  {DERAUMERE, add_deraumere},
  {SIBUR, add_sibur},
  {MENDIANE, add_mendiane},
  {PHIRAS, add_phiras},
  {THYSTAME, add_thystame},
  {NULL, NULL}
};

static void	assign_new_pos(t_data *d, int pos, char *name)
{
  int		i;

  i = 0;
  while (tab_assign[i].name)
    {
      if (tab_assign[i].name && strcmp(tab_assign[i].name, name) == 0)
	{
	  tab_assign[i].ptr(d, pos);
	  return ;
	}
      ++i;
    }
}

static int	rand_new_stone_pos(t_data *d, int pos, int val, char *name)

{
  int		i;
  int		rand;
  int		old_val = val;

  i = 0;
  while (i < val)
    {
      rand = pos - 1;
      if (pos != 1)
	while (rand + 1 == pos)
	  rand = rand_a_b((d->args->sizeY * d->args->sizeX) - 1, 0);
      else
	rand = rand_a_b((d->args->sizeY * d->args->sizeX) - 1, 0);
      assign_new_pos(d, pos, name);
      val--;
    }
  return (old_val);
}

void		eparpille_stone(t_data *d, int x, int y)
{
  t_box		*box;

  box = getBox(d, x, y);
  x++;
  y++;
  box->pierres.linemate -= rand_new_stone_pos(d, x * y,
					      box->pierres.linemate, LINEMATE);
  box->pierres.deraumere -= rand_new_stone_pos(d, x * y,
					       box->pierres.deraumere, DERAUMERE);
  box->pierres.sibur -= rand_new_stone_pos(d, x * y,
					   box->pierres.sibur, SIBUR);
  box->pierres.mendiane -= rand_new_stone_pos(d, x * y,
					      box->pierres.mendiane, MENDIANE);
  box->pierres.phiras -= rand_new_stone_pos(d, x * y,
					    box->pierres.phiras, PHIRAS);
  box->pierres.thystame -= rand_new_stone_pos(d, x * y,
					      box->pierres.thystame, THYSTAME);
}

void		add_thystame(t_data *d, int pos)
{
  d->map[pos].pierres.thystame += 1;
}

