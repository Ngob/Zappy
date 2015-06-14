/*
** req_eht.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun  8 17:10:20 2011 romain capot
** Last update Mon Jun 20 16:13:11 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		req_eht(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		res[BUFF_SIZE];

  (void)fd;
  (void)cmd;
  sprintf(res, "eht %d\n", fd);
  printcs(d, fd_dir, res);
}
