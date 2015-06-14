/*
** broadcast.h for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 13:25:54 2011 romain capot
** Last update Sun Jul 10 13:25:55 2011 romain capot
*/

#ifndef		__BROADCAST_H__
#define		__BROADCAST_H__

#include	<math.h>
#include	"zappy.h"
#include	"check_case.h"
#include	"check_direction.h"
#include	"check_way.h"
#include	"x.h"

typedef struct	s_case
{
  int		dir;
  int		x;
  int		y;
  int		nb;
}		t_case;

void		req_broadcast(t_data *, int, int, char *);
void		broad_grc(t_data *, int, char *);
float		count_dist(float, float, float, float);
int		def_direct(int, int, int);
char		*erase_broad(char *);

#endif
