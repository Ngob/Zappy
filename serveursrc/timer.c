/*
** timer.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 10:16:37 2011 romain capot
** Last update Sun Jul 10 19:31:36 2011 romain capot
*/

#include	<stdio.h>
#include	<time.h>
#include	"zappy.h"
#include	"request.h"
#include	"food.h"

int		timer_milli(struct timeval *check_time,
			    struct timeval *start_time)
{
  int		add;

  add = USEC - start_time->tv_usec;
  add += check_time->tv_usec;
  add %= USEC;
  return add;
}

static int	get_food(t_data *d)
{
  int		drone_out;
  int		food_out;

  drone_out = drone_timeout(d);
  food_out = food_timeout(d);
  if ((drone_out != 0 && drone_out < food_out) ||
      food_out == 0)
    return drone_out;
  else
    return food_out;
}

int		setTimer(t_data *d)
{
  int		req_timeout;
  int		food_out;

  req_timeout = request_timeout(d);
  food_out = get_food(d);
  if (req_timeout != -1 && req_timeout < food_out)
    return req_timeout;
  else if (food_out != 0)
      return food_out;
  else
    return -1;
}

void		init_timer(t_data *d, struct timeval *tv, int *timeout)
{
  tv->tv_sec = 0;
  tv->tv_usec = setTimer(d);
  *timeout = tv->tv_usec;
}

void		timer_diff(int *diff_time, int save_timeout,
			   struct timeval *check_time,
			   struct timeval *start_time)
{
  *diff_time = 0;
  *diff_time += (difftime(check_time->tv_sec, start_time->tv_sec) * USEC);
  *diff_time += timer_milli(check_time, start_time);
  if (*diff_time > save_timeout)
    *diff_time = save_timeout;
}
