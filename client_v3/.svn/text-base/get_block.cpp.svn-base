//
// get_block.cpp for get_block in /home/asan_i//svn/zappy/client_v3
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun 29 13:40:01 2011 inan asan
// Last update Mon Jul  4 15:24:54 2011 inan asan
//

#include	"client.hh"

void		Client::get_block(std::vector<std::string> cmd)
{
  t_block*	tmp = new t_block;
  std::list<t_block>::iterator it;
  int		i;

  if (cmd.size() == 10)
    {
      it = this->map.begin();
      for(unsigned int i = 0; i < this->map.size(); i++)
	{
	  if ((atoi(cmd[1].c_str()) == it->x) && (atoi(cmd[2].c_str()) == it->y))
	    {
	      it->food = atoi(cmd[3].c_str());
	      it->linemate = atoi(cmd[4].c_str());
	      it->deraumere = atoi(cmd[5].c_str());
	      it->sibur = atoi(cmd[6].c_str());
	      it->mendiane = atoi(cmd[7].c_str());
	      it->phiras = atoi(cmd[8].c_str());
	      it->thystame = atoi(cmd[9].c_str());
	      return;
	    }
	  it++;
	}
      tmp->x = atoi(cmd[1].c_str());
      tmp->y = atoi(cmd[2].c_str());
      tmp->food = atoi(cmd[3].c_str());
      tmp->linemate = atoi(cmd[4].c_str());
      tmp->deraumere = atoi(cmd[5].c_str());
      tmp->sibur = atoi(cmd[6].c_str());
      tmp->mendiane = atoi(cmd[7].c_str());
      tmp->phiras = atoi(cmd[8].c_str());
      tmp->thystame = atoi(cmd[9].c_str());
      
      this->map.push_back(*tmp);      
      this->Win->display(tmp);
    }
}
