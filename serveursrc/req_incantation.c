/*
** req_incantation.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Mon Jun 20 09:40:59 2011 romain capot
** Last update Sun Jul 10 14:35:36 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"
#include	"elevation.h"
#include	"request.h"

static void	send_plv(t_data *d, int fd, int fd_dir, t_pos *pos)
{
  int		i;
  t_drone	*tmp;

  i = 0;
  tmp = d->drones.drone;
  while (i < d->maxfd && i < d->max + 1)
    {
      if ((d->fd[i].type == FD_CLT && d->fd[i].status == CLT_IA)
	  && (d->fd[i].pos.pos_x == pos->pos_x
	      && d->fd[i].pos.pos_y == pos->pos_y))
	req_plv(d, i, fd_dir, NULL);
      ++i;
    }
  while (tmp)
    {
      if (tmp->lvl == d->fd[fd].lvl
	  && (tmp->pos_x == pos->pos_x && tmp->pos_y == pos->pos_y))
	req_plv_drone(d, i, fd_dir, NULL);
      tmp = tmp->next;
    }
}

static void	send_player(t_data *d, int fd, t_pos *pos)
{
  int		i;
  char		res[BUFF_SIZE];

  i = 0;
  sprintf(res, "niveau actuel : %d\n", d->fd[fd].lvl);
  while (i < d->maxfd && i < d->max + 1)
    {
      if ((d->fd[i].type == FD_CLT && d->fd[i].status == CLT_IA)
	  && (d->fd[i].pos.pos_x == pos->pos_x
	      && d->fd[i].pos.pos_y == pos->pos_y))
	  printcs(d, i, res);
      ++i;
    }
}

static void	send_cmd(t_data *d, int fd, char *res)
{
  int		i;
  t_pos		pos;

  i = 0;
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
	{
	  req_pie(d, fd, i, res);
	  send_plv(d, fd, i, &(d->fd[fd].pos));
	  pos.pos_x = d->fd[fd].pos.pos_x;
	  pos.pos_y = d->fd[fd].pos.pos_y;
	  do_bct(d, fd, i, &pos);
	}
      ++i;
    }
}

void		req_incantation(t_data *d, int fd, int fd_dir, char *cmd)
{
  int		lvl_inc;

  (void)cmd;
  (void)fd_dir;
  lvl_inc = d->fd[fd].lvl + 1;
  if (lvl_inc < 9)
    {
      if (check_elev(d, fd, lvl_inc) == SUCCESS)
	{
	  send_cmd(d, fd, "1");
	  send_player(d, fd, &(d->fd[fd].pos));
	  return ;
	}
    }
  printcs(d, fd, "ko\n");
  send_cmd(d, fd, "0");
}

void		req_incantation_pre(t_data *d, int fd, int fd_dir, char *cmd)
{
  int		i;
  t_cmd		tab;

  i = 0;
  tab.time = 300;
  tab.active = ACTIVE_ON;
  tab.ptr_func = &req_incantation;
  request_add(d, &tab, fd, cmd);
  printcs(d, fd_dir, "elevation en cours\n");
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
	req_pic(d, fd, i, NULL);
      ++i;
    }
}
