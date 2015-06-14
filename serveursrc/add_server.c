/*
** add_server.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Tue Jun 21 11:06:39 2011 romain capot
** Last update Tue Jun 28 14:30:44 2011 romain capot
*/

#include		<netinet/in.h>
#include		<stdio.h>
#include		<string.h>
#include		<errno.h>
#include		<netdb.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		"zappy.h"
#include		"x.h"

void			add_server(int port, t_data *d)
{
  int			s;
  struct sockaddr_in    sin;
  struct protoent	*type;

  type = (struct protoent *)X((void *)NULL,
			      (void *)getprotobyname("TCP"), "getprotobyname");
  s = (int)X((void *)-1, (void *)socket(PF_INET, SOCK_STREAM, type->p_proto),
	     "Socket");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  X((void *)-1, (void *)bind(s, (struct sockaddr*)&sin, sizeof(sin)), "Bind");
  X((void *)-1, (void *)listen(s, NB_CLT), "Listen");
  d->fd[s].type = FD_SERV;
  d->fd[s].func_read = add_client;
  d->fd[s].func_write = NULL;
}
