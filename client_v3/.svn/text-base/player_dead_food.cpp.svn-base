//
// player_dead_food.cpp for player dead food in /home/asan_i//svn/zappy/client_v3
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun 29 13:46:03 2011 inan asan
// Last update Fri Jul  8 22:00:34 2011 inan asan
//

#include	"client.hh"

void		Client::player_dead_food(std::vector<std::string> cmd)
{
  std::list<t_players>::iterator it;
  int				old_x;
  int				old_y;
  std::string			msg;

  if (cmd.size() == 2)
    {
      it = this->player.begin();
      for(unsigned int i = 0; i < this->player.size(); i++)
	{
	  if (atoi(cmd[1].c_str()) == it->id)
	    {
	      old_x = it->x;
	      old_y = it->y;
	      this->player.erase(it);
	      this->Win->refresh_screen(old_x, old_y, this->player, this->map, this->egg);
	      msg = "Player " + cmd[1] + " is dead";
	      this->Win->aff_msg(msg);
	      return;
	    }
	  it++;
	}
    }
}
