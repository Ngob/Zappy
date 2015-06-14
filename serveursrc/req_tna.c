/*
** req_tna.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Tue Jun 14 13:35:36 2011 romain capot
** Last update Wed Jun 15 13:47:15 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		do_tna(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		*res;

  (void)fd;
  res = str_fmt("tna %s\n", cmd);
  if (res)
    {
      printcs(d, fd_dir, res);
      free(res);
    }
}

void		req_tna(t_data *d, int fd, int fd_dir, char *cmd)
{
  t_team_list	*tmp;

  (void)cmd;
  tmp = d->list_team->begin;
  while (tmp)
    {
      do_tna(d, fd, fd_dir, tmp->name);
      tmp = tmp->next;
    }
}
