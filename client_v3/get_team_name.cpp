//
// get_team_name.cpp for get team name in /home/asan_i//svn/zappy/client_v3
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun 29 13:40:36 2011 inan asan
// Last update Sun Jul  3 23:35:46 2011 inan asan
//

#include	"client.hh"

void		Client::get_team_name(std::vector<std::string> cmd)
{
  int		i;

  i = 1;
  if (cmd.size() > 1)
    {
      while (i < cmd.size())
	{
	  this->teams.push_back(cmd[i]);
	  i++;
	}
    }
}
