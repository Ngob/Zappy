/*
** assign_multi_arg.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 10:06:06 2011 romain capot
** Last update Thu Jul  7 10:06:07 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"zappy.h"
#include	"x.h"

static int	count_team(int arg_place, int ac, char **av)
{
  int		i;

  i = 0;
  while (arg_place + 1 < ac && av[arg_place + 1][0] != '-')
    {
      ++i;
      ++arg_place;
    }
  return i;
}

void		assign_name_team(int arg_place, int ac,
				 char **av, t_args * args)
{
  int		nb_team;
  int		i;

  i = 0;
  if (arg_place + 1 < ac && av[arg_place + 1][0] != '-')
    {
      nb_team = count_team(arg_place, ac, av);
      args->team_name = Xmalloc(sizeof(args->team_name) * (nb_team + 1));
      ++arg_place;
      while (i < nb_team)
	{
	  args->team_name[i] = X(NULL, strdup(av[arg_place + i]), "strdup");
	  ++i;
	}
      args->team_name[i] = NULL;
    }
  else
    {
      fprintf(stderr, "Argument syntax error : -n [arg1] [arg2] ...\n");
      exit(EXIT_FAILURE);
    }
}
