/*
** check_cmd.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Tue Jun 21 11:08:43 2011 romain capot
** Last update Thu Jul  7 16:30:49 2011 romain capot
*/

#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"zappy.h"
#include	"request.h"
#include	"req_cmd.h"
#include	"broadcast.h"
#include	"x.h"

t_cmd		tab_cmd[] = {
  {"avance", 7, &req_avance, REQ_IA, -1},
  {"droite", 7, &req_droite, REQ_IA, -1},
  {"gauche", 7, &req_gauche, REQ_IA, -1},
  {"voir", 7, &req_voir, REQ_IA, -1},
  {"inventaire", 7, &req_inventaire, REQ_IA, -1},
  {"prend", 7, &req_prend, REQ_IA, -1},
  {"pose", 7, &req_pose, REQ_IA, -1},
  {"expulse", 7, &req_expulse, REQ_IA, -1},
  {"broadcast", 7, &req_broadcast, REQ_IA, -1},
  {"incantation", 0, &req_incantation_pre, REQ_IA, -1},
  {"fork", 0, &req_fork_pre, REQ_IA, -1},
  {"connect_nbr", 0, &req_connect_nbr, REQ_IA, -1},
  {"msz", 0, &req_msz, REQ_GRC, -1},
  {"bct", 0, &req_bct, REQ_GRC, -1},
  {"mct", 0, &req_mct, REQ_GRC, -1},
  {"ppo", 0, &req_ppo, REQ_GRC, -1},
  {"pin", 0, &req_pin, REQ_GRC, -1},
  {"plv", 0, &req_plv, REQ_GRC, -1},
  {"sgt", 0, &req_sgt, REQ_GRC, -1},
  {"sst", 0, &req_sst, REQ_GRC, -1},
  {"tna", 0, &req_tna, REQ_GRC, -1},
  {NULL, 0, NULL, 0, -1}
};

static void	send_fail(t_data *d, int fd)
{
  if (d->fd[fd].status == CLT_GRC)
    printcs(d, fd, BAD_CMD);
  else
    printcs(d, fd, "ko\n");
}

static void	add_req(t_data *d, int fd, char *cur_cmd, int i)
{
  if (tab_cmd[i].req == REQ_IA)
    {
      if (request_count(d, fd) < 10)
	request_add(d, &(tab_cmd[i]), fd, cur_cmd);
    }
  else if (tab_cmd[i].req == REQ_GRC)
    tab_cmd[i].ptr_func(d, fd, fd, cur_cmd);
}

void		check_cmd(t_data * d, int fd, char *cmd)
{
  char		*first_cmd;
  char		*cmd_cp;
  char		*cur_cmd;
  int		i;

  i = 0;
  cur_cmd = _X(NULL, (void *)strdup(cmd), "Strdup");
  if (strlen(cmd) >= 1)
    {
      cmd_cp = _X(NULL, (void *)strdup(cmd), "Strdup");
      if (cmd_cp && (first_cmd = strtok(cmd_cp, " ")))
	{
	  while (tab_cmd[i].cmd)
	    {
	      if (!strcmp(tab_cmd[i].cmd, first_cmd))
		{
		  add_req(d, fd, cur_cmd, i);
		  return ;
		}
	      ++i;
	    }
	  if (d->fd[fd].type == FD_CLT && d->fd[fd].status == CLT_GRC)
	    send_fail(d, fd);
	}
    }
}
