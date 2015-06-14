//
// Convstr.hpp for  in /home/basset_a//Test
//
// Made by antoine basset
// Login   <basset_a@epitech.net>
//
// Started on  Mon Jul  4 11:21:55 2011 antoine basset
// Last update Thu Jul  7 13:34:27 2011 antoine basset
//

#ifndef		_CONVSTR_HPP_
#define		_CONVSTR_HPP_

#include	<sstream>
#include	<iostream>
#include	<string>

template <typename T>
T		string_to_nb(std::string const & str)
{
  T			nb = 0;
  std::stringstream     Str;

  Str << str;
  if (Str)
    Str >> nb;
  return (nb);
}

template <typename T>
std::string		nb_to_string(T nb)
{
  std::ostringstream	tmp;

  tmp << nb;
  return (tmp.str());
}


#endif		/*_CONVSTR_HPP_*/
