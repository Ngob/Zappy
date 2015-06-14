/*
** func_cmd.h for  in /home/capot_r//public/irc
**
** Made by romain capot
** Login   <capot_r@epitech.net>
**
** Started on  Mon Apr 18 14:18:11 2011 romain capot
** Last update Thu Jun 23 10:32:09 2011 romain capot
*/

#ifndef		__REQ_CMD_H__
#define		__REQ_CMD_H__

#define	SEND_DR	0
#define	SEND_PL	1

typedef struct	s_gest_obj
{
  char		*obj;
  int		(*ptr_func)(t_data *, int);
  int		obj_id;
}		t_gest_obj;

char		*find_obj_at_pos(t_data *, int, int);
char		*add_str(char *, char *, char);
void		check_cmd(t_data *, int, char *);
char		*catch_arg(char *, int);

void		ajust_coord(t_data *, int);

void		req_plv(t_data *, int, int, char *);
void		req_plv_drone(t_data *, int, int, char *);
void		req_ppo(t_data *, int, int, char *);
void		req_ppo_drone(t_data *, int, int, char *);
void		req_pin(t_data *, int, int, char *);
void		do_pin(t_data *, int, int, int);
void		req_add_grc(t_data *, int, int, char *);
void		req_add_ia(t_data *, int, int, char *);
void		req_add_ia_drone(t_data *, int, int, char *);
void		req_voir(t_data *, int, int, char *);
void		req_avance(t_data *, int, int, char *);
void		req_droite(t_data *, int, int, char *);
void		req_gauche(t_data *, int, int, char *);
void		req_inventaire(t_data *, int, int, char *);
void		req_incantation(t_data *, int, int, char *);
void		req_incantation_pre(t_data *, int, int, char *);
void		req_prend(t_data *, int, int, char *);
void		req_pose(t_data *, int, int, char *);
void		req_expulse(t_data *, int, int, char *);
void		req_fork_pre(t_data *, int, int, char *);
void		req_fork(t_data *, int, int, char *);
void		req_fork_eclos(t_data *, int, int, char *);
void		req_connect_nbr(t_data *, int, int, char *);
void		req_msz(t_data *, int, int, char *);
void		req_bct(t_data *, int, int, char *);
void		do_bct(t_data *, int, int, t_pos *);
void		req_tna(t_data *, int, int, char *);
void		do_tna(t_data *, int, int, char *);
void		req_mct(t_data *, int, int, char *);
void		req_pnw(t_data *, int, int, char *);
void		req_seg(t_data *, int, int, char *);
void		req_sgt(t_data *, int, int, char *);
void		req_sst(t_data *, int, int, char *);
void		req_smg(t_data *, int, int, char *);
void		req_pex(t_data *, int, int, char *);
void		req_pbc(t_data *, int, int, char *);
void		req_pdi(t_data *, int, int, char *);
void		req_edi(t_data *, int, int, char *);
void		req_ebo(t_data *, int, int, char *);
void		req_eht(t_data *, int, int, char *);
void		req_enw(t_data *, int, int, char *);
void		req_pie(t_data *, int, int, char *);
void		req_pic(t_data *, int, int, char *);
void		req_pgt(t_data *, int, int, char *);
void		req_pfk(t_data *, int, int, char *);
void		req_pdr(t_data *, int, int, char *);

#endif
