/*
** buf_count.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Tue Jun 21 11:08:20 2011 romain capot
** Last update Wed Jul  6 11:31:33 2011 romain capot
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"zappy.h"

int		count_cmd(t_data *d, int fd)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (i < BUFF_SIZE && d->fd[fd].buf_r[i])
    {
      if (d->fd[fd].buf_r[i] == '\n')
	++nb;
      ++i;
    }
  return nb;
}
