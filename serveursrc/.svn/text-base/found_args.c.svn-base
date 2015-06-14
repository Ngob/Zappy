/*
** found_args.c for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Mon May 16 10:42:05 2011 romain capot
** Last update Thu May 19 11:20:13 2011 romain capot
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"assign_args.h"

t_getArgs	arg_tab[] = {
  {"-p", &assign_port, -1},
  {"-x", &assign_width, -1},
  {"-y", &assign_height, -1},
  {"-c", &assign_nb_clt, -1},
  {"-t", &assign_act_time, 100},
  {"-n", &assign_name_team, -1},
  {NULL, NULL, -1},
};

static int	found_cmd(int ac, char **av, char *cmd)
{
  int		i;

  i = 0;
  while (i < ac)
    {
      if (!strcmp(av[i], cmd))
	return i;
      ++i;
    }
  return 0;
}

t_args		found_args(int ac, char **av)
{
  t_args	args;
  int		arg_place;
  int		i;

  i = 0;
  while (arg_tab[i].cmd)
    {
      if ((arg_place = found_cmd(ac, av, arg_tab[i].cmd)))
	arg_tab[i].ptr_func(arg_place, ac, av, &args);
      else if (arg_tab[i].dfl < 0)
	{
	  fprintf(stderr, "Zappy : missing argument %s\n", arg_tab[i].cmd);
	  exit(EXIT_FAILURE);
	}
      else if (!strcmp(arg_tab[i].cmd, "-t"))
	args.act_time = arg_tab[i].dfl;
      ++i;
    }
  return args;
}
