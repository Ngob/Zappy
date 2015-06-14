/*
** check_case.h for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 13:26:23 2011 romain capot
** Last update Sun Jul 10 13:26:24 2011 romain capot
*/

#ifndef		__CHECK_CASE_H__
#define		__CHECK_CASE_H__

#include	"broadcast.h"

typedef struct	s_arg_pos
{
  float		x;
  float		y;
}		t_arg_pos;

float		case_downleft(t_data *, int, int);
float		case_upleft(t_data *, int, int);
float		case_downright(t_data *, int, int);
float		case_upright(t_data *, int, int);
void		find_case_recep(t_data *, t_arg_pos *, int, int);

#endif
