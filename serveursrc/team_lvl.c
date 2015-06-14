/*
** team_lvl.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 19:38:09 2011 romain capot
** Last update Sun Jul 10 19:39:40 2011 romain capot
*/

#include	"zappy.h"
#include	"req_cmd.h"

void		dec_team_lvl(t_data *d, char *name)
{
  t_team_list   *current_element;

  current_element = d->list_team->begin;
  while (current_element)
    {
      if (!strcmp(current_element->name, name))
	{
	  current_element->lvl -= 1;
	  return ;
	}
      current_element = current_element->next;
    }
}

int		get_team_player_by_lvl(t_data *d, char *name, int lvl)
{
  int		i;
  int		check;

  i = 0;
  check = 0;
  while (i < d->maxfd && i < d->max + 1)
    {
      if (d->fd[i].type == FD_CLT &&
	  !strcmp(d->fd[i].team, name) && d->fd[i].lvl == lvl)
	check++;
      ++i;
    }
  return check;
}

void		set_nb_max_lvl_by_team(t_data *d, char *name, int nb_max_lvl)
{
  t_team_list   *current_element;

  current_element = d->list_team->begin;
  while (current_element)
    {
      if (!strcmp(current_element->name, name))
	{
	  current_element->lvl = nb_max_lvl;
	  return ;
	}
      current_element = current_element->next;
    }
}

int		check_end_game(t_data *d)
{
  t_team_list   *current_element;
  int		i;

  i = 0;
  current_element = d->list_team->begin;
  while (current_element)
    {
      if (current_element->lvl >= WIN_LIM_PLAY)
	{
	  while (i < d->maxfd && i < d->max + 1)
	    {
	      if (d->fd[i].type == FD_CLT && d->fd[i].status == CLT_GRC)
		req_seg(d, 0, i, current_element->name);
	      i++;
	    }
	  return 1;
	}
      current_element = current_element->next;
    }
  return 0;
}
