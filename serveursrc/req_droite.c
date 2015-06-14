/*
** req_droite.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Tue Jun  7 10:21:44 2011 romain capot
** Last update Mon Jun 20 10:14:55 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"req_dir.h"
#include	"req_cmd.h"

t_dir		dir_tab_droite[]={
  {DIR_BOT, 0, 0, DIR_LEFT},
  {DIR_LEFT, 0, 0, DIR_TOP},
  {DIR_TOP, 0, 0, DIR_RIGHT},
  {DIR_RIGHT, 0, 0, DIR_BOT},
  {-1, -1, -1, -1}
};

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

void		req_droite(t_data *d, int fd, int fd_dir, char *cmd)
{
  int		i;

  i = 0;
  (void)cmd;
  (void)fd_dir;
  while (dir_tab_droite[i].cur_dir != -1)
    {
      if (dir_tab_droite[i].cur_dir == d->fd[fd].pos.dir)
	{
	  d->fd[fd].pos.dir = dir_tab_droite[i].next_dir;
	  printcs(d, fd_dir, "ok\n");
	  send_cmd(d, fd);
	  return ;
	}
      ++i;
    }
  printcs(d, fd_dir, "ko\n");
}
