//
// client.hh for  in /home/ngo_b//rendu/proj/zappy/clientsrc/ia
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Tue Jun 21 12:59:02 2011 benoit ngo
// Last update Wed Jun 29 15:44:00 2011 benoit ngo
//

#ifndef		__CLIENT_HH__
# define	__CLIENT_HH__
# include "ConvertToInt.hh"
# include "s_case.hh"
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string>
# include <vector>

class		Client
{
  struct protoent *	_pe;
  int			_socket;
  struct sockaddr_in	_s;
  const std::string	_ip;
    int			_port;
  fd_set	       	_champ_read;
  fd_set	       	_champ_write;
  timeval		_tv;
public:
  std::string		_buffer_write;
  int			nb_command_send;
  int			nb_rec;
  void			fill_command_to_buffer(std::string &);
  Client(const std::string & ip, int port, const std::string & teamName);
  ~Client();
  void			watch(std::string &);
  void			read(std::string &);
  void			write(const std::string &);
  bool			do_select();
  bool			fd_isset_write();

  const std::string	_teamName;
};


#endif		/*__CLIENT_HH__*/
