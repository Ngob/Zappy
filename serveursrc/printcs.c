/*
** printcs.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 10:14:45 2011 romain capot
** Last update Thu Jul  7 10:14:46 2011 romain capot
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"graphic_info.h"
#include	"x.h"

static void	put_write(t_data *d, int cs, char *str, int nb_write)
{
  int		i;
  int		tot;
  int		size_buf;

  tot = nb_write;
  size_buf = strlen(str);
  i = strlen(d->fd[cs].buf_w);
  while (i < BUFF_SIZE && str[tot] && tot < size_buf)
    d->fd[cs].buf_w[i++] = str[tot++];
}

void		printcs(t_data *d, int cs, char *str)
{
  int		nb_write;
  int		str_size;

  str_size = strlen(str);
  if ((nb_write = write(cs, str, str_size)) <= 0)
    del_fd(d, cs);
  else if (nb_write < str_size)
    put_write(d, cs, str, nb_write);
  sending_message(str, cs);
}
