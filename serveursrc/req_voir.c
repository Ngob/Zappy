/*
** req_voir.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 10:15:51 2011 romain capot
** Last update Thu Jul  7 10:15:52 2011 romain capot
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"zappy.h"
#include	"req_dir.h"
#include	"req_cmd.h"
#include	"ressources.h"
#include	"map.h"
#include	"x.h"

static t_voir_dir	dir_tab[] = {
  {DIR_BOT, voir_bottom},
  {DIR_TOP, voir_up},
  {DIR_LEFT, voir_left},
  {DIR_RIGHT, voir_right},
  {-1, 0}
};

void		req_voir(t_data *d, int fd, int fd_dir, char *cmd)
{
  int		i;
  int		y;

  (void) fd_dir;
  (void) cmd;
  i = 0;
  y = d->fd[fd].pos.pos_y;
  while (dir_tab[i].cur_dir != -1)
    {
      if (d->fd[fd].pos.dir == dir_tab[i].cur_dir)
	dir_tab[i].ptr(d, fd, y);
      ++i;
    }
}

