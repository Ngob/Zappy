/*
** del_fd.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 19:36:30 2011 romain capot
** Last update Sun Jul 10 19:36:30 2011 romain capot
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"zappy.h"
#include	"request.h"
#include	"x.h"
#include	"req_cmd.h"

static void	send_cmd(t_data *d, int fd)
{
  int		i;

  i = 0;
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
	req_pdi(d, fd, i, NULL);
      ++i;
    }
}

void		del_fd(t_data * d, int fd)
{
  t_request	*tmp;
  t_request	*erase;

  d->fd[fd].type = FD_FREE;
  if (d->fd[fd].status == CLT_IA)
    {
      if (d->fd[fd].lvl == MAX_LVL)
	dec_team_lvl(d, d->fd[fd].team);
      tmp = d->req;
      while (tmp)
	{
	  erase = tmp;
	  tmp = tmp->next;
	  if (erase->fd == fd)
	    request_erase(d, erase);
	}
      erase_player(d->fd[fd].team, d->list_team, 1);
      _X(NULL, memset(d->fd[fd].buf_r, 0, BUFF_SIZE), "Memset");
      _X(NULL, memset(d->fd[fd].buf_w, 0, BUFF_SIZE), "Memset");
      send_cmd(d, fd);
    }
  if (d->fd[fd].team)
    free(d->fd[fd].team);
  d->fd[fd].team = NULL;
  _X((void *)-1, (void *)close(fd), "Close");
}
