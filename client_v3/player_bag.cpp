//
// player_bag.cpp for player bag in /home/asan_i//svn/zappy/client_v3
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun 29 13:42:36 2011 inan asan
// Last update Sun Jul  3 22:21:06 2011 inan asan
//

#include	"client.hh"

void		Client::player_bag(std::vector<std::string> cmd)
{
  std::list<t_players>::iterator it;

    if (cmd.size() == 11)
    {
      it = this->player.begin();
      for(unsigned int i = 0; i < this->player.size(); i++)
	{
	  if (atoi(cmd[1].c_str()) == it->id)
	    {
	      it->x = atoi(cmd[2].c_str());
	      it->y = atoi(cmd[3].c_str());
	      it->bag = new t_block;
	      it->bag->x = 0;
	      it->bag->y = 0;
	      it->bag->food = atoi(cmd[4].c_str());
	      it->bag->linemate = atoi(cmd[5].c_str());
	      it->bag->deraumere = atoi(cmd[6].c_str());
	      it->bag->sibur = atoi(cmd[7].c_str());
	      it->bag->mendiane = atoi(cmd[8].c_str());
	      it->bag->phiras = atoi(cmd[9].c_str());
	      it->bag->thystame = atoi(cmd[10].c_str());
	      return;
	    }
	  it++;
	}
    }
}
