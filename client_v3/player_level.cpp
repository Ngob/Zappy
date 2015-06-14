//
// player_level.cpp for player lvl in /home/asan_i//svn/zappy/client_v3
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun 29 13:42:11 2011 inan asan
// Last update Mon Jul  4 15:24:53 2011 inan asan
//

#include	"client.hh"

void		Client::player_level(std::vector<std::string> cmd)
{
  std::list<t_players>::iterator it;

  if (cmd.size()== 3)
    {
      it = this->player.begin();
      for(unsigned int i = 0; i < this->player.size(); i++)
	{
	  if (atoi(cmd[1].c_str()) == it->id)
	    {
	      it->level = atoi(cmd[2].c_str());
	      return;
	    }
	  it++;
	}
    }
}
