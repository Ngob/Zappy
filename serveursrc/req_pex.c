/*
** req_pex.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun  8 15:23:59 2011 romain capot
** Last update Mon Jun 20 16:12:25 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"

void		req_pex(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		res[BUFF_SIZE];

  (void)cmd;
  sprintf(res, "pex %d\n", fd);
  printcs(d, fd_dir, res);
}
