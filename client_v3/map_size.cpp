//
// map_size.cpp for map size in /home/asan_i//svn/zappy/client_v3
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun 29 13:39:31 2011 inan asan
// Last update Sun Jul 10 12:40:49 2011 inan asan
//

#include	"client.hh"

void		Client::map_size(std::vector<std::string> cmd)
{
  if (cmd.size() == 3)
    {
      this->_map_max_x = atoi(cmd[1].c_str());
      this->_map_max_y = atoi(cmd[2].c_str());
      this->Win->_map_max_x = this->_map_max_x;
      this->Win->_map_max_y = this->_map_max_y;
    }
}
