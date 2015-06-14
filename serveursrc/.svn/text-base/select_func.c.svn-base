/*
** select_func.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Tue Jun 21 17:28:17 2011 romain capot
** Last update Sun Jul 10 19:31:40 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"x.h"

void		select_func(t_data *d, struct timeval *tv)
{
  if (tv->tv_usec >= 0)
    X((void *)-1,
      (void *)select(d->max + 1, &d->fd_read, &d->fd_write, NULL, tv),
      "Select");
  else
    X((void *)-1,
      (void *)select(d->max + 1, &d->fd_read, &d->fd_write, NULL, NULL),
      "Select");
}
