//
// client.cpp for client in /home/asan_i//svn/zappy/clientsrc
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Wed Jun  8 14:05:19 2011 inan asan
// Last update Sun Jul 10 18:07:47 2011 chris chaulvet
//

#include	"client.hh"
#include	<iostream>
#include	<string>
#include	<fstream>

Client::Client(std::string ip, int port)
{
  this->pe = getprotobyname("TCP");
  this->_socket = socket(PF_INET, SOCK_STREAM, this->pe->p_proto);
  this->s.sin_family = AF_INET;
  this->s.sin_port = htons(port);
  this->s.sin_addr.s_addr = inet_addr(ip.c_str());
  if ((connect(_socket, (const struct sockaddr *)&s, sizeof(this->s))) == -1)
    {
      std::cerr << "Connect error" << std::endl;
      xclose(_socket);
      exit(EXIT_FAILURE);
    }
  this->_ip = ip;
  this->_port = port;

  this->cmds["msz"] = &Client::map_size;
  this->cmds["bct"] = &Client::get_block;
  this->cmds["tna"] = &Client::get_team_name;
  this->cmds["pnw"] = &Client::new_player;
  this->cmds["ppo"] = &Client::player_pos;
  this->cmds["plv"] = &Client::player_level;
  this->cmds["pin"] = &Client::player_bag;
  this->cmds["pex"] = &Client::eject_player;
  this->cmds["pbc"] = &Client::player_broadcast;
  this->cmds["pic"] = &Client::incant;
  this->cmds["pie"] = &Client::end_incant;
  this->cmds["pfk"] = &Client::player_egg;
  this->cmds["pdr"] = &Client::drop_ressource;
  this->cmds["pgt"] = &Client::take_ressource;
  this->cmds["pdi"] = &Client::player_dead_food;
  this->cmds["enw"] = &Client::egg_drop_by_player;
  this->cmds["eht"] = &Client::egg_done;
  this->cmds["ebo"] = &Client::player_connected_egg;
  this->cmds["edi"] = &Client::egg_dead_food;
  this->cmds["sgt"] = &Client::current_time_unit;
  this->cmds["seg"] = &Client::end_game;
  this->cmds["smg"] = &Client::server_msg;
  this->cmds["suc"] = &Client::unknown_cmd;
  this->cmds["sbp"] = &Client::bad_param;

  this->Win = new Graphic(1200,800);
  this->Win->App->Clear();
}

Client::~Client()
{
  delete this->Win;
}

int		Client::get_client_id() const
{
  return (this->_client_id);
}

int		Client::get_max_x() const
{
  return (this->_map_max_x);
}

int		Client::get_max_y() const
{
  return (this->_map_max_y);
}

void		Client::get_map_size(char *buffer)
{
  int			i;
  int			j;
  std::string	      	tmp;
  std::string  		tmp2;

  i = 0;
  j = 0;
  while (buffer[i] != ' ')
    tmp += buffer[i++];
  j = 0;
  this->_map_max_x = atoi(tmp.c_str());
  i++;
  while (buffer[i] != '\n')
    tmp2 += buffer[i++];
  this->_map_max_y = atoi(tmp2.c_str());
}

void		Client::check_cmd(std::string buffer)
{
  int		i = 0;
  std::string	s = "";
  t_data	*tmp;

  while (buffer[i] != 0)
    {
      tmp = new t_data;
      while (buffer[i])
	{
	  if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i])
	    s += buffer[i];
	  if (buffer[i] == ' ' || buffer[i] == '\n' || !buffer[i])
	    {
	      tmp->cmd.push_back(s);
	      s = "";
	      if (buffer[i] == '\n')
		break;
	    }
	  i++;
	}
      this->_cmd.push_back(*tmp);
      delete tmp;
      i++;
    }
}

int		check_param(std::string param)
{
  std::string	tab[24]  = {"msz", "bct", "tna", "pnw", "ppo", "plv",
			    "pin", "pex", "pbc", "pic", "pie", "pfk",
			    "pdr", "pgt", "pdi", "enw", "eht", "ebo",
			    "edi", "sgt", "seg", "smg", "suc", "sbp"};
  int		i;

  i = 0;
  while (i < 24)
    {
      if (tab[i] == param)
	return (1);
      i++;
    }
  return (0);
}

void		Client::client_loop(int w)
{
  std::list<t_data>::iterator it;
  char		buffer[4096];
  std::string	buf;
  int  		error;
  fd_set       	readfds;
  struct timeval tv;
  int		check = 0;
  
  error = 0;
  while (this->Win->getFlag() == true)
    {
      FD_ZERO(&readfds);
      FD_SET(this->_socket, &readfds);
      FD_SET(0, &readfds);
      tv.tv_sec = 0;
      tv.tv_usec = 100000;
      if ((error = select(6, &readfds, NULL, NULL, &tv)) != -1)
	{
	  if (FD_ISSET(this->_socket, &readfds))
	    {
	      bzero(buffer, 4095);
	      if (read(w, buffer, 4095) <= 0)
		exit(EXIT_FAILURE);
	      buf += buffer;
	    }
	  else
	    {
	      if (buf != "")
		{
		  this->check_cmd(buf);
		  it = this->_cmd.begin();
		  for(unsigned int i = 0; i < this->_cmd.size(); i++)
		    {
		      if (check_param(it->cmd[0]) == 1)
			(this->*cmds[it->cmd[0]])((*it).cmd);
		      it++;
		    }
		  this->_cmd.clear();
		  buf = "";

		}
	    }
	  this->Win->App->Display();
	  this->Win->setMapBlock(&(this->map));
	  this->Win->setPlayers(&(this->player));
	  this->Win->setEgg(&(this->egg));
	  this->Win->aff_ress(895, 0, *(this->Win->getInfo()));
	  this->Win->aff_msg("");
	  this->Win->input();
	  if (this->Win->clic == true)
	    this->Win->aff_info(NULL);
	  if (this->Win->move == true)
	    {
	      this->Win->move = false;
	      this->Win->App->Clear();
	      this->Win->refresh_screen2(this->player, this->map, this->egg);
	      this->Win->aff_ress(895, 0, *(this->Win->getInfo()));
	    }
	}

    }
  xclose(this->_socket);
}

void		Client::check_start_msg(int w, char* msg)
{
  if (strcmp(msg, "BIENVENUE\n") == 0)
    write(w, "GRAPHIC\n", 8);
  this->client_loop(w);
}

void		Client::do_op(int r, int w, int check)
{
  char 		buff[1024];

  bzero(buff, 1023);
  if (read(r, buff, 1023) <= 0)
    exit(EXIT_FAILURE);
  if (check == 1)
    {
     if (write(w, buff, strlen(buff)) <= 0)
	exit(EXIT_FAILURE);
    }
  else
    this->check_start_msg(r, buff);
  bzero(buff, 511);
}
