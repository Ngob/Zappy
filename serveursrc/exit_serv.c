/*
** exit_serv.c for  in /home/capot_r//public/irc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Tue Apr 19 15:35:05 2011 romain capot
** Last update Mon May 16 10:34:34 2011 romain capot
*/

#include	"zappy.h"

void		exit_serv(int sig)
{
  (void)sig;
  check_exit(1);
}

int		check_exit(int flag)
{
  static int	res = 0;

  if (flag == 1)
    res = 1;
  return res;
}
