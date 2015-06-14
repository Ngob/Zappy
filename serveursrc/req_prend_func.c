/*
** req_prend_func.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun 15 10:51:32 2011 romain capot
** Last update Wed Jun 15 11:01:30 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

int	req_prend_deraumere(t_data *d, int fd)
{
  t_box		*b;

  if ((b = getBox(d, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y)))
    {
      if (b->pierres.deraumere > 0)
	{
	  --b->pierres.deraumere;
	  ++d->fd[fd].pierres.deraumere;
	  return SUCCESS;
	}
    }
  return FAIL;
}

int	req_prend_sibur(t_data *d, int fd)
{
  t_box		*b;

  if ((b = getBox(d, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y)))
    {
      if (b->pierres.sibur > 0)
	{
	  --b->pierres.sibur;
	  ++d->fd[fd].pierres.sibur;
	  return SUCCESS;
	}
    }
  return FAIL;
}

int	req_prend_mendiane(t_data *d, int fd)
{
  t_box		*b;

  if ((b = getBox(d, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y)))
    {
      if (b->pierres.mendiane > 0)
	{
	  --b->pierres.mendiane;
	  ++d->fd[fd].pierres.mendiane;
	  return SUCCESS;
	}
    }
  return FAIL;
}

int	req_prend_phiras(t_data *d, int fd)
{
  t_box		*b;

  if ((b = getBox(d, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y)))
    {
      if (b->pierres.phiras > 0)
	{
	  --b->pierres.phiras;
	  ++d->fd[fd].pierres.phiras;
	  return SUCCESS;
	}
    }
  return FAIL;
}

int	req_prend_thystame(t_data *d, int fd)
{
  t_box		*b;

  if ((b = getBox(d, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y)))
    {
      if (b->pierres.thystame > 0)
	{
	  --b->pierres.thystame;
	  ++d->fd[fd].pierres.thystame;
	  return SUCCESS;
	}
    }
  return FAIL;
}
