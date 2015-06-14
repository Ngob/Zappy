/*
** req_expulse.c for 90 in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jun 16 11:19:19 2011 romain capot
** Last update Tue Jun 21 11:27:28 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"
#include	"req_dir.h"
#include	"x.h"

t_exp_dir	dir_tab_exp[]={
  {DIR_BOT, 0, -1, 3},
  {DIR_TOP, 0, 1, 7},
  {DIR_RIGHT, -1, 0, 1},
  {DIR_LEFT, 1, 0, 5},
  {-1, -1, -1, -1},
};

int		do_exp(t_data *d, int fd, int exp, int * fd_i)
{
  int		i;
  int		res;
  char		res_str[BUFF_SIZE];

  i = 0;
  res = FAIL;
  sprintf(res_str, "deplacement %d\n", dir_tab_exp[exp].exp_case);
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_IA)
	{
	  if (d->fd[i].pos.pos_x == d->fd[fd].pos.pos_x &&
	      d->fd[i].pos.pos_y == d->fd[fd].pos.pos_y && i != fd)
	    {
	      d->fd[i].pos.pos_x += dir_tab_exp[exp].diff_x;
	      d->fd[i].pos.pos_y += dir_tab_exp[exp].diff_y;
	      ajust_coord(d, i);
	      add_tab(fd_i, i);
	      printcs(d, i, res_str);
	      res = SUCCESS;
	    }
	}
      ++i;
    }
  return res;
}

int		do_exp_drone(t_data *d, int fd, int exp, int * fd_i)
{
  t_drone	*tmp;
  int		res;

  res = FAIL;
  tmp = d->drones.drone;
  while (tmp)
    {
      if (tmp->pos_x == d->fd[fd].pos.pos_x &&
	  tmp->pos_y == d->fd[fd].pos.pos_y &&
	  tmp->status == ST_EC)
	{
	  tmp->pos_x += dir_tab_exp[exp].diff_x;
	  tmp->pos_y += dir_tab_exp[exp].diff_y;
	  drone_ajust_coord(d, tmp);
	  add_tab_drone(fd_i, tmp->id);
	  res = SUCCESS;
	}
      tmp = tmp->next;
    }
  return res;
}

static void	send_cmd(t_data *d, int fd, int flag)
{
  int		i;

  i = 0;
  while (i < d->maxfd && i < d->max + 1)
    {
      if (flag == SEND_PL)
	{
	  if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
	    req_ppo(d, fd, i, NULL);
	}
      else if (flag == SEND_DR)
	{
	  if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
	    {
	      req_ppo_drone(d, fd, i, NULL);
	    }
	}
      ++i;
    }
}

static void	send_ia(t_data *d, int fd, int *tab_exp, int *tab_exp_drone)
{
  int		i;

  i = 0;
  while (tab_exp[i] != -1)
    {
      send_cmd(d, tab_exp[i], SEND_PL);
      ++i;
    }
  i = 0;
  while (tab_exp_drone[i] != -1)
    {
      send_cmd(d, tab_exp_drone[i], SEND_DR);
      ++i;
    }
  printcs(d, fd, "ok\n");
}

void		req_expulse(t_data *d, int fd, int fd_dir, char *cmd)
{
  int		i;
  int		tab_fd[BUFF_SIZE];
  int		*tab_dr;

  i = 0;
  (void)cmd;
  (void)fd_dir;
  memset(tab_fd, -1, BUFF_SIZE);
  tab_dr = Xmalloc(sizeof(*tab_dr) * (size_drone(d) + 1));
  memset(tab_dr, -1, size_drone(d) + 1);
  while (dir_tab_exp[i].exp_dir != -1)
    {
      if (dir_tab_exp[i].exp_dir == d->fd[fd].pos.dir)
	{
	  if (do_exp(d, fd, i, tab_fd) == SUCCESS ||
	      do_exp_drone(d, fd, i, tab_dr) == SUCCESS)
	    {
	      send_ia(d, fd, tab_fd, tab_dr);
	      return ;
	    }
	}
      ++i;
    }
  free(tab_dr);
  printcs(d, fd_dir, "ko\n");
}
