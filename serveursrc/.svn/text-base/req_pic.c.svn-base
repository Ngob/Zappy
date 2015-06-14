/*
** req_pic.c for  in /home/capot_r//tek2/c/zappy/serveursrc
**
** Made by romain capot
** Login   <capot_r@epitech.net>
**
** Started on  Tue Jun 21 11:30:58 2011 romain capot
** Last update Sun Jul 10 14:38:02 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"

void		req_pic(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		res[BUFF_SIZE];
  int		i;

  i = 0;
  (void)cmd;
  sprintf(res, "pic %d %d %d", d->fd[fd].pos.pos_x,
	  d->fd[fd].pos.pos_y, d->fd[fd].lvl);
  while (i < d->maxfd && i < d->max + 1)
    {
      if ((d->fd[i].pos.pos_x == d->fd[fd].pos.pos_x)
	  && (d->fd[i].pos.pos_y == d->fd[fd].pos.pos_y))
	sprintf(res, "%s %d", res, i);
      ++i;
    }
  sprintf(res, "%s\n", res);
  printcs(d, fd_dir, res);
}
