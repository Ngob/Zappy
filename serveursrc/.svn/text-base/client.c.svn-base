/*
** client.c for  in /home/capot_r//public/irc/serveursrc
**
** Made by romain capot
** Login   <capot_r@epitech.net>
**
** Started on  Mon Apr 18 10:37:16 2011 romain capot
** Last update Wed Jul  6 16:44:24 2011 romain capot
*/

#include	<fcntl.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"zappy.h"
#include	"client.h"
#include	"req_cmd.h"
#include	"graphic_info.h"
#include	"x.h"

void		client_read(int fd, t_data * d)
{
  int		nb_rec;
  int		i;
  char		buf[BUFF_SIZE];
  char		*cmd;

  i = 0;
  memset(buf, 0, BUFF_SIZE);
  if ((nb_rec = read(fd, buf, BUFF_SIZE - 1)) <= 0)
    del_fd(d, fd);
  else
    {
      add_buf(fd, d, buf);
      received_message(buf, fd);
      while ((cmd = valid_buf(d, fd)))
      	{
      	  if (d->fd[fd].team)
	    check_cmd(d, fd, cmd);
      	  else
      	    add_ctl_team(d, fd, cmd);
      	  free(cmd);
      	}
    }
}

void		client_write(int fd, t_data * d)
{
  char		*cmd;

  if ((cmd = _X(NULL, (void *)strdup(d->fd[fd].buf_w), "Strdup")))
    {
      if (memset(d->fd[fd].buf_w, 0, BUFF_SIZE))
	{
	  printcs(d, fd, cmd);
	  free(cmd);
	}
    }
}
