/*
** elevation.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 19:36:26 2011 romain capot
** Last update Sun Jul 10 19:36:26 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"elevation.h"

t_elev		elev[] = {
  {2, 1, {1, 0, 0, 0, 0, 0}},
  {3, 2, {1, 1, 1, 0, 0, 0}},
  {4, 2, {2, 0, 1, 0, 2, 0}},
  {5, 4, {1, 1, 2, 0, 1, 0}},
  {6, 4, {1, 2, 1, 3, 0, 0}},
  {7, 6, {1, 2, 3, 0, 1, 0}},
  {8, 6, {2, 2, 2, 2, 2, 1}},
  {0, 0, {0, 0, 0, 0, 0, 0}},
};

static int	pierres_cmp(t_pierres * p1, t_pierres * p2)
{
  if ((p2->linemate == p1->linemate)
      && (p2->deraumere == p1->deraumere)
      && (p2->sibur == p1->sibur)
      && (p2->mendiane == p1->mendiane)
      && (p2->phiras == p1->phiras)
      && (p2->thystame == p1->thystame))
    return 1;
  return 0;
}

int		check_player(t_data *d, int fd, int x, int y)
{
  int		nb;
  int		i;
  t_drone	*tmp;

  i = 0;
  nb = 0;
  tmp = d->drones.drone;
  while (i < d->maxfd && i < d->max + 1)
    {
      if ((d->fd[i].type == FD_CLT && d->fd[i].status == CLT_IA)
	  && (d->fd[i].lvl == d->fd[fd].lvl)
	  && (d->fd[i].pos.pos_x == x && d->fd[i].pos.pos_y == y))
	++nb;
      ++i;
    }
  while (tmp)
    {
      if (tmp->lvl == d->fd[fd].lvl
	  && tmp->status == ST_EC
	  && (tmp->pos_x == x && tmp->pos_y == y))
	++nb;
      tmp = tmp->next;
    }
  return nb;
}

int		inc_lvl(t_data *d, int fd, int x, int y)
{
  int		nb;
  int		i;
  t_drone	*tmp;

  i = 0;
  nb = 0;
  tmp = d->drones.drone;
  while (i < d->maxfd && i < d->max + 1)
    {
      if ((d->fd[i].type == FD_CLT && d->fd[i].status == CLT_IA)
	  && (d->fd[i].lvl == d->fd[fd].lvl)
	  && (d->fd[i].pos.pos_x == x && d->fd[i].pos.pos_y == y))
	++d->fd[i].lvl;
      ++i;
    }
  while (tmp)
    {
      if (tmp->lvl == d->fd[fd].lvl
	  && tmp->status == ST_EC
	  && (tmp->pos_x == x && tmp->pos_y == y))
	++tmp->lvl;
      tmp = tmp->next;
    }
  return nb;
}

int		check_elev(t_data *d, int fd, int lvl_inc)
{
  t_box		*b;

  b = getBox(d, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y);
  if (pierres_cmp(&(elev[lvl_inc - 2].list_pierres), &(b->pierres)))
    {
      if (check_player(d, fd, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y)
	  == elev[lvl_inc - 2].nb_players)
	{
	  inc_lvl(d, fd, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y);
	  eparpille_stone(d, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_x);
	  set_nb_max_lvl_by_team(d, d->fd[fd].team,
				 get_team_player_by_lvl(d, d->fd[fd].team, MAX_LVL));
	  return SUCCESS;
	}
    }
  return FAIL;
}
