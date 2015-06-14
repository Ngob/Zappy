//
// epur_str.cpp for  in /home/ngo_b//rendu/proj/zappy/clientsrc/ia
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Tue Jun 28 16:45:20 2011 benoit ngo
// Last update Wed Jun 29 15:23:47 2011 benoit ngo
//

#include	"epur_str.hh"

void		epur_str(std::string & str)
{
  for (int i = 0; i < str.size(); ++i)
    {
      if ((str[i] == ' ' && (i + 1 == str.size() || i == 0)) ||
	  (i + 1 < str.size() && str[i] == ' ' && str[i + 1] == ' '))
	{
	  str.erase(i, i + 1);
	  i = 0;
	}
    }
}

void		fill_endl(std::string & str)
{
 for (int i = 0; i < str.size(); ++i)
    {
      if (str[i] == ' ')
	str[i] = '\n';
    }
}
