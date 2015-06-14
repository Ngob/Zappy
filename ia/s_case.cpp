//
// s_case.cpp for  in /home/ngo_b//rendu/proj/zappy/clientsrc/ia
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Tue Jun 21 14:43:44 2011 benoit ngo
// Last update Sun Jul 10 20:09:14 2011 benoit ngo
//

#include "s_case.hh"

void		s_case::init()
{
  this->drone = 0;
  this->content.clear();
  this->content["linemate"] = 0;
  this->content["deraumere"] = 0;
  this->content["sibur"] = 0;
  this->content["mendiane"] = 0;
  this->content["phiras"] = 0;
  this->content["thystame"] = 0;
  this->content["nourriture"] = 0;

}

bool		s_case::isEmpty()
{
  if (this->content["linemate"] == 0 &&
      this->content["deraumere"] == 0 &&
      this->content["sibur"] == 0 &&
      this->content["mendiane"] == 0 &&
      this->content["phiras"] == 0 &&
      this->content["thystame"] == 0 &&
      this->content["nourriture"] == 0)
    return (true);
  return (false);
}
