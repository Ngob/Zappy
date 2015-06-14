/*
** init_data.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 13:29:30 2011 romain capot
** Last update Sun Jul 10 13:29:30 2011 romain capot
*/

#include	<unistd.h>
#include	<sys/resource.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"x.h"
#include	"team.h"
#include	"drone.h"

void		init_data(t_data *d, t_args *args)
{
  int		i;
  struct rlimit lim;

  i = 0;
  d->max = 0;
  X((void *)-1, (void *)getrlimit(RLIMIT_NOFILE, &lim), "Getrlimit");
  d->maxfd = lim.rlim_cur;
  d->fd = Xmalloc(sizeof(*(d->fd)) * (d->maxfd + 1));
  d->req = NULL;
  d->args = args;
  d->map = Xmalloc(sizeof((*d->map)) * ((args->sizeX * args->sizeY) + 1));
  init_map(d, args);
  while (i <= d->maxfd)
    {
      d->fd[i].type = FD_FREE;
      d->fd[i].func_read = NULL;
      d->fd[i].func_write = NULL;
      ++i;
    }
  d->list_team = Xmalloc(sizeof(d->list_team));
  init_list(d->list_team);
  put_team_list(d);
  d->drones.id_drone = d->maxfd + 1;
  d->drones.drone = NULL;
}

void		put_team_list(t_data *d)
{
  int		i;

  i = 0;
  while (d->args->team_name[i] != NULL)
    {
      if (d->list_team->begin == NULL)
	add_team(d->args->team_name[i], d->args->nb_clients, d->list_team);
      else
	insert_end_list(d->list_team, d->list_team->end,
			d->args->team_name[i], d->args->nb_clients);
      i++;
    }
}
