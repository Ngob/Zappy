//
// client.hh for client header in /home/asan_i//svn/zappy/clientsrc
//
// Made by inan asan
// Login   <asan_i@epitech.net>
//
// Started on  Wed Jun  8 14:05:33 2011 inan asan
// Last update Sun Jul 10 18:58:36 2011 inan asan
//

#ifndef _CLIENT_HH_
# define _CLIENT_HH_

#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include <X11/Xlib.h>

#define CSIZE 53

static int const pixel_decal = 30;

typedef struct	t_egg
{
  int		id;
  int		x;
  int		y;
  int		player_id;
}		s_egg;

typedef struct	t_block
{
  int		x;
  int		y;
  int		food;
  int		linemate;
  int		deraumere;
  int		sibur;
  int		mendiane;
  int		phiras;
  int		thystame;
}		s_block;

typedef struct t_players
{
  int		id;
  int		x;
  int		y;
  int		orientation;
  int		level;
  std::string	team_name;
  t_block	*bag;
}		s_players;

void		xclose(int fd);

class			Graphic
{
public:
  int			_height;
  int			_width;
  int			_view_x;
  int			_view_y;
  bool			_flag;
  bool			move;
  int			aff_x_min;
  int			aff_y_min;
  int			_map_max_x;
  int			_map_max_y;
  bool			clic;
  sf::RenderWindow	*App;
  sf::Image		_linemate;
  sf::Image		_deraumere;
  sf::Image		_sibur;
  sf::Image		_mendiane;
  sf::Image		_phiras;
  sf::Image		_thystame;
  sf::Image		_food;
  sf::Image		_info;
  sf::Image		_floor;
  sf::Image		_p;
  
  std::list<t_block>	_map;
  std::list<t_players>	_players;
  std::list<t_egg>	_egg;

public:
  Graphic(int, int);
  ~Graphic();

public:
  sf::Image &		setImgPlayers(std::string &);
  void			getIt(int, int);
  void			setMapBlock(std::list<t_block> * map);
  void			setPlayers(std::list<t_players> * player);
  void			setEgg(std::list<t_egg> * egg);
  void			aff_ress(int, int, sf::Image);
  void			display(t_block*);
  void			check_event(sf::Event);
  void			display2(t_players*);
  void			display3(t_egg*);
  void			aff_info(t_block*);
  void			aff_team(std::vector<std::string>);
  void			aff_msg(std::string msg);
  void			refresh_screen(int x, int y, std::list<t_players> p, std::list<t_block>, std::list<t_egg>);
  void			refresh_screen2(std::list<t_players> p, std::list<t_block>, std::list<t_egg>);
  void			input();
  sf::RenderWindow *	getApp() const;
  bool			getFlag();
  sf::Image *		getInfo();

};

typedef struct		t_data
{
  std::vector<std::string> cmd;
}			s_data;

class			Client
{
  typedef		void (Client::*exec)(std::vector<std::string>);

private:
  int			_client_id;
  int			_map_max_x;
  int			_map_max_y;
  int			_time_unit;

public :
  Graphic		*Win;
  std::list<t_block>	map;
  std::list<t_players>	player;
  std::list<t_egg>	egg;
  std::list<t_data>	_cmd;
  struct sockaddr_in	s;
  struct protoent	*pe;
  std::string		_ip;
  int			_port;
  int			_socket;
  std::map<std::string, exec>	cmds;
  std::vector<std::string>	teams;

public :

  Client(std::string ip, int port);
  ~Client();

public :
  int			get_client_id() const;
  int			get_max_x() const;
  int			get_max_y() const;

public :
  void			erase_cmd_list();
  void			check_cmd(std::string);
  void			client_loop(int);
  void			get_full_map();
  void			get_map_size(char* buffer);
  void			check_start_msg(int, char*);
  t_block*		cut_block_line(char* line);

public:
  void		do_op(int, int, int);
  void		map_size(std::vector<std::string>);
  void		get_block(std::vector<std::string>);
  void		get_team_name(std::vector<std::string>);
  void		new_player(std::vector<std::string>);
  void		player_pos(std::vector<std::string>);
  void		player_level(std::vector<std::string>);
  void		player_bag(std::vector<std::string>);
  void		eject_player(std::vector<std::string>);
  void		player_broadcast(std::vector<std::string>);
  void		incant(std::vector<std::string>);
  void		end_incant(std::vector<std::string>);
  void		player_egg(std::vector<std::string>);
  void		drop_ressource(std::vector<std::string>);
  void		take_ressource(std::vector<std::string>);
  void		player_dead_food(std::vector<std::string>);
  void		egg_drop_by_player(std::vector<std::string>);
  void		egg_done(std::vector<std::string>);
  void		player_connected_egg(std::vector<std::string>);
  void		egg_dead_food(std::vector<std::string>);
  void		current_time_unit(std::vector<std::string>);
  void		end_game(std::vector<std::string>);
  void		server_msg(std::vector<std::string>);
  void		unknown_cmd(std::vector<std::string>);
  void		bad_param(std::vector<std::string>);
};

#endif
