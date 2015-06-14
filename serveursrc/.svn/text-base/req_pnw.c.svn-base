/*
** req_pnw.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun  8 14:26:36 2011 romain capot
** Last update Mon Jun 20 16:09:16 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		req_pnw(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		*res;

  (void)cmd;
  res = str_fmt("pnw %d %d %d %d %d %s\n", fd,
		d->fd[fd].pos.pos_x,
		d->fd[fd].pos.pos_y,
		d->fd[fd].pos.dir,
		d->fd[fd].lvl,
		d->fd[fd].team);
  if (res)
    {
      printcs(d, fd_dir, res);
      free(res);
    }
}
