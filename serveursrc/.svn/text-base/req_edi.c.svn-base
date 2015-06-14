/*
** req_edi.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun  8 16:57:27 2011 romain capot
** Last update Mon Jun 20 16:13:16 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		req_edi(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		res[BUFF_SIZE];

  (void)cmd;
  sprintf(res, "edi %d\n", fd);
  printcs(d, fd_dir, res);
}
