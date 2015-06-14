/*
** req_pin.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 10:15:42 2011 romain capot
** Last update Thu Jul  7 10:15:42 2011 romain capot
*/

#include	<stdlib.h>
#include        <stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		do_pin(t_data *d, int fd, int fd_dir, int player)
{
  char		res[BUFF_SIZE];

  (void)fd;
  sprintf(res, "pin %d %d %d %d %d %d %d %d %d %d\n",
	  player, d->fd[player].pos.pos_x,
	  d->fd[player].pos.pos_y,
	  d->fd[player].food / (USEC / d->args->act_time) / FOOD_TIME,
	  d->fd[player].pierres.linemate,
	  d->fd[player].pierres.deraumere,
	  d->fd[player].pierres.sibur,
	  d->fd[player].pierres.mendiane,
	  d->fd[player].pierres.phiras,
	  d->fd[player].pierres.thystame);
  printcs(d, fd_dir, res);
}

void		req_pin(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		*arg;
  int		player;

  (void)fd;
  arg = catch_arg(cmd, 1);
  if (arg)
    {
      player = atoi(arg);
      do_pin(d, fd, fd_dir, player);
    }
}
