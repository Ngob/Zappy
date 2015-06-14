//
// main.cpp for  in /home/ngo_b//rendu/proj/zappy/clientsrc/ia
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Tue Jun 21 13:24:36 2011 benoit ngo
// Last update Sun Jul 10 18:55:00 2011 benoit ngo
//

#include	"client.hh"
#include	"drone.hh"
#include	<unistd.h>
#include	<stdio.h>
#include	<string>
#include	<iostream>
#include	"ConvertToInt.hh"

int		main(int ac, char **av)
{
  int		c;
  std::string  	tn("");
  std::string	ip = "127.0.0.1";
  std::string	port("");
  while ((c = getopt(ac, av, "n:p:h:")) != -1 && c != EOF)
    {
      switch (c)
	{
	case 'n':
	  tn = optarg;
	  break;
	case 'p':
	  port = optarg;
	  break;
	case 'h':
	  ip = optarg;
	  break;
	}
    }
  if (tn == "" || port == "")
    {
      std::cout << "Usage : -n TeamName -p Port -h Hostname" << std::endl;
      return (0);
    }
  std::cout << tn;
  std::cout << std::endl << port << std::endl << ip << std::endl;
  try
    {
      Client		* cl = new Client(ip, ConvertToInt(port), tn);
      try
	{
	  Drone			dr(cl);
	  dr.launch();
	}
      catch (std::exception exept_read)
	{
	  std::cout << "Game End" << std::endl;
	  delete cl;
	}
    }
  catch (std::exception exept_connect)
    {
      std::cerr << "Erreur de connection" << std::endl;
      return (0);
    }
  return (0);
}
