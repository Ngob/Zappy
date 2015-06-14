/*
** team.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 19:35:08 2011 romain capot
** Last update Sun Jul 10 19:36:55 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"team.h"
#include	"x.h"

void		init_list(t_team_ref *ref)
{
  ref->begin = NULL;
  ref->end = NULL;
  ref->size = 0;
}

int		add_team(char *Name, int Nb_max_player, t_team_ref *ref)
{
  t_team_list	*new;

  if ((new = malloc(sizeof(t_team_list))) == NULL)
    return (-1);
  if ((new->name = strdup(Name)) == NULL)
    return (-1);
  new->nb_max_player = Nb_max_player;
  new->lvl = 0;
  new->next = NULL;
  ref->begin = new;
  ref->end = new;
  ref->size++;
  return (0);
}

int		insert_end_list(t_team_ref *ref, t_team_list *current_element,
				char *Name, int Nb_max_player)
{
  t_team_list	*new;

  if ((new = malloc(sizeof(t_team_list))) == NULL)
    return (-1);
  if ((new->name = strdup(Name)) == NULL)
    return (-1);
  new->nb_max_player = Nb_max_player;

  current_element->next = new;
  new->next = NULL;

  ref->end = new;
  ref->size++;
  return (0);
}

void		erase_list(t_team_ref *ref, char *Name)
{
  t_team_list	*current_element;
  t_team_list	*delete_element;

  current_element = ref->begin;
  while (current_element != NULL && (strcmp(Name, current_element->name)))
    {
      current_element = current_element->next;
    }
  delete_element = current_element->next;
  current_element->next = current_element->next->next;
  if (current_element->next == NULL)
    ref->end = current_element;
  free (delete_element->name);
  free (delete_element);
  ref->size--;
}

void		erase_player(char *Name, t_team_ref *ref, int player_dead)
{
  t_team_list *current_element;

  current_element = ref->begin;
  while (current_element != NULL)
    {
      if (strcmp(Name, current_element->name) == 0)
	current_element->nb_max_player = current_element->nb_max_player
	  + player_dead;
      current_element = current_element->next;
    }
}
