/*
** add_team.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun  8 11:09:24 2011 romain capot
** Last update Wed Jul  6 16:42:23 2011 romain capot
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"
#include	"x.h"
#include	"team.h"

void		add_ctl_team(t_data *d, int fd, char *cmd)
{
  int		id_drone;

  if (!strcmp(GRAPHIC_TEAM, cmd))
    {
      d->fd[fd].team = _X(NULL, (void *)strdup(cmd), "Strdup");
      req_add_grc(d, fd, fd, NULL);
    }
  else
    {
      if ((id_drone = drone_check(d, cmd)) >= 0)
	{
	  d->fd[fd].team = _X(NULL, (void *)strdup(cmd), "Strdup");
	  req_add_ia_drone(d, id_drone, fd, NULL);
	}
      else if (team_check(d, cmd))
	{
	  d->fd[fd].team = _X(NULL, (void *)strdup(cmd), "Strdup");
	  req_add_ia(d, fd, fd, NULL);
	}
      else
	{
	  printcs(d, fd, "ko\n");
	  del_fd(d, fd);
	}
    }
}
