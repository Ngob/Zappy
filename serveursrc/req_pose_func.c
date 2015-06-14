/*
** req_pose_func.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun 15 13:17:53 2011 romain capot
** Last update Wed Jun 15 13:25:07 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

int	req_pose_deraumere(t_data *d, int fd)
{
  t_box		*b;

  if ((b = getBox(d, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y)))
    {
      if (d->fd[fd].pierres.deraumere > 0)
	{
	  ++b->pierres.deraumere;
	  --d->fd[fd].pierres.deraumere;
	  return SUCCESS;
	}
    }
  return FAIL;
}

int	req_pose_sibur(t_data *d, int fd)
{
  t_box		*b;

  if ((b = getBox(d, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y)))
    {
      if (d->fd[fd].pierres.sibur > 0)
	{
	  ++b->pierres.sibur;
	  --d->fd[fd].pierres.sibur;
	  return SUCCESS;
	}
    }
  return FAIL;
}

int	req_pose_mendiane(t_data *d, int fd)
{
  t_box		*b;

  if ((b = getBox(d, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y)))
    {
      if (d->fd[fd].pierres.mendiane > 0)
	{
	  ++b->pierres.mendiane;
	  --d->fd[fd].pierres.mendiane;
	  return SUCCESS;
	}
    }
  return FAIL;
}

int	req_pose_phiras(t_data *d, int fd)
{
  t_box		*b;

  if ((b = getBox(d, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y)))
    {
      if (d->fd[fd].pierres.phiras > 0)
	{
	  ++b->pierres.phiras;
	  --d->fd[fd].pierres.phiras;
	  return SUCCESS;
	}
    }
  return FAIL;
}

int	req_pose_thystame(t_data *d, int fd)
{
  t_box		*b;

  if ((b = getBox(d, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y)))
    {
      if (d->fd[fd].pierres.thystame > 0)
	{
	  ++b->pierres.thystame;
	  ++d->fd[fd].pierres.thystame;
	  return SUCCESS;
	}
    }
  return FAIL;
}
