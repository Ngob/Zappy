/*
** request_active.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 16:37:53 2011 romain capot
** Last update Sun Jul 10 19:25:08 2011 romain capot
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"zappy.h"
#include	"request.h"

void		request_active(t_data *d, int fd, t_request *req, int act)
{
  if (act != -1)
    req->active = act;
  else if (request_search_fd(d, fd))
    req->active = ACTIVE_OFF;
  else
    req->active = ACTIVE_ON;
}
