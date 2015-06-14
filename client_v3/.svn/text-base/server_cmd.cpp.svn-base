//
// server_cmd.cpp for server cmd in /home/asan_i//svn/zappy/client_v3
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun 29 13:47:01 2011 inan asan
// Last update Thu Jun 30 22:02:22 2011 inan asan
//

#include	"client.hh"

void		Client::server_msg(std::vector<std::string> cmd)
{
  if (cmd.size() == 2)
    std::cout << "Server said : " << cmd[1] << std::endl;
}

void		Client::unknown_cmd(std::vector<std::string> cmd)
{
  std::cout << "Unknown command received by server" << std::endl;
}

void		Client::bad_param(std::vector<std::string> cmd)
{
  std::cout << "Bad param received from server" << std::endl;
}
