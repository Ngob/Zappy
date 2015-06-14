/*
** req_sgt.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun  8 14:55:18 2011 romain capot
** Last update Tue Jun 21 11:32:33 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"

void		req_sgt(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		res[BUFF_SIZE];

  (void)cmd;
  (void)fd;
  sprintf(res, "sgt %d\n", d->args->act_time);
  printcs(d, fd_dir, res);
}
