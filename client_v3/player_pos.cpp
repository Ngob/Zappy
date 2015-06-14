//
// player_pos.cpp for player_pos in /home/asan_i//svn/zappy/client_v3
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun 29 13:41:25 2011 inan asan
// Last update Sun Jul 10 12:25:15 2011 inan asan
//

#include	"client.hh"

void		Client::player_pos(std::vector<std::string> cmd)
{
  std::list<t_players>::iterator it;
  int				old_x;
  int				old_y;
  std::string			msg;

  if (cmd.size()== 5)
    {
      it = this->player.begin();
      for(unsigned int i = 0; i < this->player.size(); i++)
	{
	  if (atoi(cmd[1].c_str()) == it->id)
	    {
	      old_x = it->x;
	      old_y = it->y;
	      it->x = atoi(cmd[2].c_str());
	      it->y = atoi(cmd[3].c_str());
	      it->orientation = atoi(cmd[4].c_str());
	      this->Win->refresh_screen(it->x, it->y, this->player, this->map, this->egg);
	      this->Win->refresh_screen(old_x, old_y, this->player, this->map, this->egg);
	      msg = "Player " + cmd[1] + " moved to " + cmd[2] + "/" + cmd[3];
	      this->Win->aff_msg(msg);
	      this->Win->App->Display();
	      return;
	    }
	  it++;
	}
    }
}
