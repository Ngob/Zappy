/*
** check_direction.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 13:26:53 2011 romain capot
** Last update Sun Jul 10 13:26:53 2011 romain capot
*/

#include	<stdio.h>
#include	"check_direction.h"

float		check_down(t_data *d, int fd, int i)
{
  float		dist_down;
  t_arg_pos	pos;

  dist_down = fabsf(count_dist(d->fd[fd].pos.pos_x,
			       d->fd[fd].pos.pos_y,
			       d->fd[i].pos.pos_x,
			       d->fd[i].pos.pos_y + d->args->sizeY));
  pos.x = d->fd[i].pos.pos_x;
  pos.y = d->fd[i].pos.pos_y + d->args->sizeY;
  find_case_recep(d,
		  &pos,
		  i, fd);
  d->fd[i].broad->case_recep_trans = d->fd[i].broad->case_recep;
  return (dist_down);
}

float		check_up(t_data *d, int fd, int i)
{
  float		dist_up;
  t_arg_pos	pos;

  dist_up = fabsf(count_dist(d->fd[fd].pos.pos_x,
			     d->fd[fd].pos.pos_y,
			     d->fd[i].pos.pos_x,
			     d->fd[i].pos.pos_y - d->args->sizeY));
  pos.x = d->fd[i].pos.pos_x;
  pos.y = d->fd[i].pos.pos_y - d->args->sizeY;
  find_case_recep(d,
		  &pos,
		  i, fd);
  d->fd[i].broad->case_recep_trans = d->fd[i].broad->case_recep;
  return (dist_up);
}

float		check_right(t_data *d, int fd, int i)
{
  float		dist_right;
  t_arg_pos	pos;

  dist_right = fabsf(count_dist(d->fd[fd].pos.pos_x,
				d->fd[fd].pos.pos_y,
				d->fd[i].pos.pos_x + d->args->sizeX,
				d->fd[i].pos.pos_y));
  pos.x = d->fd[i].pos.pos_x + d->args->sizeX;
  pos.y = d->fd[i].pos.pos_y;
  find_case_recep(d,
		  &pos,
		  i, fd);
  d->fd[i].broad->case_recep_trans = d->fd[i].broad->case_recep;
  return (dist_right);
}

float		check_left(t_data *d, int fd, int i)
{
  float		dist_left;
  t_arg_pos	pos;

  dist_left = fabsf(count_dist(d->fd[fd].pos.pos_x,
			       d->fd[fd].pos.pos_y,
			       d->fd[i].pos.pos_x - d->args->sizeX,
			       d->fd[i].pos.pos_y));
  pos.x = d->fd[i].pos.pos_x - d->args->sizeX;
  pos.y = d->fd[i].pos.pos_y;
  find_case_recep(d,
		  &pos,
		  i, fd);
  d->fd[i].broad->case_recep_trans = d->fd[i].broad->case_recep;
  return (dist_left);
}

float		check_dist(float xdep, float ydep, float xarr, float yarr)
{
  if (xdep == xarr)
    return (yarr - ydep);
  else if (ydep == yarr)
    return (xarr - xdep);
  return (0);
}
