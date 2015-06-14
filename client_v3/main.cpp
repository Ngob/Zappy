//
// main.cpp for main cpp client in /home/asan_i//svn/zappy/clientsrc
//
// Made by inan asan
// Login   <asan_i@epitech.net>
//
// Started on  Wed Jun  8 14:16:55 2011 inan asan
// Last update Sun Jul 10 19:02:07 2011 inan asan
//

#include	"client.hh"
#include	"Convstr.hpp"

int		check_args(char **args, int ac)
{
  int		port;
  std::string	ip;
  int		i;
  int		error;

  ip = "127.0.0.1";
  i = 0;
  error = 0;
  while (i != ac)
    {
      if (strcmp(args[i], "-p") == 0)
	{
	  port = atoi(args[i + 1]);
	  error++;
	}
      else if (strcmp(args[i], "-h") == 0)
	ip = args[i + 1];
      i++;
    }
  if (error == 1)
    {
      Client	client(ip, port);

      client.do_op(client._socket,1 ,0);
    }
  return (-1);
}

int		main(int ac, char **av)
{
  int				error;
  Display *dpy;

  error = 0;
  dpy = XOpenDisplay(NULL);
  if (dpy == NULL)
    return (0);
  else
    XCloseDisplay(dpy);
  if (ac == 3 || ac == 5)
    error = check_args(av, ac);
  else if (error == -1 || ac != 3 || ac != 5)
    std::cerr << "./client\n\t[-p port] \n\t[-h nom_machine, localhost par defaut]" << std::endl;
  return (0);
}
