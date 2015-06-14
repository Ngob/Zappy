/*
** team.h for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 19:35:02 2011 romain capot
** Last update Sun Jul 10 19:35:03 2011 romain capot
*/

#ifndef		__TEAM_H__
#define		__TEAM_H__

#include	<string.h>

typedef struct	s_team_list
{
  char			*name;
  int			nb_max_player;
  int			lvl;
  struct s_team_list	*next;
}		t_team_list;

typedef struct	s_team_ref
{
  struct s_team_list	*begin;
  struct s_team_list	*end;
  int			size;
}		t_team_ref;

void		init_list(t_team_ref *);
int		add_team(char *, int, t_team_ref *);
int		insert_end_list(t_team_ref *, t_team_list *, char *, int);
void		erase_player(char *, t_team_ref *, int);
void		erase_list(t_team_ref *, char *);
void		aff_list(t_team_ref *);

#endif
