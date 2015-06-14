/*
** voir_down.c for \ in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 19:39:19 2011 romain capot
** Last update Sun Jul 10 19:39:21 2011 romain capot
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

static char	*vison_laterale(t_data *d, int fd, int pos_y, int i)
{
  int		j;
  int		pos_x;
  int		good_x;
  int		vision;
  char		*res;

  j = 0;
  res = NULL;
  vision = i * 2 + 1;
  pos_x = d->fd[fd].pos.pos_x;
  while (j < vision)
    {
      good_x = setGood_xy(pos_x + i - j, d->args->sizeX);
      res = add_str(res, find_obj_at_pos(d, good_x, pos_y), ' ');
      if (!((i + 1) == d->fd[fd].lvl + 1 && (j + 1) == vision))
	res = (res == NULL) ? (str_fmt("%s", " ")) : (str_fmt("%s, ", res));
      ++j;
    }
  return res;
}

void		voir_bottom(t_data *d, int fd, int pos_y)
{
  char		*res;
  int		i;
  int		vision;
  int		good_y;

  res = NULL;
  i = 0;
  good_y = 0;
  vision = 1;
  while (i < d->fd[fd].lvl + 1)
    {
      good_y = setGood_xy(pos_y, d->args->sizeY);
      res = add_str(res, vison_laterale(d, fd, good_y, i), ' ');
      vision += 2;
      ++i;
      ++pos_y;
    }
  print_voir_to_client(d, fd, res);
}
