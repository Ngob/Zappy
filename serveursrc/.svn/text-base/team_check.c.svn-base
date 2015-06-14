/*
** team_check.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Tue Jun 21 17:40:34 2011 romain capot
** Last update Tue Jun 28 16:56:47 2011 romain capot
*/

#include	<stdio.h>
#include	"zappy.h"

int		team_check(t_data *d, char *cmd)
{
  t_team_list	*current_element;

  current_element = d->list_team->begin;
  while (current_element)
    {
      if (!strcmp(cmd, current_element->name))
	{
	  if (current_element->nb_max_player <= 0)
	    return (0);
	  current_element->nb_max_player--;
	  return (1);
	}
      current_element = current_element->next;
    }
  return (0);
}
