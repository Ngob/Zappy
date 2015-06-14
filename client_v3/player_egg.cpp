//
// player_egg.cpp for player egg in /home/asan_i//svn/zappy/client_v3
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun 29 13:45:07 2011 inan asan
// Last update Tue Jul  5 14:08:46 2011 inan asan
//

#include	"client.hh"

void		Client::player_egg(std::vector<std::string> cmd)
{
}

void		Client::egg_drop_by_player(std::vector<std::string> cmd)
{
  t_egg		*tmp = new t_egg;
  std::string	msg;

  if (cmd.size() == 5)
    {
      tmp->id = atoi(cmd[1].c_str());
      tmp->player_id = atoi(cmd[2].c_str());
      tmp->x = atoi(cmd[3].c_str());
      tmp->y = atoi(cmd[4].c_str());
      this->egg.push_back(*tmp);
      this->Win->display3(tmp);
      msg = "Egg dropped by player " + cmd[2];
      this->Win->refresh_screen(tmp->x, tmp->y, this->player, this->map, this->egg);
      this->Win->aff_msg(msg);
    }
}

void		Client::egg_done(std::vector<std::string> cmd)
{
  std::string	msg;

  if (cmd.size() == 2)
    {
      msg = "Egg " + cmd[1] + " done";
      this->Win->aff_msg(msg);
    }
}

void		Client::egg_dead_food(std::vector<std::string> cmd)
{
  std::list<t_egg>::iterator	it;
  std::string			msg;
  int				old_x;
  int				old_y;

  if (cmd.size() == 2)
    {
      it = this->egg.begin();
      for(unsigned int i = 0; i < egg.size(); i++)
	{
	  if (it->id == atoi(cmd[1].c_str()))
	    {
	      old_x = it->x;
	      old_y = it->y;
	      this->egg.erase(it);
	      this->Win->refresh_screen(old_x, old_y, this->player, this->map, this->egg);
	      return;
	    }
	  it++;
	}
      msg = "Egg " + cmd[1] + " is dead";
      this->Win->aff_msg(msg);
    }
}

void		Client::player_connected_egg(std::vector<std::string> cmd)
{
  std::list<t_egg>::iterator	it;
  std::string			msg;

  if (cmd.size() == 2)
    {
      it = this->egg.begin();
      for(unsigned int i = 0; i < egg.size(); i++)
	{
	  if (it->id == atoi(cmd[1].c_str()))
	    {
	      this->egg.erase(it);
	      msg = "A player is connected on egg " + cmd[1];
	      this->Win->aff_msg(msg);
	      return;
	    }
	  it++;
	}
    }
}
