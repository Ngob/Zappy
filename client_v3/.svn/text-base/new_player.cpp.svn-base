//
// new_player.cpp for new player in /home/asan_i//svn/zappy/client_v3
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun 29 13:41:05 2011 inan asan
// Last update Sun Jul 10 14:42:49 2011 inan asan
//

#include	"client.hh"

void		Client::new_player(std::vector<std::string> cmd)
{
  t_players	*tmp = new t_players;
  std::string	msg;

  if (cmd.size() == 7)
    {
      tmp->id = atoi(cmd[1].c_str());
      tmp->x = atoi(cmd[2].c_str());
      tmp->y = atoi(cmd[3].c_str());
      tmp->orientation = atoi(cmd[4].c_str());
      tmp->level = atoi(cmd[5].c_str());
      tmp->team_name = cmd[6];
      msg =  "Player " + cmd[1] + " is now connected";
      this->Win->aff_msg(msg);
      this->player.push_back(*tmp);
      this->Win->display2(tmp);
    }
}
