/*
** add_client.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 19:36:51 2011 romain capot
** Last update Sun Jul 10 19:36:52 2011 romain capot
*/

#include		<netinet/in.h>
#include		<string.h>
#include		<sys/socket.h>
#include		<stdio.h>
#include		"zappy.h"
#include		"client.h"
#include		"graphic_info.h"
#include		"x.h"

static void			init_client(t_data *d, int fd)
{
  d->fd[fd].pos.pos_x = rand_a_b(d->args->sizeX, 0);
  d->fd[fd].pos.pos_y = rand_a_b(d->args->sizeY, 0);
  new_connection(d, fd);
}

static void		init_infos_client(t_data *d, int cs)
{
  d->fd[cs].pierres.linemate = 0;
  d->fd[cs].pierres.deraumere = 0;
  d->fd[cs].pierres.sibur = 0;
  d->fd[cs].pierres.mendiane = 0;
  d->fd[cs].pierres.phiras = 0;
  d->fd[cs].pierres.thystame = 0;
  d->fd[cs].team = NULL;
  d->fd[cs].food = FOOD_TIME * USEC / d->args->act_time * FOOD_DFL;
  d->fd[cs].lvl = 1;
  d->fd[cs].pos.dir = DIR_BOT;
  _X(NULL, memset(d->fd[cs].buf_r, 0, BUFF_SIZE), "Memset");
  _X(NULL, memset(d->fd[cs].buf_w, 0, BUFF_SIZE), "Memset");
  init_client(d, cs);
}

void			add_client(int s, t_data *d)
{
  int			cs;
  struct sockaddr_in    client_sin;
  socklen_t             clt_len;

  clt_len = sizeof(client_sin);
  cs = (int)_X((void *)-1, (void *)accept(s, (struct sockaddr *)&client_sin,
					 &clt_len), "Accept");
  if (cs != -1)
    {
      d->fd[cs].type = FD_CLT;
      d->fd[cs].status = CLT_NO;
      d->fd[cs].func_read = client_read;
      d->fd[cs].func_write = client_write;
      init_infos_client(d, cs);
      printcs(d, cs, "BIENVENUE\n");
    }
}

void		new_connection(t_data *d, int fd)
{
  printf("%sNew player %d on (%d, %d)%s\n",
	 YELLOW, fd, d->fd[fd].pos.pos_x,
	 d->fd[fd].pos.pos_y, BASE);
}
