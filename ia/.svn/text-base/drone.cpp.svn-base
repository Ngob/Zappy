//
// drone.cpp for  in /home/ngo_b//rendu/proj/zappy/clientsrc
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Thu Jun  9 16:15:50 2011 benoit ngo
//

#include       	"drone.hh"
#include	<string>
#include	<vector>
#include	<iostream>
#define		MAX_LVL 4
#include <sstream>

requirLevel	secret;

void		Drone::find_item(const std::string & item,
				 s_case & cur_case)
{
  if (item == "joueur")
    cur_case.drone += 1;
  else if (item != "" && item != "\n")
    cur_case.content[item] += 1;
}

void		Drone::pars_itm(std::string str,
				std::vector<s_case> & to)
{
  std::string	item("");
  int		nb_case = 0;
  s_case       	cur_case;

  cur_case.init();
  if (str[0] == '{')
    str = str.substr(1);
  for (int i = 0; i < str.size() && str[i] != '}'; ++i)
    {
      item = "";
      for ( ; i < str.size() && str[i] != '{' && str[i] != ',' && str[i] != ' ' && str[i] != '}'; ++i)
	item += str[i];
      this->find_item(item, cur_case);
      if (str[i] == ',')
	{
	  to.push_back(cur_case);
	  cur_case.init();
	}
    }
  to.push_back(cur_case);
}

void		Drone::getSize(const std::string & str)
{

  std::string	x;
  int		i = 0;

  for (int i = 0; i < str.size(); ++i)
    {
      if (str[i] <= '9' && str[i] >= '0')
	x += str[i];
      else
	{
	  this->_max_size = this->max(this->_max_size,
				      ConvertToInt(x));
	  x = "";
	}
    }

}

void		Drone::elevation(bool f)
{
  if (secret.stone_for_lvl[this->_lvl + 1].content["drone"] != 1 && this->_mode == 0)
    {
      std::ostringstream oss;
      oss << this->_lvl + 1;
      this->buf_write += "broadcast " + this->_cl->_teamName +
	" request level: " + oss.str() + "\n";
    }
  if (f == false)
    for (std::map<std::string, int>::iterator it
	   = secret.stone_for_lvl[this->_lvl + 1]
	   .content.begin();
	 it != secret.stone_for_lvl[this->_lvl + 1]
	   .content.end();
	 ++it)
      {
	for (int i = 0; it->first != "nourriture"
	       && it->first != "drone"
	       && it->second - i > 0; ++i)
	  this->buf_write += "pose " + it->first + "\n";
	this->_invent.content[it->first] -= it->second;
      }
  this->buf_write += "incantation\n";
}

bool		Drone::do_broadcast(const std::string & s)
{
  std::string	str;
  std::string	nb;
  int		from;
  int		i = 0;;
  this->buf_write = "";
  for (i = 0; i < s.size() &&
	 s[i] != ' '; ++i);
  str = s.substr(i + 1);
  nb = str.substr(0, 1);
  str = str.substr(2);
  from = ConvertToInt(nb);
  if (str.find(this->_cl->_teamName) == std::string::npos)
    return (false);
  int		request_lvl;
  std::string	r_lvl;
  if ((request_lvl = str.find("request")) == std::string::npos)
    return (false);
  r_lvl = str.substr(request_lvl + 15, request_lvl + 16);
  str = str.substr(request_lvl + 14);
  request_lvl = ConvertToInt(r_lvl);
  if (request_lvl == this->_lvl + 1)
    this->_mode = from;
  else
    return (false);
  this->_distance_x = 0;
  this->_distance_y = 0;
  return (true);
}

void		Drone::search_left()
{

}

void		Drone::search_front()
{
  //int		 new_y = this->_distance_y + (this->_lvl * this->_sens_y);
  int		new_y = this->_distance_y + (1 * this->_sens_y);

  std::string	sens("");

  this->buf_write = "";
  if (this->buf_watch != "")
    {
      this->watch();
      this->buf_watch = "";
      return ;
    }
  if (new_y <= this->_max_size && new_y >= 0)
      this->_distance_y = new_y;
  else
    {
      int		new_x = this->_distance_x +
	1;
      if (new_x > this->_max_size || new_x < 0)
	{
	  this->buf_write += "droite\navance\ngauche\n";
	  this->_distance_x = 0;
	  this->_distance_y = 0;
	  this->_mode = 0;
	  return ;
	}
      if (this->_sens_y == 1)
	sens += "droite\n";
      else
	sens += "gauche\n";
      this->buf_write += sens;
      std::string	o;
      this->_distance_x = new_x;
      this->_sens_y *= -1;
      this->buf_write += "voir\n";
    }
  this->buf_write += "avance\n";
  this->buf_write += sens;
  this->buf_write += "voir\n";
}

void		Drone::search_drone()
{
  this->buf_write = "";
  if (this->_distance_x == 0 && this->_distance_y == 0)
    {
      if (this->_mode == 3 || this->_mode == 4)
	this->buf_write += "gauche\n";
      else if (this->_mode == 6 || this->_mode == 5)
	this->buf_write += "gauche\ngauche\n";
      else if (this->_mode == 7 || this->_mode == 8)
	this->buf_write += "droite\n";
    }
}

void		Drone::launch()
{
  int		a = 0;
  bool		check = false;
  this->_cl->nb_rec = 0;
  while (1)
    {
      if (this->_cl->do_select() == true)
	{
	  std::string str("");
	  this->_cl->read(str);
	  if (str == "BIENVENUE\n")
	    {
	      std::string	size;
	      this->_cl->write(this->_cl->_teamName + "\n");
	      str = "";
	      this->_cl->read(str);
	      this->_num = ConvertToInt(str);
	      str = "";
	      this->_cl->read(size);
	      this->getSize(size);
	      ++a;
	      this->_cl->nb_rec = 0;
	      this->_cl->nb_command_send = 0;
	    }
	  (this->*(assos_instruct[this->verif_str.verif_string(str)]))(str, check);
	}
    }
}


 int		Drone::avance_x(const int nb, std::string & str,
				const int y) const
{
  int		nb_mid = 0;
  int		x;
  int		real_x;

  for (int i = 0; i < y; ++i)
    {
      nb_mid += i * 2 + 1;
    }
  nb_mid += y;
  x = nb_mid - nb;
  real_x = x;
  if (x < 0)
    x *= -1;
  if (x == 0)
    return (0);
  for (int i = 0; i < x; ++i)
    str += "avance\n";
  return (real_x);
}

int		Drone::avance_y(const int nb,
				std::string & str) const
{
  int		y = 0;

  for (int i = 0; i < nb; ++i)
    {
      if (i > (y * 2))
	{
	  str += "avance\n";
	  ++y;
	}
    }
  return (y);
}

bool		Drone::check_inventory()
{
  bool		check = true;

  for (std::map<std::string, int>::iterator it =
	 this->_invent.content.begin();
       it != this->_invent.content.end(); ++it)
    {
      if (it->first != "drone" &&
	  it->first != "nourriture"
	  && it->second <= secret.stone_for_lvl[this->_lvl + 1].content[it->first])
	{
	  check = false;
	}
      if (it->first == "nourriture" && it->second < 10)
	check = false;
    }
  return (check);
}

bool		Drone::check_inventory(const std::string & s)
{
  for (int i = 0; i < s.size(); ++i)
    {
      std::string	item_nombre("");
      std::string	item;
      int		nombre;
      int		j;
      if (s[i] == ' ')
	++i;
      for (; i < s.size() && s[i] != ',' && s[i] != '[' &&
	     s[i] != ']' && s[i] != '\n'; ++i)
	{
	  item_nombre += s[i];
	}
      if (item_nombre != "")
	{
	  for (j = 0; j < item_nombre.size() &&
		 item_nombre[j] != ' '; ++j)
	    item += item_nombre[j];
	  nombre = ConvertToInt(item_nombre.substr(j));
	  this->_invent.content[item] = nombre;
	}
    }
  //exit(0);
  return (this->check_inventory());
}

void		Drone::take(s_case & cas)
{
  if (this->_lvl > 1 && cas.drone > 1)
    return ;
  if (cas.drone <= 1)
    {
      for (std::map<std::string,int>::iterator it = cas
	     .content.begin();
	   it != cas.content.end() && cas
	     .content.empty()!= true; ++it)
	for (int i = 0; it->second != 0 && it->first != ""
	       && it->second - i > 0; ++i)
	  {
	    if (it->first == "nourriture" ||
		this->_incant == true || this->_invent.content[it->first] < 8)
	    {
		this->buf_write += "prend " + it->first + "\n";
		this->_invent.content[it->first] += 1;
	    }
	  }
    }
}

bool		Drone::watch()
{
  std::vector<s_case>	vision;
  std::string		vis;

  this->pars_itm(this->buf_watch, vision);
  this->buf_watch = "";
  std::vector<s_case>::iterator it = vision.begin();
  if (vision.size() >= 1)
    {
      if (vision[0].isEmpty() != true)
  	{
  	  if (this->_mode != 0 && vision[0].drone > 1
  	      && vision[0].drone <= secret.stone_for_lvl[this->_lvl + 1].content["drone"])
  	    {
    	      this->buf_write = "";
  	      for (int i = 0; i < 43; ++i)
  		this->buf_write += "droite\n";
	      this->buf_watch = "";
  	      return (false);
  	    }
  	  if ((vision[0].drone == 1))
  	    this->take(vision[0]);
  	}
    }
  return (true);
}
int		Drone::max(const int x, const int y) const
{
  if (x > y)
    return (x);
  return (y);
}

bool		Drone::search_stand_stone()
{
  int		new_y = this->_distance_y + (this->_lvl * this->_sens_y);
  std::string	order("");
  std::string sens("");
  int		lvl = this->_lvl;

 this->_lvl = 1;
  if (this->buf_watch != "")
    {
      this->watch();
      this->buf_watch = "";
      this->_lvl = lvl;
      return (false);
    }
  this->buf_write = "";
  if (this->check_inventory() == true)
    {
      this->buf_write += "inventaire\n";
      this->_lvl = lvl;
      return (false);
    }
  if (new_y <= this->_max_size && new_y >= 0)
    {
      this->_distance_y += (this->_lvl * this->_sens_y);
    }
  else
    {
      int		new_x = this->_distance_x +
	this->_lvl;
      if (new_x > this->_max_size || new_x < 0)
	{
	  this->buf_write += "droite\navance\ngauche\n";
	  this->_distance_x = 0;
	  this->_distance_y = 0;
	  this->_lvl = lvl;
	  return (false);
	}
      if (this->_sens_y == 1)
	sens += "droite\n";
      else
	sens += "gauche\n";
      this->buf_write += sens;
      std::string	o;
      this->_distance_x = new_x;
      this->_sens_y *= -1;
      this->buf_write += "voir\n";
    }
  this->buf_write += "avance\n";
  this->buf_write += sens;
  this->buf_write += "voir\n";
  this->_lvl = lvl;
  return (true);
}


int		max(const int a, const int b)
{
  if (b > a)
    return (b);
  return (a);
}

void		Drone::instruct_lvlup(std::string & str, bool & check)
{
  (void) str;
  this->_lvl += 1;
 check = false;
 if (this->_mode != 0)
   --this->_cl->nb_rec;
 this->_mode = 0;
}

void		Drone::instruct_broadcast(std::string & str, bool & check)
{
  this->do_broadcast(str);
  this->_cl->nb_rec -= 1;
  check = false;
}

void		Drone::instruct_runElev(std::string & str, bool & check)
{
  this->_cl->nb_rec -= 1;
  check = false;
  this->_incant = false;
}

void		Drone::instruct_stand_mode()
{
  if (this->_cl->_buffer_write != "")
    this->_cl->write("");
  else
    {
      this->search_front();
      this->_cl->write(this->buf_write);
      this->buf_write = "";
    }
}

void		Drone::instruct_watch(std::string & str, bool & check)
{
  if (this->_cl->nb_command_send != this->_cl->nb_rec)
    return ;
  this->buf_watch = str;
  str = "ok\n";
  this->watch();
  this->_cl->_buffer_write = this->buf_write
    + this->_cl->_buffer_write;
  this->buf_write = "";
  this->_cl->write("");
}

void		Drone::instruct_ok(std::string & str, bool & check)
{
  (void) str;
  if (this->_cl->nb_command_send != this->_cl->nb_rec || this->_num == 0)
    return ;
  if (this->_mode != 0)
    {
      this->instruct_stand_mode();
    }
  else if (check == true)
    check = false;
  else
    {
      this->instruct_stand_search();
    }
}

void		Drone::instruct_ko(std::string & str, bool & check)
{
  (void) str;
  if (this->_cl->nb_command_send != this->_cl->nb_rec || this->_num == 0)
    return ;
  if (this->_mode != 0)
      this->instruct_stand_mode();
  else if (check == true)
      this->_cl->write("inventaire\n");
  else
      this->instruct_stand_search();
}

void		Drone::instruct_inventory(std::string & str, bool & check)
{
  if (this->_cl->nb_command_send != this->_cl->nb_rec)
    return ;
  (void) str;
  if (check == true)
    {
      if (this->check_inventory(str) == true)
	{
	  this->elevation(true);
	  this->_cl->write(this->buf_write);
	  this->buf_write = "";
	}
      else
	{
	  check = false;
	  this->_incant = false;
	}
    }
  else
    {
      if ((check = this->check_inventory(str)) == true)
	{
	  this->buf_write = "voir\n";
	  this->_incant = true;
	  this->elevation();
	}
      str = "";
      this->_cl->write(this->buf_write);
      this->buf_write = "";
    }
}

void		Drone::instruct_stand_search()
{
  if (this->_cl->_buffer_write != "")
    this->_cl->write("");
  else
    {
      this->search_stand_stone();
      this->_cl->write(this->buf_write);
      this->buf_write = "";
    }
}

Drone::~Drone()
{
}

Drone::Drone(Client * const cl):
  _incant(false), _max_size(0), _distance_x(0),
  _distance_y(0), _lvl(1), _sens_x(1), _sens_y(1), _num(0), _cl(cl),
  _mode(0)
{
  this->assos_instruct[INVENTORY] = &Drone::instruct_inventory;
  this->assos_instruct[WATCH] = &Drone::instruct_watch;
  this->assos_instruct[OK] = &Drone::instruct_ok;
  this->assos_instruct[KO] = &Drone::instruct_ko;
  this->assos_instruct[LVLUP] = &Drone::instruct_lvlup;
  this->assos_instruct[BROADCAST] = &Drone::instruct_broadcast;
  this->assos_instruct[RUN_ELEV] = &Drone::instruct_runElev;
}
