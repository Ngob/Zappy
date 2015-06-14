//
// exept_connect.hpp for exept in /home/ngo_b//rendu/proj/zappy/ia
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Sun Jul 10 18:15:15 2011 benoit ngo

#ifndef		__EXEPT_READ_HPP__
# define	__EXEPT_READ_HPP__
# include	<iostream>
# include	<string>
# include	<sstream>
# include	<stdexcept>

class exept_read : public std::exception
{
public :

  exept_read(const std::string & Msg):
    _msg(Msg)
  {
  };

  virtual ~exept_read() throw() {};

  virtual const char * What() const throw()
  {
    return (this->_msg.c_str());
  };

private :

  std::string		_msg;

};

#endif		/*__EXEPT_READ_HPP__*/
