/*
** select_clients.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 19:35:13 2011 romain capot
** Last update Sun Jul 10 19:36:56 2011 romain capot
*/

#include	<stdlib.h>
#include	<string.h>
#include	<sys/time.h>
#include	<signal.h>
#include	<time.h>
#include	<stdio.h>
#include	<sys/timeb.h>
#include	"zappy.h"
#include	"request.h"
#include	"timer.h"
#include	"food.h"
#include	"x.h"

static void	set_fd(t_data * d)
{
  int		i;

  i = 0;
  FD_ZERO(&d->fd_read);
  FD_ZERO(&d->fd_write);
  while (i < d->maxfd)
    {
      if (d->fd[i].type == FD_CLT ||
	  (d->fd[i].type == FD_SERV && check_free_space(d)))
	{
	  FD_SET(i, &d->fd_read);
	  if (strlen(d->fd[i].buf_w) > 0)
	    FD_SET(i, &d->fd_write);
	  d->max = i;
	}
      ++i;
    }
}

static void	check_fd(t_data * d)
{
  int		i;

  i = 0;
  while (i <= d->max)
    {
      if (d->fd[i].type != FD_FREE)
	{
	  if (FD_ISSET(i, &d->fd_read))
	    d->fd[i].func_read(i, d);
	  if (FD_ISSET(i, &d->fd_write))
	    d->fd[i].func_read(i, d);
	}
      ++i;
    }
}

static void	analysis_data(t_data *d, int diff_time)
{
  if (diff_time >= 0)
    {
      drone_food_dec(d, diff_time);
      food_dec(d, diff_time);
      request_dec(d, diff_time);
      request_check(d);
    }
  check_fd(d);
}

void		select_clients(t_data * d)
{
  struct timeval tv;
  struct timeval start_time;
  struct timeval check_time;
  int		 diff_time;
  int	        save_timeout;
  int		exit;

  X((void *)SIG_ERR, (void *)signal(SIGINT, exit_serv), "Signal");
  exit = 0;
  while (!exit)
    {
      init_timer(d, &tv, &save_timeout);
      set_fd(d);
      gettimeofday(&start_time, NULL);
      select_func(d, &tv);
      gettimeofday(&check_time, NULL);
      timer_diff(&diff_time, save_timeout, &check_time, &start_time);
      if (!(exit = check_exit(0)))
	analysis_data(d, diff_time);
      exit = check_end_game(d);
    }
  close_fd(d);
}
