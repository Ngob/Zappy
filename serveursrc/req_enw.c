/*
** req_enw.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun  8 17:13:49 2011 romain capot
** Last update Tue Jun 21 11:26:46 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		req_enw(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		res[BUFF_SIZE];

  if (cmd)
    {
      sprintf(res, "enw %s %d %d %d\n", cmd, fd,
	      d->fd[fd].pos.pos_x, d->fd[fd].pos.pos_y);
      printcs(d, fd_dir, res);
    }
}
