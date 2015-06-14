/*
** req_bct.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed Jun  8 13:02:53 2011 romain capot
** Last update Tue Jun 21 17:57:35 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"req_cmd.h"

void		do_bct(t_data *d, int fd, int fd_dir, t_pos *pos)
{
  t_box		*b;
  char		res[BUFF_SIZE];

  (void)fd;
  if ((b = getBox(d, pos->pos_x, pos->pos_y)))
    {
      sprintf(res, "bct %d %d %d %d %d %d %d %d %d\n", pos->pos_x, pos->pos_y,
	      b->food, b->pierres.linemate, b->pierres.deraumere,
	      b->pierres.sibur, b->pierres.mendiane, b->pierres.phiras,
	      b->pierres.thystame);
      printcs(d, fd_dir, res);
    }
  else
    printcs(d, fd_dir, BAD_PARAMETER);
}

void		req_bct(t_data *d, int fd, int fd_dir, char *cmd)
{
  char		*str_x;
  char		*str_y;
  t_pos		pos;

  (void)d;
  (void)fd;
  str_x = catch_arg(cmd, 1);
  str_y = catch_arg(cmd, 2);
  if (str_x && str_y)
    {
      pos.pos_x = atoi(str_x);
      pos.pos_y = atoi(str_y);
      do_bct(d, fd, fd_dir, &pos);
    }
  else
    printcs(d, fd_dir, BAD_PARAMETER);
}
