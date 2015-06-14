//
// current_time_unit.cpp for time unit in /home/asan_i//svn/zappy/client_v3
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun 29 13:48:09 2011 inan asan
// Last update Thu Jun 30 22:01:40 2011 inan asan
//

#include		"client.hh"

void		Client::current_time_unit(std::vector<std::string> cmd)
{
  if (cmd.size() == 2)
    this->_time_unit = atoi(cmd[1].c_str());
}
