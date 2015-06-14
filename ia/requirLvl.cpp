//
// requirLvl.cpp for  in /home/ngo_b//rendu/proj/zappy/clientsrc/ia
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Mon Jul  4 15:07:40 2011 benoit ngo
// Last update Tue Jul  5 16:35:30 2011 benoit ngo
//

#include	"requirLvl.hh"

requirLevel::requirLevel()
{
  s_stone		s;

  s.content["drone"] = 0;
  this->stone_for_lvl.resize(11, s);
  this->stone_for_lvl[2].content["linemate"] = 1;
  this->stone_for_lvl[2].content["deraumere"] = 0;
  this->stone_for_lvl[2].content["sibur"] = 0;
  this->stone_for_lvl[2].content["mendiane"] = 0;
  this->stone_for_lvl[2].content["phiras"] = 0;
  this->stone_for_lvl[2].content["thystame"] = 0;
  this->stone_for_lvl[2].content["drone"] = 1;

  this->stone_for_lvl[3].content["linemate"] = 1;
  this->stone_for_lvl[3].content["deraumere"] = 1;
  this->stone_for_lvl[3].content["sibur"] = 1;
  this->stone_for_lvl[3].content["mendiane"] = 0;
  this->stone_for_lvl[3].content["phiras"] = 0;
  this->stone_for_lvl[3].content["thystame"] = 0;
  this->stone_for_lvl[3].content["drone"] = 2;

  this->stone_for_lvl[4].content["linemate"] = 2;
  this->stone_for_lvl[4].content["deraumere"] = 0;
  this->stone_for_lvl[4].content["sibur"] = 1;
  this->stone_for_lvl[4].content["mendiane"] = 0;
  this->stone_for_lvl[4].content["phiras"] = 2;
  this->stone_for_lvl[4].content["thystame"] = 0;
  this->stone_for_lvl[4].content["drone"] = 2;

  this->stone_for_lvl[5].content["linemate"] = 1;
  this->stone_for_lvl[5].content["deraumere"] = 1;
  this->stone_for_lvl[5].content["sibur"] = 2;
  this->stone_for_lvl[5].content["mendiane"] = 0;
  this->stone_for_lvl[5].content["phiras"] = 1;
  this->stone_for_lvl[5].content["thystame"] = 0;
  this->stone_for_lvl[5].content["drone"] = 4;

this->stone_for_lvl[6].content["linemate"] = 1;
  this->stone_for_lvl[6].content["deraumere"] = 2;
  this->stone_for_lvl[6].content["sibur"] = 1;
  this->stone_for_lvl[6].content["mendiane"] = 3;
  this->stone_for_lvl[6].content["phiras"] = 0;
  this->stone_for_lvl[6].content["thystame"] = 0;
  this->stone_for_lvl[6].content["nourriture"] = 0;
  this->stone_for_lvl[6].content["drone"] = 4;

this->stone_for_lvl[7].content["linemate"] = 1;
  this->stone_for_lvl[7].content["deraumere"] = 2;
  this->stone_for_lvl[7].content["sibur"] = 3;
  this->stone_for_lvl[7].content["mendiane"] = 0;
  this->stone_for_lvl[7].content["phiras"] = 1;
  this->stone_for_lvl[7].content["thystame"] = 0;
  this->stone_for_lvl[7].content["drone"] = 6;

  this->stone_for_lvl[8].content["linemate"] = 2;
  this->stone_for_lvl[8].content["deraumere"] = 2;
  this->stone_for_lvl[8].content["sibur"] = 2;
  this->stone_for_lvl[8].content["mendiane"] = 2;
  this->stone_for_lvl[8].content["phiras"] = 2;
  this->stone_for_lvl[8].content["thystame"] = 1;
  this->stone_for_lvl[8].content["drone"] = 6;
}
