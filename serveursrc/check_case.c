/*
** check_case.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 13:26:07 2011 romain capot
** Last update Sun Jul 10 13:26:08 2011 romain capot
*/

#include	<stdio.h>
#include	"check_case.h"

float		case_downleft(t_data *d, int fd, int i)
{
  if (d->fd[fd].pos.pos_x <= d->args->sizeX / 2
      && d->fd[fd].pos.pos_y >= d->args->sizeY / 2)
    {
      if (check_left(d, fd, i) > check_down(d, fd, i))
	return (check_down(d, fd, i));
      else
	return (check_left(d, fd, i));
    }
  else
    return (0);
}

float		case_upleft(t_data *d, int fd, int i)
{
  if (d->fd[fd].pos.pos_x <= d->args->sizeX / 2
      && d->fd[fd].pos.pos_y <= d->args->sizeY / 2)
    {
      if (check_left(d, fd, i) > check_up(d, fd, i))
	return (check_up(d, fd, i));
      else
	return (check_left(d, fd, i));
    }
  else
    return (0);
}

float		case_downright(t_data *d, int fd, int i)
{
  if (d->fd[fd].pos.pos_x >= d->args->sizeX / 2
      && d->fd[fd].pos.pos_y >= d->args->sizeY / 2)
    {
      if (check_down(d, fd, i) > check_right(d, fd, i))
	return (check_right(d, fd, i));
      else
	return (check_down(d, fd, i));
    }
  return (0);
}

float		case_upright(t_data *d, int fd, int i)
{
  if (d->fd[fd].pos.pos_x >= d->args->sizeX / 2
      && d->fd[fd].pos.pos_y <= d->args->sizeY / 2)
    {
      if (check_right(d, fd, i) > check_up(d, fd, i))
	return (check_up(d, fd, i));
      else
	return (check_right(d, fd, i));
    }
  return (0);
}

void		find_case_recep(t_data *d, t_arg_pos *pos, int i, int fd)
{
  float		xs;
  float		ys;
  float		xc;
  float		yc;

  if (pos->x > d->fd[fd].pos.pos_x)
    xc = pos->x - 1;
  else if (pos->x == d->fd[fd].pos.pos_x)
    xc = pos->x;
  else
    xc = pos->x + 1;
  if (pos->y > d->fd[fd].pos.pos_y)
    yc = pos->y - 1;
  else if (pos->y > d->fd[fd].pos.pos_y)
    yc = pos->y + 1;
  else
    yc = pos->y;
  xs = xc - pos->x;
  ys = yc - pos->y;
  d->fd[i].broad->case_recep = 0;
  d->fd[i].broad->case_recep = def_direct(xs, ys, d->fd[i].pos.dir);
}
