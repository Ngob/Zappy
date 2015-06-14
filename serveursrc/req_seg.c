/*
** req_seg.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun  8 14:40:38 2011 romain capot
** Last update Thu Jun  9 10:18:11 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"

void		req_seg(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		*res;

  (void)fd;
  res = str_fmt("seg %s\n", cmd);
  if (res)
    {
      printcs(d, fd_dir, res);
      free(res);
    }
}
