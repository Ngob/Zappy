//
// s_stone.hh for  in /home/ngo_b//rendu/proj/zappy/clientsrc
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Tue Jun 14 14:24:41 2011 benoit ngo
// Last update Sat Jul  9 03:09:00 2011 benoit ngo
//

#ifndef		__STONE_HH__
# define	__STONE_HH__

# include	<map>
# include	<string>

struct		s_stone
{
  s_stone();
  std::map<std::string, int> content;
  bool		operator<(const int &);
};

#endif		/*__STONE_HH__*/
