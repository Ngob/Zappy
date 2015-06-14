/*
** req_dir.h for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 10:15:06 2011 romain capot
** Last update Thu Jul  7 10:15:07 2011 romain capot
*/

#ifndef		__REQ_DIR_H__
#define		__REQ_DIR_H__

int		setGood_xy(int, int);
void	        print_voir_to_client(t_data *, int, char *);
void            voir_up(t_data *, int, int);
void		voir_bottom(t_data *, int , int);
void		voir_right(t_data *, int , int);
void		voir_left(t_data *, int , int);

typedef	struct	s_check_dir
{
  int		cur_dir;
  int		diff_x;
  int		diff_y;
  int		next_dir;
}		t_dir;

typedef struct	s_voir_dir
{
  int		cur_dir;
  void		(*ptr)(t_data *, int, int);
}		t_voir_dir;

typedef struct	s_exp_dir
{
  int		exp_dir;
  int		diff_x;
  int		diff_y;
  int		exp_case;
}		t_exp_dir;

#endif
