/*
** req_inventaire.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 10:15:19 2011 romain capot
** Last update Sun Jul 10 13:49:08 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		req_inventaire(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		res[BUFF_SIZE];

  (void)cmd;
  sprintf(res, "{nourriture %d, linemate %d, deraumere %d, sibur %d",
	  d->fd[fd].food / (USEC / d->args->act_time) / FOOD_TIME,
	  d->fd[fd].pierres.linemate, d->fd[fd].pierres.deraumere,
	  d->fd[fd].pierres.sibur);
  sprintf(res, "%s, mendiane %d, phiras %d, thystame %d}\n",
	  res, d->fd[fd].pierres.mendiane,
	  d->fd[fd].pierres.phiras, d->fd[fd].pierres.thystame);
  printcs(d, fd_dir, res);
}
