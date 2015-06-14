//
// ExecpZappy.hpp for  in /home/basset_a//workspace/zappy/client_v3
//
// Made by antoine basset
// Login   <basset_a@epitech.net>
//
// Started on  Mon Jul  4 11:01:32 2011 antoine basset
// Last update Mon Jul  4 11:07:39 2011 antoine basset
//

#ifndef		_EXECPZAPPY_HPP_
#define		_EXECPZAPPY_HPP_

#include	<iostream>
#include	<string>
#include	<sstream>
#include	<stdexcept>

class ExecpZappy : public std::exection
{
public :

  ExecpZappy(const char * Msg)
  {
    std::ostringstream oss;
    oss << Msg;
    this->_msg = oss.str();
  }

  ExecpZappy(std::string const & Msg)
  {
    std::ostringstream oss;
    oss << Msg;
    this->_msg = oss.str();
  }

  virtual ~ExecpZappy() throw() {}

  virtual const char * What() const throw()
  {
    return this->_msg.c_str();
  }

private :

  std::string		_msg;

};

#endif		/*_EXECPZAPPY_HPP_*/
