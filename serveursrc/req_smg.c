/*
** req_smg.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun  8 15:00:08 2011 romain capot
** Last update Tue Jun 21 11:32:40 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"

void		req_smg(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		*res;

  (void)fd;
  res = str_fmt("smg %s\n", cmd);
  if (res)
    {
      printcs(d, fd_dir, res);
      free(res);
    }
}
