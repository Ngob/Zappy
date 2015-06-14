//
// drone.hh for  in /home/ngo_b//rendu/proj/zappy/clientsrc
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Thu Jun  9 15:56:48 2011 benoit ngo
// Last update Sun Jul 10 16:28:57 2011 benoit ngo
//

#ifndef		__DRONE_HH__
# define	__DRONE_HH__

# include	"s_lin_func.hh"
# include	"s_stone.hh"
# include	"s_case.hh"
# include	"client.hh"
# include	"requirLvl.hh"
# include	"check_string.hh"

typedef s_stone s_inventory;

class		Drone
{
  bool		_incant;
  int		_max_size;
  int		_distance_x;
  int		_distance_y;
  int		_lvl;
  int		_sens_x;
  int		_sens_y;
  s_inventory	_invent;
  int		_num;
  Client * const _cl;
  std::string	buf_write;
  std::string	buf_watch;
  int		_mode;

  bool		search_stand_stone();
  bool		watch();
  // bool		search_stone(s_lin_func f_max, s_lin_func f_min,
  // 			     int);
  int		max(const int, const int) const;
  int		avance_x(const int, std::string &, const int) const;
  int		avance_y(const int, std::string &) const;

  std::map<typeString, void (Drone::*)(std::string &,
				       bool &)>	assos_instruct;

  check_string	verif_str;

public:
  Drone(Client * const);
  ~Drone();
  void		launch();
  void		getSize(const std::string &);
  void		take(s_case &);
  void		pars_itm(std::string, std::vector<s_case> &);
  void		find_item(const std::string &, s_case &);
  bool		check_inventory();
  bool		check_inventory(const std::string &);
  void		elevation(bool f = false);
  void		search_front();
  bool		do_broadcast(const std::string &);
  void		search_drone();
  void		search_left();

  void		instruct_lvlup(std::string &, bool &);
  void		instruct_broadcast(std::string &, bool &);
  void		instruct_runElev(std::string &, bool &);
  void		instruct_stand_mode();
  void		instruct_stand_search();
  void		instruct_watch(std::string &, bool &);
  void		instruct_ok(std::string &, bool &);
  void		instruct_ko(std::string &, bool &);
  void		instruct_inventory(std::string &, bool &);
};

#endif		/*__DRONE_HH__*/
