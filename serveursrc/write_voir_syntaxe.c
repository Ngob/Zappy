/*
** write_voir_syntaxe.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 19:37:31 2011 romain capot
** Last update Sun Jul 10 19:38:13 2011 romain capot
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

char		*add_str(char *all, char *name, char delim)
{
  char          *new;

  if (!name)
    return (all);
  if (!all)
    new = _X(NULL, strdup(name), "strdup");
  else
    {
      new = str_fmt("%s%c%s", all, delim, name);
      free(all);
    }
  return (new);
}

static char		*check_joueur(t_data *d, int x, int y)
{
  char		*new;
  int		i;

  new = NULL;
  i = 0;
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT
	  && d->fd[i].pos.pos_x == x && d->fd[i].pos.pos_y == y
	  && (d->fd[i].status == CLT_IA || d->fd[i].status == CLT_DRN))
	new = add_str(new, "joueur", ' ');
      ++i;
    }
  return new;
}

static char		*write_stone(char *stone, int val)
{
  char		*res;
  int		i;

  res = NULL;
  i = 0;
  while (i < val)
    {
      res = add_str(res, stone, ' ');
      ++i;
    }
  return res;
}

static char		*check_stone(t_box *box)
{
  char		*res;
  char		*tmp;

  tmp = NULL;
  res = NULL;
  if ((tmp = write_stone(LINEMATE, box->pierres.linemate)))
    res = add_str(res, tmp, ' ');
  if ((tmp = write_stone(DERAUMERE, box->pierres.deraumere)))
      res = add_str(res, tmp, ' ');
  if ((tmp = write_stone(SIBUR, box->pierres.sibur)))
      res = add_str(res, tmp, ' ');
  if ((tmp = write_stone(MENDIANE, box->pierres.mendiane)))
      res = add_str(res, tmp, ' ');
  if ((tmp = write_stone(PHIRAS, box->pierres.phiras)))
      res = add_str(res, tmp, ' ');
  if ((tmp = write_stone(THYSTAME, box->pierres.thystame)))
      res = add_str(res, tmp, ' ');
  if ((tmp = write_stone(FOOD, box->food)))
      res = add_str(res, tmp, ' ');
  return res;
}

char		*find_obj_at_pos(t_data *d, int x, int y)
{
  t_box		*box;
  char		*res;

  res = NULL;
  res = check_joueur(d, x, y);
  box = getBox(d, x, y);
  res = add_str(res, check_stone(box), ' ');
  return res;
}
