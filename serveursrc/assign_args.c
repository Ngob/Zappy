/*
** assign_args.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 10:05:45 2011 romain capot
** Last update Thu Jul  7 10:05:45 2011 romain capot
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"zappy.h"
#include	"graphic_info.h"

void		assign_port(int arg_place, int ac, char **av, t_args * args)
{
  if (arg_place + 1 < ac && av[arg_place + 1][0] != '-')
    {
      args->port = atoi(av[arg_place + 1]);
      printPort(args->port);
    }
  else
    {
      fprintf(stderr, "Argument syntax error : -p [arg]\n");
      exit(EXIT_FAILURE);
    }
}

void		assign_width(int arg_place, int ac, char **av, t_args * args)
{
  int		width;

  if (arg_place + 1 < ac && av[arg_place + 1][0] != '-'
      && check_valid_nb(av[arg_place + 1]))
    {
      width = atoi(av[arg_place + 1]);
      if (width > 0)
	args->sizeX = width;
      else
	{
	  fprintf(stderr, "Argument syntax error : -x < 0\n");
	  exit(EXIT_FAILURE);
	}
    }
  else
    {
      fprintf(stderr, "Argument syntax error : -x [arg]\n");
      exit(EXIT_FAILURE);
    }
}

void		assign_height(int arg_place, int ac, char **av, t_args * args)
{
  int		height;

  if (arg_place + 1 < ac && av[arg_place + 1][0] != '-'
      && check_valid_nb(av[arg_place + 1]))
    {
      height = atoi(av[arg_place + 1]);
      if (height)
	args->sizeY = height;
      else
	{
	  fprintf(stderr, "Argument syntax error : -y < 0\n");
	  exit(EXIT_FAILURE);
	}
    }
  else
    {
      fprintf(stderr, "Argument syntax error : -y [arg]\n");
      exit(EXIT_FAILURE);
    }
}

void		assign_nb_clt(int arg_place, int ac, char **av, t_args * args)
{
  int		nb_clt;

  if (arg_place + 1 < ac && av[arg_place + 1][0] != '-'
      && check_valid_nb(av[arg_place + 1]))
    {
      nb_clt = atoi(av[arg_place + 1]);
      if (nb_clt > 0)
	args->nb_clients = atoi(av[arg_place + 1]);
      else
	{
	  fprintf(stderr, "Argument syntax error : -c < 0\n");
	  exit(EXIT_FAILURE);
	}
    }
  else
    {
      fprintf(stderr, "Argument syntax error : -c [arg]\n");
      exit(EXIT_FAILURE);
    }
}

void		assign_act_time(int arg_place, int ac, char **av, t_args * args)
{
  if (arg_place + 1 < ac && av[arg_place + 1][0] != '-'
      && check_valid_nb(av[arg_place + 1]))
    args->act_time = atoi(av[arg_place + 1]);
  else
    {
      fprintf(stderr, "Argument syntax error : -t [arg]\n");
      exit(EXIT_FAILURE);
    }
}
