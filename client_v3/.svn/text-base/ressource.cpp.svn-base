//
// ressource.cpp for ressources in /home/asan_i//svn/zappy/client_v3
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun 29 13:45:32 2011 inan asan
// Last update Tue Jul  5 14:23:12 2011 inan asan
//

#include	"client.hh"

void		Client::drop_ressource(std::vector<std::string> cmd)
{
  std::string			msg;
  std::list<t_players>::iterator it;

  if (cmd.size() == 2)
    {
      msg = "Player " + cmd[1] + " drop ressource " + cmd[2];
      it = this->player.begin();
      for(unsigned int i = 0; i < this->player.size(); i++)
	{
	  if (atoi(cmd[1].c_str()) == it->id)
	    {
	      this->Win->refresh_screen(it->x, it->y, this->player, this->map, this->egg);
	      return;
	    }
	}
      this->Win->aff_msg(msg);
    }
}

void		Client::take_ressource(std::vector<std::string> cmd)
{
  std::string			msg;
  std::list<t_players>::iterator it;

  if (cmd.size() == 2)
    {
      msg = "Player " + cmd[1] + " take ressource " + cmd[2];
      it = this->player.begin();
      for(unsigned int i = 0; i < this->player.size(); i++)
	{
	  if (atoi(cmd[1].c_str()) == it->id)
	    {
	      this->Win->refresh_screen(it->x, it->y, this->player, this->map, this->egg);
	      return;
	    }
	}
      this->Win->aff_msg(msg);
    }
}
