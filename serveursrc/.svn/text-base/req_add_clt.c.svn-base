/*
** req_add_clt.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun  8 11:20:11 2011 romain capot
** Last update Tue Jul  5 09:48:19 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		req_add_grc(t_data *d, int fd, int fd_dir, char *cmd)
{
  int		i;
  t_drone	*tmp;

  (void)cmd;
  i = 0;
  d->fd[fd].status = CLT_GRC;
  tmp = d->drones.drone;
  req_msz(d, fd, fd_dir, NULL);
  req_sgt(d, fd, fd_dir, NULL);
  req_mct(d, fd, fd_dir, NULL);
  req_tna(d, fd, fd_dir, NULL);
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_IA)
	{
	  req_pnw(d, i, fd, NULL);
	  do_pin(d, i, fd, i);
	}
      ++i;
    }
  while (tmp)
    {
      req_enw(d, tmp->id, fd, NULL);
      tmp = tmp->next;
    }
}

void		req_add_ia(t_data *d, int fd, int fd_dir, char *cmd)
{
  int		i;
  char		res[BUFF_SIZE];

  i = 0;
  (void)cmd;
  (void)fd_dir;
  d->fd[fd].status = CLT_IA;
  sprintf(res, "%d\n", fd);
  printcs(d, fd, res);
  sprintf(res, "%d %d\n", d->args->sizeX, d->args->sizeY);
  printcs(d, fd, res);
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
	req_pnw(d, fd, i, NULL);
      ++i;
    }
}

static void	init_data_drone(t_data *d, int fd, int fd_dir)
{
  t_drone	*dr;

  dr = getDrone(d, fd);
  d->fd[fd_dir].food = dr->food;
  d->fd[fd_dir].lvl = dr->lvl;
  d->fd[fd_dir].pos.pos_x = dr->pos_x;
  d->fd[fd_dir].pos.pos_y = dr->pos_y;
  d->fd[fd_dir].pos.dir = dr->dir;
}

void		req_add_ia_drone(t_data *d, int fd, int fd_dir, char *cmd)
{
  int		i;
  char		res[BUFF_SIZE];

  i = 0;
  (void)cmd;
  d->fd[fd_dir].status = CLT_IA;
  init_data_drone(d, fd, fd_dir);
  sprintf(res, "%d\n", fd_dir);
  printcs(d, fd_dir, res);
  sprintf(res, "%d %d\n", d->args->sizeX, d->args->sizeY);
  printcs(d, fd_dir, res);
  drone_erase(d, fd);
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
	{
	  req_ebo(d, fd, i, NULL);
	  req_pnw(d, fd_dir, i, NULL);
	}
      ++i;
    }
}
