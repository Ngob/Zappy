//
// incant.cpp for incant in /home/asan_i//svn/zappy/client_v3
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun 29 13:44:40 2011 inan asan
// Last update Sun Jul 10 14:42:48 2011 inan asan
//

#include	"client.hh"

void		Client::incant(std::vector<std::string> cmd)
{
  std::string	msg;

  if (cmd.size() >= 5)
    {
      msg = "Incantation at " + cmd[1] + "/" + cmd[2];
      this->Win->aff_msg(msg);
    }
}

void		Client::end_incant(std::vector<std::string> cmd)
{
  std::string	msg;

  if (cmd.size() == 4)
    {
      msg =  cmd[1] + "/" + cmd[2] + " incantation ok";
      this->Win->aff_msg(msg);
    }
}
