##
## Makefile for  in /home/ngo_b//rendu/proj/zappy/clientsrc/ia
##
## Made by benoit ngo
## Login   <ngo_b@epitech.net>
##
## Started on  Tue Jun 21 14:47:10 2011 benoit ngo
## Last update Sun Jul 10 18:19:35 2011 benoit ngo
##

NAMEIA		= client_ia

SRCSIA		= client.cpp		\
		  convertToInt.cpp	\
		  main.cpp		\
		  s_case.cpp		\
		  drone.cpp		\
		  epur_str.cpp		\
		  s_stone.cpp		\
		  requirLvl.cpp		\
		  check_string.cpp

OBJSIA		= $(SRCSIA:.cpp=.o)

RM		= rm -f

CC		= g++

all		: $(NAMEIA)

$(NAMEIA)	: $(OBJSIA)
		$(CC) -o $(NAMEIA) $(OBJSIA)

clean		:
		$(RM) $(OBJSIA)

fclean		: clean
		$(RM) $(NAMEIA)

re		: fclean all