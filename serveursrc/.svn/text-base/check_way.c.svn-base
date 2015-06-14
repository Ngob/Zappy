/*
** check_way.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 13:27:15 2011 romain capot
** Last update Sun Jul 10 13:27:16 2011 romain capot
*/

#include	<stdio.h>
#include	"check_way.h"

void		check_short_way(t_data *d, int fd, int i)
{
  check_simple_way(d, fd, i);
  check_trans_way(d, fd, i);
  if (d->fd[i].broad->dist_simple > d->fd[i].broad->dist_trans)
    d->fd[i].broad->case_recep = d->fd[i].broad->case_recep_trans;
  else
    d->fd[i].broad->case_recep = d->fd[i].broad->case_recep_simple;
}

void		check_simple_way(t_data *d, int fd, int i)
{
  t_arg_pos	pos;

  d->fd[i].broad->dist_simple = fabsf(count_dist(d->fd[fd].pos.pos_x,
						 d->fd[fd].pos.pos_y,
						 d->fd[i].pos.pos_x,
						 d->fd[i].pos.pos_y));
  pos.x = d->fd[i].pos.pos_x;
  pos.y = d->fd[i].pos.pos_y;
  find_case_recep(d,
		  &pos,
		  i, fd);
  d->fd[i].broad->case_recep_simple = d->fd[i].broad->case_recep;
}

void		check_trans_way(t_data *d, int fd, int i)
{
  if (case_downleft(d, fd, i) > 0)
    d->fd[i].broad->dist_trans = case_downleft(d, fd, i);
  else if (case_upleft(d, fd, i) > 0)
    d->fd[i].broad->dist_trans = case_upleft(d, fd, i);
  else if (case_downright(d, fd, i) > 0)
    d->fd[i].broad->dist_trans = case_downright(d, fd, i);
  else if (case_upright(d, fd, i) > 0)
    d->fd[i].broad->dist_trans = case_upright(d, fd, i);
}
