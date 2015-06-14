//
// check_string.cpp for  in /home/ngo_b//rendu/proj/zappy/ia
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Sun Jul 10 14:36:55 2011 benoit ngo
// Last update Sun Jul 10 16:39:55 2011 benoit ngo
//

#include	"check_string.hh"

bool			check_string::verif_inventory(const std::string & str)
{
  if (str != "" && str[0] == '{')
    {
      for (int i = 0; i < str.size(); ++i)
	{
	  if (str[i] <= '9' && str[i] >= '0')
	    return (true);
	}
    }
  return (false);
}

bool			check_string::verif_watch(const std::string & str)
{
  if (str != "" && str[0] == '{')
    {
      for (int i = 0; i < str.size(); ++i)
	{
	  if (str[i] <= '9' && str[i] >= '0')
	    return (false);
	}
      return (true);
    }
  return (false);
}

bool			check_string::verif_ok(const std::string & str)
{
  return (str == "ok\n");
}

bool			check_string::verif_lvlup(const std::string & str)
{
  std::string		niveau("niveau");

  if (str != "" && str[0] == 'n')
    {
      for (int i = 0; i < str.size(); ++i)
	{
	  if (str[i] == 'u' && str.substr(0, i+1) == niveau)
	    return (true);
	}
    }
  return (false);
}

bool			check_string::verif_ko(const std::string & str)
{
  return (str == "ko\n");
}

bool			check_string::verif_broadcast(const std::string & str)
{
  std::string		broadcast("message");

  if (str != "" && str[0] == 'm')
    {
      for (int i = 0; i < str.size(); ++i)
	{
	  if (str[i] == 'e' && str.substr(0, i+1) == broadcast)
	    return (true);
	}
    }
  return (false);
}

bool			check_string::verif_runElev(const std::string & str)
{
  return (str == "elevation en cours\n");
}

typeString		check_string::verif_string(const std::string & str)
{
  for (std::map<typeString, bool (check_string::*)(const std::string &)>::iterator it =
	 this->assos_type_func.begin(); it != this->assos_type_func.end(); ++it)
    {
      if ((this->*(it->second))(str))
	return (it->first);
    }
  return (OK);
}

check_string::check_string()
{
  this->assos_type_func[INVENTORY] = &check_string::verif_inventory;
  this->assos_type_func[WATCH] = &check_string::verif_watch;
  this->assos_type_func[OK] = &check_string::verif_ok;
  this->assos_type_func[KO] = &check_string::verif_ko;
  this->assos_type_func[LVLUP] = &check_string::verif_lvlup;
  this->assos_type_func[BROADCAST] = &check_string::verif_broadcast;
  this->assos_type_func[RUN_ELEV] = &check_string::verif_runElev;
}
