/*
** graphic_info.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Sun Jul 10 19:35:17 2011 romain capot
** Last update Sun Jul 10 19:36:56 2011 romain capot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"zappy.h"
#include	"graphic_info.h"
#include	"x.h"

void		printConfig(t_args *args)
{
  printf("%sConfiguration : Max(%d) WoldX(%d) WorldY(%d) T(%d)%s\n",
	 GREEN, args->nb_clients, args->sizeX, args->sizeY,
	 args->act_time, BASE);
}

static char	*remove_retchar(char *str, char *token, char rem)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (str[i] != '\0')
    {
      j = 0;
      while (token[j] != '\0')
	{
	  if (str[i] == token[j])
	    {
	      if (str[i + 1] == '\0')
		str[i] = '\0';
	      else
		str[i] = rem;
	    }
	  j++;
	}
      ++i;
    }
  return (str);
}

void		received_message(char *s, int fd)
{
  char		*str;

  str = _X(NULL, strdup(s), "strdup");
  if (str)
    {
      str = remove_retchar(str, "\r", '\0');
      str = remove_retchar(str, "\n", '|');
      printf("\n%sReceiving message from player n°%d \"%s\" %s\n",
	     RED, fd, str, BASE);
      free(str);
    }
}

void		sending_message(char *s, int fd)
{
  char		*str;

  str = _X(NULL, strdup(s), "strdup");
  if (str)
    {
      str = remove_retchar(str, "\n\r", '\0');
      printf("%sSending message to player n°%d \"%s\" %s\n",
	     BLUE, fd, str, BASE);
      free(str);
    }
}
