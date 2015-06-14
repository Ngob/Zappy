/*
** req_pgt.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun 15 11:25:32 2011 romain capot
** Last update Mon Jun 20 16:12:13 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		req_pgt(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		res[1024];

  sprintf(res, "pgt %d %s\n", fd, cmd);
  printcs(d, fd_dir, res);
}
