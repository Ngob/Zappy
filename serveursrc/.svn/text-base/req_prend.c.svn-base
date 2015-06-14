/*
** req_prend.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 13:27:40 2011 romain capot
** Last update Sun Jul 10 13:27:41 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"
#include	"req_prend_func.h"

t_gest_obj	obj_tab[]={
  {"nourriture", &req_prend_nourriture, ID_FOOD},
  {"linemate", &req_prend_linemate, ID_LINEMATE},
  {"deraumere", &req_prend_deraumere, ID_DERAUMERE},
  {"sibur", &req_prend_sibur, ID_SIBUR},
  {"mendiane", &req_prend_mendiane, ID_MENDIANE},
  {"phiras", &req_prend_phiras, ID_PHIRAS},
  {"thystame", &req_prend_thystame, ID_THYSTAME},
  {NULL, NULL, -1},
};

int		req_prend_nourriture(t_data *d, int fd)
{
  t_box		*b;

  if ((b = getBox(d, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y)))
    {
      if (b->food > 0)
	{
	  --b->food;
	  d->fd[fd].food += FOOD_TIME * USEC / d->args->act_time;
	  return SUCCESS;
	}
    }
  return FAIL;
}

int		req_prend_linemate(t_data *d, int fd)
{
  t_box		*b;

  if ((b = getBox(d, d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y)))
    {
      if (b->pierres.linemate > 0)
	{
	  --b->pierres.linemate;
	  ++d->fd[fd].pierres.linemate;
	  return SUCCESS;
	}
    }
  return FAIL;
}

static void	send_cmd(t_data *d, int fd, int obj_id)
{
  int		i;
  char		obj_str[BUFF_SIZE];
  t_pos		pos;

  i = 0;
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
	{
	  sprintf(obj_str, "%d", obj_id);
	  req_pgt(d, fd, i, obj_str);
	  do_pin(d, fd, i, fd);
	  pos.pos_x = d->fd[fd].pos.pos_x;
	  pos.pos_y = d->fd[fd].pos.pos_y;
	  do_bct(d, fd, i, &pos);
	}
      ++i;
    }
}

void		req_prend(t_data *d, int fd, int fd_dir, char *cmd)
{
  int		i;
  char		*arg;

  i = 0;
  if ((arg = catch_arg(cmd, 1)))
    {
      while (obj_tab[i].obj)
	{
	  if (!strcmp(obj_tab[i].obj, arg))
	    {
	      if (obj_tab[i].ptr_func(d, fd) == SUCCESS)
		{
		  printcs(d, fd_dir, "ok\n");
		  send_cmd(d, fd, obj_tab[i].obj_id);
		}
	      else
		printcs(d, fd_dir, "ko\n");
	      return;
	    }
	  ++i;
	}
    }
  printcs(d, fd_dir, "ko\n");
}
