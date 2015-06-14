/*
** req_pie.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Tue Jun 21 11:31:14 2011 romain capot
** Last update Tue Jun 21 11:31:20 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"

void		req_pie(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		res[BUFF_SIZE];
  (void)cmd;

  sprintf(res, "pie %d %d %s\n", d->fd[fd].pos.pos_x,
	  d->fd[fd].pos.pos_y, cmd);
  printcs(d, fd_dir, res);
}
