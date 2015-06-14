/*
** req_pfk.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jun 16 10:11:06 2011 romain capot
** Last update Mon Jun 20 16:12:18 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		req_pfk(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		res[1024];

  (void)cmd;
  sprintf(res, "pfk %d\n", fd);
  printcs(d, fd_dir, res);
}
