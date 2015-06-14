/*
** request.h for  in /home/capot_r//tek2/c/zappy
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Wed May 18 10:49:07 2011 romain capot
** Last update Thu Jul  7 16:43:56 2011 romain capot
*/

#ifndef		__REQUEST_H__
#define		__REQUEST_H__

#define	ACTIVE_ON	0
#define	ACTIVE_OFF	1

struct	s_request
{
  int	time;
  int	fd;
  char	*cmd;
  int	active;
  void	(*ptr_func)(t_data *, int, int, char *);
  struct s_request	*next;
};

int		request_next(t_data *, int);
void		request_add(t_data *, t_cmd *, int, char *);
int		request_size(t_data *);
void		request_check(t_data *);
void		request_dec(t_data *, int);
void		request_erase(t_data *, t_request *);
int		request_search_fd(t_data *, int);
int		request_search_fd_active(t_data *, int);
void		request_switch(t_data *, int);
int		request_timeout(t_data *);
int		request_count(t_data *, int);
void		request_active(t_data *, int, t_request *, int);

#endif
