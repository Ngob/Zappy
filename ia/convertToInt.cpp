//
// convertToInt.cpp for  in /home/ngo_b//rendu/proj/zappy/clientsrc/ia
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Tue Jun 21 13:08:06 2011 benoit ngo
// Last update Tue Jun 21 13:55:10 2011 benoit ngo
//

#include	"ConvertToInt.hh"
#include	<iostream>
#include	<sstream>

int		ConvertToInt(const std::string & s)
{
  std::stringstream	ss;
  int		res;

  ss << s;
  ss >> res;
  return (res);
}
