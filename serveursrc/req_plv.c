/*
** req_plv.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Tue Jun 21 11:31:48 2011 romain capot
** Last update Tue Jun 21 11:31:49 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"

void		req_plv(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		res[BUFF_SIZE];

  (void)cmd;
  sprintf(res, "plv %d %d\n", fd, d->fd[fd].lvl);
  printcs(d, fd_dir, res);
}

void		req_plv_drone(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		res[BUFF_SIZE];
  t_drone	*tmp;

  (void)cmd;
  tmp = d->drones.drone;
  while (tmp)
    {
      if (tmp->id == fd)
	{
	  sprintf(res, "plv %d %d\n", fd, tmp->lvl);
	  printcs(d, fd_dir, res);
	}
      tmp = tmp->next;
    }
}
