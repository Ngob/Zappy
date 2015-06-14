/*
** req_sst.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun  8 15:03:44 2011 romain capot
** Last update Tue Jun 21 11:32:46 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		req_sst(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		*str_time;
  int		time;

  str_time = catch_arg(cmd, 1);
  if (str_time)
    {
      time = atoi(str_time);
      d->args->act_time = time;
      req_sgt(d, fd, fd_dir, NULL);
    }
  else
    printcs(d, fd_dir, BAD_PARAMETER);
}
