/*
** req_pbc.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 10:15:30 2011 romain capot
** Last update Sun Jul 10 14:12:59 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		req_pbc(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		*res;

  if (cmd)
    {
      res = str_fmt("pbc %d %s\n", fd, cmd)
;
      printcs(d, fd_dir, res);
      free(res);
    }
  else
    printcs(d, fd_dir, BAD_PARAMETER);
}
