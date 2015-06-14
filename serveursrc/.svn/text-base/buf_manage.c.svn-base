/*
** add_buf.c for  in /home/capot_r//public/irc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Mon Apr 18 11:44:26 2011 romain capot
** Last update Wed Jul  6 16:51:54 2011 romain capot
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"zappy.h"
#include	"client.h"
#include	"x.h"

void		add_buf(int fd, t_data *d, char *buf)
{
  int		i;
  size_t	j;

  j = 0;
  i = strlen(d->fd[fd].buf_r);
  if (count_cmd(d, fd) < 10)
    {
      while (j < strlen(buf) && i < BUFF_SIZE - 1)
	{
	  if ((buf[j] > 31 && buf[j] < 127) || buf[j] == '\n')
	      d->fd[fd].buf_r[i++] = buf[j];
	  if (buf[j] == '\n')
	    if (count_cmd(d, fd) >= 10)
	      return;
	  ++j;
	}
    }
}

static int	search_size_buf(t_data *d, int fd)
{
  int		i;

  i = 0;
  while (d->fd[fd].buf_r[i] != '\0' &&
	 d->fd[fd].buf_r[i] != '\n' &&
	 i < BUFF_SIZE)
    ++i;
  if (d->fd[fd].buf_r[i] == '\n')
    return i + 1;
  return 0;
}

static void	catch_buf(t_data *d, int fd, char *cmd, int size)
{
  int		i;

  i = 0;
  while (i < size - 1)
    {
      cmd[i] = d->fd[fd].buf_r[i];
      ++i;
    }
}

static void	decal_buf(t_data *d, int fd, int size)
{
  int		i;
  int		j;

  i = size;
  j = 0;
  while (i < BUFF_SIZE)
    {
      d->fd[fd].buf_r[j] = d->fd[fd].buf_r[i];
      ++i;
      ++j;
    }
}

char *		valid_buf(t_data *d, int fd)
{
  char		*cmd;
  int		size_buf;

  size_buf = search_size_buf(d, fd);
  if (size_buf > 0)
    {
      if ((cmd = malloc(sizeof(*cmd) * (size_buf + 1))))
	{
	  memset(cmd, 0, size_buf + 1);
	  catch_buf(d, fd, cmd, size_buf);
	  decal_buf(d, fd, size_buf);
	  return cmd;
	}
    }
  return NULL;
}
