/*
** req_fork.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun 15 15:42:53 2011 romain capot
** Last update Sun Jul 10 14:02:57 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"
#include	"request.h"

static void	send_cmd(t_data *d, int fd, int id_dr)
{
  int		i;
  char		id_drone[BUFF_SIZE];

  i = 0;
  sprintf(id_drone, "%d", id_dr);
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
	req_enw(d, fd, i, id_drone);
      ++i;
    }
}

static void	send_cmd_eclos(t_data *d, int fd)
{
  int		i;

  i = 0;
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
	req_eht(d, fd, i, NULL);
      ++i;
    }
}

void		req_fork_eclos(t_data *d, int fd, int fd_dir, char *cmd)
{
  (void)fd_dir;
  (void)cmd;
  active_drone(d, fd);
  send_cmd_eclos(d, fd);
}

void		req_fork(t_data *d, int fd, int fd_dir, char *cmd)
{
  t_cmd		tab;

  tab.time = 600;
  tab.ptr_func = &req_fork_eclos;
  tab.active = ACTIVE_ON;
  request_add(d, &tab, d->drones.id_drone, cmd);
  add_drone(d, fd);
  send_cmd(d, fd, d->drones.id_drone - 1);
  printcs(d, fd_dir, "ok\n");
}

void		req_fork_pre(t_data *d, int fd, int fd_dir, char *cmd)
{
  int		i;
  t_cmd		tab;

  (void)fd_dir;
  i = 0;
  tab.time = 42;
  tab.ptr_func = &req_fork;
  request_add(d, &tab, fd, cmd);
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
	req_pfk(d, fd, i, NULL);
      ++i;
    }
}
