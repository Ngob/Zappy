/*
** main.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 13:29:40 2011 romain capot
** Last update Sun Jul 10 13:29:41 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<time.h>
#include	"zappy.h"

int		main(int ac, char **av)
{
  if (ac > 1)
    {
      srand(time(NULL));
      server_zappy(found_args(ac, av));
    }
  else
    {
      fprintf(stderr, "To few arguments\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
