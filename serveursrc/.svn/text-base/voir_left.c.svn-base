/*
** voir_left.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 13:30:04 2011 romain capot
** Last update Sun Jul 10 13:30:05 2011 romain capot
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

static char	*vison_laterale(t_data *d, int fd, int pos_x, int i)
{
  int		j;
  int		pos_y;
  int		good_y;
  int		vision;
  char		*res;

  j = 0;
  res = NULL;
  vision = i * 2 + 1;
  pos_y = d->fd[fd].pos.pos_y;
  while (j < vision)
    {
      good_y = setGood_xy(pos_y + i - j, d->args->sizeY);
      res = add_str(res, find_obj_at_pos(d, pos_x, good_y), ' ');
      if (!((i + 1) == d->fd[fd].lvl + 1 && (j + 1) == vision))
	res = (res == NULL) ? (str_fmt("%s", " ")) : (str_fmt("%s, ", res));
      ++j;
    }
  return res;
}

void		voir_left(t_data *d, int fd, int pos_y)
{
  char		*res;
  int		i;
  int		vision;
  int		good_x;
  int		pos_x;

  (void) pos_y;
  res = NULL;
  i = 0;
  good_x = 0;
  vision = 1;
  pos_x = d->fd[fd].pos.pos_x;
  while (i < d->fd[fd].lvl + 1)
    {
      good_x = setGood_xy(pos_x, d->args->sizeX);
      res = add_str(res, vison_laterale(d, fd, good_x, i), ' ');
      vision += 2;
      ++i;
      --pos_x;
    }
  print_voir_to_client(d, fd, res);
}
