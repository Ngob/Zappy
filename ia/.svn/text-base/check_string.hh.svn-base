//
// check_string.hh for  in /home/ngo_b//rendu/proj/zappy/ia
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Sun Jul 10 14:26:52 2011 benoit ngo
// Last update Sun Jul 10 15:20:35 2011 benoit ngo
//

#ifndef		__CHECK_STRING_HH__
# define	__CHECK_STRING_HH__

# include	<map>
# include	<string>

enum		typeString
  {
    INVENTORY,
    WATCH,
    OK,
    KO,
    LVLUP,
    BROADCAST,
    RUN_ELEV
  };

class		check_string
{
private:
  bool		verif_runElev(const std::string &);
  bool		verif_broadcast(const std::string &);
  bool		verif_ko(const std::string &);
  bool		verif_ok(const std::string &);
  bool		verif_lvlup(const std::string &);
  bool		verif_watch(const std::string &);
  bool		verif_inventory(const std::string &);

  std::map<typeString,
	   bool (check_string::*)(const std::string &)> assos_type_func;

public:
  check_string();
  typeString	verif_string(const std::string &);
};

#endif		/*__CHECK_STRING_HH__*/
