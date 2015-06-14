/*
** req_connect_nbr.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun 15 13:27:34 2011 romain capot
** Last update Wed Jun 15 13:35:44 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		req_connect_nbr(t_data *d, int fd, int fd_dir, char *cmd)
{
  t_team_list	*tmp;
  char		res[BUFF_SIZE];

  (void)cmd;
  tmp = d->list_team->begin;
  while (tmp)
    {
      if (!strcmp(tmp->name, d->fd[fd].team))
	{
	  sprintf(res, "%d\n", tmp->nb_max_player);
	  printcs(d, fd, res);
	  return ;
	}
      tmp = tmp->next;
    }
  printcs(d, fd_dir, "ko\n");
}
