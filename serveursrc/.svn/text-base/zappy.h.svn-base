/*
** zappy.h for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 19:37:24 2011 romain capot
** Last update Sun Jul 10 19:37:24 2011 romain capot
*/

#include	<unistd.h>
#include	<sys/types.h>
#include	<time.h>
#include	"ressources.h"
#include	"map.h"
#include	"team.h"
#include	"drone.h"

#ifndef		__ZAPPY_H__
#define		__ZAPPY_H__

#define FD_FREE	0
#define FD_SERV	1
#define FD_CLT	2
#define FD_DRN	2
#define NB_CLT	1024

#define	CLT_NO	0
#define	CLT_GRC	1
#define	CLT_IA	2
#define	CLT_DRN	3

#define	REQ_IA	0
#define	REQ_GRC	1

#define	GRAPHIC_TEAM	"GRAPHIC"

#define	BUFF_SIZE	1024

#define	USEC		1000000

#define	FOOD_TIME	126
#define	FOOD_DFL	10

#define	DIR_TOP		1
#define	DIR_RIGHT	2
#define	DIR_BOT		3
#define	DIR_LEFT	4

#define	BAD_PARAMETER	"sbp\n"
#define	BAD_CMD		"suc\n"

#define WIN_LIM_PLAY	6
#define MAX_LVL		8

#define	SUCCESS		0
#define	FAIL		1

typedef struct s_data	t_data;

typedef struct s_request	t_request;

typedef	struct	s_pos
{
  int		pos_x;
  int		pos_y;
  int		dir;
}		t_pos;

typedef struct	s_broad
{
  float		dist_simple;
  float		dist_trans;
  int		case_recep;
  int		case_recep_trans;
  int		case_recep_simple;
}		t_broad;

typedef	struct	s_fd
{
  int		type;
  int		status;
  void		(*func_read)(int, t_data *);
  void		(*func_write)(int, t_data *);
  char		*team;
  t_pierres	pierres;
  int		food;
  int		lvl;
  t_pos		pos;
  char		buf_r[BUFF_SIZE];
  char		buf_w[BUFF_SIZE];
  int		off_w;
  t_broad	*broad;
}		t_fd;

typedef struct	s_args
{
  int		port;
  int		sizeX;
  int		sizeY;
  int		nb_clients;
  int		act_time;
  char		**team_name;
}		t_args;

typedef	struct	s_drones
{
  t_drone	*drone;
  int		id_drone;
}		t_drones;

struct	s_data
{
  t_fd		*fd;
  t_drones	drones;
  int		maxfd;
  int	        max;
  t_request	*req;
  t_args	*args;
  t_box		*map;
  fd_set	fd_read;
  fd_set	fd_write;
  t_team_ref	*list_team;
};
typedef struct	s_cmd
{
  char		*cmd;
  int		time;
  void		(*ptr_func)(t_data *, int, int, char *);
  int		req;
  int		active;
}		t_cmd;

typedef struct	s_assign_stone
{
  char		*name;
  void		(*ptr)(t_data *, int);
}		t_assign_stone;

void		eparpille_stone(t_data *, int, int);
void		add_linemate(t_data *, int);
void		add_deraumere(t_data *, int);
void		add_sibur(t_data *, int);
void		add_mendiane(t_data *, int);
void		add_phiras(t_data *, int);
void		add_thystame(t_data *, int);

t_args		found_args(int, char **);
void		server_zappy(t_args);
void		select_func(t_data *, struct timeval *);
void		add_server(int, t_data *);
void		add_client(int, t_data *);
void		init_data(t_data *, t_args *);
void		put_team_list(t_data *);
int		team_check(t_data *, char *);
void            init_map(t_data *, t_args *);
void		select_clients(t_data *);
void		del_fd(t_data *, int);
void		printcs(t_data *, int, char *);
t_box           *getBox(t_data *, int , int );
int		check_free_space(t_data *);

void		exit_serv(int);
int		check_exit(int);
void		close_fd(t_data *);
int		check_valid_nb(char *);
void		add_ctl_team(t_data *, int, char *);
char		*str_fmt(const char *, ...);
int		rand_a_b(int , int);

void		add_drone(t_data *, int);
void		aff_drone(t_data *);
void		active_drone(t_data *, int);
t_drone		*getDrone(t_data *, int);
int		size_drone(t_data *);
void		drone_ajust_coord(t_data *, t_drone *);
int		drone_check(t_data *, char *);
void		drone_erase(t_data *, int);
int		drone_timeout(t_data *);
void		drone_food_dec(t_data *, int);

void		add_tab(int *, int);
void		add_tab_drone(int *, int);

int		check_elev(t_data *, int, int);

void		dec_team_lvl(t_data *, char *);
int		get_team_player_by_lvl(t_data *, char *, int);
void		set_nb_max_lvl_by_team(t_data *, char *, int);
int		check_end_game(t_data *);

#endif
