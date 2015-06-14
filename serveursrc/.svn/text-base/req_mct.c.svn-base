/*
** req_mct.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun  8 13:29:33 2011 romain capot
** Last update Tue Jun 21 18:02:17 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		req_mct(t_data *d, int fd, int fd_dir, char *cmd)
{
  t_pos		pos;

  (void)cmd;
  pos.pos_x = 0;
  pos.pos_y = 0;
  while (pos.pos_y < d->args->sizeY)
    {
      while (pos.pos_x < d->args->sizeX)
	{
	  do_bct(d, fd, fd_dir, &pos);
	  ++pos.pos_x;
	}
      pos.pos_x = 0;
      ++pos.pos_y;
    }
}
