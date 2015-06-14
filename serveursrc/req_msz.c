/*
** req_msz.c for  in /home/capot_r//tek2/c/zappy
**
** Made by romain capot
** Login   <capot_r@epitech.net>
**
** Started on  Wed Jun  8 10:43:45 2011 romain capot
** Last update Thu Jun  9 10:14:53 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"

void		req_msz(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		res[BUFF_SIZE];

  (void)cmd;
  (void)fd;
  sprintf(res, "msz %d %d\n", d->args->sizeX, d->args->sizeY);
  printcs(d, fd_dir, res);
}
