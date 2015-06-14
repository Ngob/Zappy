//
// eject_player.cpp for eject player in /home/asan_i//svn/zappy/client_v3
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun 29 13:43:15 2011 inan asan
// Last update Sun Jul  3 22:27:16 2011 inan asan
//

#include	"client.hh"

void		Client::eject_player(std::vector<std::string> cmd)
{
  std::list<t_players>::iterator it;
  int				old_x;
  int				old_y;

  if (cmd.size() == 1)
    {
      it = this->player.begin();
      for(unsigned int i = 0; i < this->player.size(); i++)
	{
	  if (atoi(cmd[1].c_str()) == it->id)
	    {
	      old_x = it->x;
	      old_y = it->y;
	      std::cout << "Player " << it->id << " has been ejected" << std::endl;
	      this->player.erase(it);
	      this->Win->refresh_screen(old_x, old_y, this->player, this->map,this->egg);
	      return;
	    }
	  it++;
	}
    }
}
