/*
** broadcast.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 13:25:44 2011 romain capot
** Last update Sun Jul 10 14:20:00 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"broadcast.h"
#include	"req_cmd.h"

t_case	case_info[] = {
  {DIR_TOP, 0, -1, 1},
  {DIR_TOP, -1, -1, 2},
  {DIR_TOP, -1, 0, 3},
  {DIR_TOP, -1, 1, 4},
  {DIR_TOP, 0, 1, 5},
  {DIR_TOP, 1, 1, 6},
  {DIR_TOP, 1, 0, 7},
  {DIR_TOP, 1, -1, 8},
  {DIR_RIGHT, 1, 0, 1},
  {DIR_RIGHT, 1, -1, 2},
  {DIR_RIGHT, 0, -1, 3},
  {DIR_RIGHT, -1, -1, 4},
  {DIR_RIGHT, -1, 0, 5},
  {DIR_RIGHT, -1, 1, 6},
  {DIR_RIGHT, 0, 1, 7},
  {DIR_RIGHT, 1, 1, 8},
  {DIR_BOT, 0, 1, 1},
  {DIR_BOT, 1, 1, 2},
  {DIR_BOT, 1, 0, 3},
  {DIR_BOT, 1, -1, 4},
  {DIR_BOT, 0, -1, 5},
  {DIR_BOT, 0, -1, 6},
  {DIR_BOT, -1, -1, 7},
  {DIR_BOT, -1, 0, 8},
  {DIR_LEFT, -1, 0, 1},
  {DIR_LEFT, -1, 1, 2},
  {DIR_LEFT, 0, 1, 3},
  {DIR_LEFT, 1, 1, 4},
  {DIR_LEFT, 1, 0, 5},
  {DIR_LEFT, 1, -1, 6},
  {DIR_LEFT, 0, -1, 7},
  {DIR_LEFT, -1, -1, 8}
};

char		*erase_broad(char *src)
{
  size_t	i;
  size_t       	j;
  char		*dest;

  i = 0;
  j = 0;
  dest = Xmalloc(sizeof(char) * strlen(src));
  _X(NULL, memset(dest, 0, strlen(dest)), "Memset");
  if (!strncmp(src, "broadcast", 9))
    i = 10;
  while (src[i] != '\0')
    {
      dest[j] = src[i];
      i++;
      j++;
    }
  dest[j] = '\0';
  return (dest);
}

void		req_broadcast(t_data *d, int fd, int fd_dir, char *cmd)
{
  int		i;
  char		*str;

  (void)fd_dir;
  i = 0;
  while (i < d->maxfd && i < d->max + 1)
    {
      d->fd[i].broad = Xmalloc(sizeof(t_broad));
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_IA && i != fd)
	{
	  check_short_way(d, fd, i);
	  str = str_fmt("message %d, %s\n",
			d->fd[i].broad->case_recep, erase_broad(cmd));
	  if (str)
	    {
	      printcs(d, i, str);
	      free(str);
	    }
	}
      free(d->fd[i].broad);
      ++i;
    }
  printcs(d, fd, "ok\n");
  broad_grc(d, fd, cmd);
}

void		broad_grc(t_data *d, int fd, char *cmd)
{
  int		i;

  i = 0;
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
	req_pbc(d, fd, i, erase_broad(cmd));
      ++i;
    }
}

float		count_dist(float xdep, float ydep, float xarr, float yarr)
{
  float		dist_long;
  float		dist_larg;
  float		hypothenuse;

  if (xdep == xarr || ydep == yarr)
    return (check_dist(xdep, ydep, xarr, yarr));
  else
    {
      dist_long = yarr - ydep;
      dist_larg = xarr - ydep;
      hypothenuse = sqrt((dist_long * dist_long) + (dist_larg * dist_larg));
      return (hypothenuse);
    }
}

int		def_direct(int x, int y, int dir)
{
  int		i;

  i = 0;
  while (case_info[i].x != x && case_info[i].y != y && case_info[i].dir != dir)
    i++;
  return (case_info[i].nb);
}
