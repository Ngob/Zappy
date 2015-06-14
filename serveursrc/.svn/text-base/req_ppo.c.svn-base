/*
** req_ppo.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Tue Jun 21 11:32:02 2011 romain capot
** Last update Tue Jun 21 11:32:14 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"

void		req_ppo(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		res[BUFF_SIZE];

  (void)cmd;
  sprintf(res, "ppo %d %d %d %d\n", fd, d->fd[fd].pos.pos_x,
	  d->fd[fd].pos.pos_y, d->fd[fd].pos.dir);
  printcs(d, fd_dir, res);
}

void		req_ppo_drone(t_data *d, int fd, int fd_dir, char *cmd)
{
  t_drone	*dr;
  char		res[BUFF_SIZE];

  (void)cmd;
  dr = getDrone(d, fd);
  if (dr)
    {
      sprintf(res, "ppo %d %d %d %d\n", fd, dr->pos_x, dr->pos_y, dr->dir);
      printcs(d, fd_dir, res);
    }
}

