/*
** server_zappy.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 19:34:55 2011 romain capot
** Last update Sun Jul 10 19:34:56 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"
#include	"graphic_info.h"

void		printPort(int port)
{
  printf("%sListening on port %d...%s\n", GREEN, port, BASE);
}

void		printTeams(t_args *args)
{
  int		i;

  i = 0;
  printf("%sTeams :\n", GREEN);
  printf("\tMax players -> %d\n", args->nb_clients);
  while (args->team_name[i] != NULL)
    {
      printf("%s\tName(%s)%s\n", GREEN, args->team_name[i], BASE);
      ++i;
    }
}

void		server_zappy(t_args args)
{
  t_data	data;

  init_data(&data, &args);
  printTeams(&args);
  printConfig(&args);
  add_server(data.args->port, &data);
  select_clients(&data);
}
