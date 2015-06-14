/*
** req_avance.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 10:14:56 2011 romain capot
** Last update Thu Jul  7 10:14:56 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"req_dir.h"
#include	"req_cmd.h"

t_dir		dir_tab[] = {
  {DIR_BOT, 0, 1, -1},
  {DIR_TOP, 0, -1, -1},
  {DIR_LEFT, -1, 0, -1},
  {DIR_RIGHT, 1, 0, -1},
  {-1, -1, -1, -1}
};

void		ajust_coord(t_data * d, int fd)
{
  if (d->fd[fd].pos.pos_x < 0)
    d->fd[fd].pos.pos_x = d->args->sizeX - 1;
  else if (d->fd[fd].pos.pos_x >= d->args->sizeX)
    d->fd[fd].pos.pos_x = 0;
  if (d->fd[fd].pos.pos_y < 0)
    d->fd[fd].pos.pos_y = d->args->sizeY - 1;
  else if (d->fd[fd].pos.pos_y >= d->args->sizeY)
    d->fd[fd].pos.pos_y = 0;
}

static void	send_cmd(t_data *d, int fd)
{
  int		i;

  i = 0;
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
	req_ppo(d, fd, i, NULL);
      ++i;
    }
}

void		req_avance(t_data *d, int fd, int fd_dir, char *cmd)
{
  int		i;

  i = 0;
  (void)cmd;
  (void)fd_dir;
  while (dir_tab[i].cur_dir != -1)
    {
      if (d->fd[fd].pos.dir == dir_tab[i].cur_dir)
	{
	  d->fd[fd].pos.pos_x += dir_tab[i].diff_x;
	  d->fd[fd].pos.pos_y += dir_tab[i].diff_y;
	  ajust_coord(d, fd);
	  printcs(d, fd_dir, "ok\n");
	  send_cmd(d, fd);
	  return ;
	}
      ++i;
    }
  printcs(d, fd_dir, "ko\n");
}
