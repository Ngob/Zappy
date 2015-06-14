//
// s_stone.cpp for  in /home/ngo_b//rendu/proj/zappy/clientsrc/ia
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Mon Jul  4 14:39:42 2011 benoit ngo
// Last update Sat Jul  9 03:17:48 2011 benoit ngo
//

#include		"s_stone.hh"

s_stone::s_stone()
{
  this->content.clear();
  this->content["linemate"] = 0;
  this->content["deraumere"] = 0;
  this->content["sibur"] = 0;
  this->content["mendiane"] = 0;
  this->content["phiras"] = 0;
  this->content["thystame"] = 0;
  this->content["nourriture"] = 0;
  this->content["drone"] = 0;
}

bool		s_stone::operator<(const int & i)
{
  if (this->content["linemate"] < i &&
      this->content["deraumere"] < i &&
      this->content["sibur"] < i &&
      this->content["mendiane"] < i &&
      this->content["phiras"] < i &&
      this->content["thystame"] < i)
    return (true);
  return (false);
}
