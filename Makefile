##
## Makefile for  in /u/epitech_2014/capot_r/public/42sh/42Sh
##
## Made by camille benhamou
## Login   <benham_a@epitech.net>
##
## Started on  Sun May 23 15:48:28 2010 camille benhamou
## Last update Sun Jul 10 20:27:06 2011 benoit ngo
##

CC		=	gcc

CPP		=	g++

NAME		=	serveur

NAME2		=	client

NAMEIA		= client_ia

DIRIA		= ia/

DIR		=	serveursrc/

DIR2		=	client_v3/

SRCS		=	$(DIR)main.c \
			$(DIR)add_client.c \
			$(DIR)add_server.c \
			$(DIR)add_ctl_team.c \
			$(DIR)add_tab.c \
			$(DIR)drone.c \
			$(DIR)drone_check.c \
			$(DIR)drone_erase.c \
			$(DIR)drone_food.c \
			$(DIR)client.c \
			$(DIR)init_data.c \
			$(DIR)select_clients.c \
			$(DIR)select_func.c \
			$(DIR)server_zappy.c \
			$(DIR)buf_manage.c \
			$(DIR)buf_count.c \
			$(DIR)check_cmd.c \
			$(DIR)check_free_space.c \
			$(DIR)food.c \
			$(DIR)request.c \
			$(DIR)request_search.c	\
			$(DIR)request_switch.c	\
			$(DIR)request_timeout.c \
			$(DIR)request_count.c	\
			$(DIR)request_next.c	\
			$(DIR)request_active.c	\
			$(DIR)req_voir.c \
			$(DIR)req_add_clt.c \
			$(DIR)req_droite.c \
			$(DIR)req_gauche.c \
			$(DIR)req_avance.c \
			$(DIR)req_inventaire.c \
			$(DIR)req_prend.c \
			$(DIR)req_prend_func.c \
			$(DIR)req_pose.c \
			$(DIR)req_pose_func.c \
			$(DIR)req_expulse.c \
			$(DIR)req_fork.c \
			$(DIR)req_connect_nbr.c \
			$(DIR)req_incantation.c \
			$(DIR)req_msz.c \
			$(DIR)req_bct.c \
			$(DIR)req_mct.c \
			$(DIR)req_pnw.c \
			$(DIR)req_seg.c \
			$(DIR)req_sgt.c \
			$(DIR)req_sst.c \
			$(DIR)req_smg.c \
			$(DIR)req_pex.c \
			$(DIR)req_pbc.c \
			$(DIR)req_pdi.c \
			$(DIR)req_pfk.c \
			$(DIR)req_edi.c \
			$(DIR)req_ebo.c \
			$(DIR)req_enw.c \
			$(DIR)req_eht.c \
			$(DIR)req_tna.c \
			$(DIR)req_pgt.c \
			$(DIR)req_pdr.c \
			$(DIR)str_fmt.c \
			$(DIR)timer.c \
			$(DIR)found_args.c \
			$(DIR)assign_args.c \
			$(DIR)assign_multi_arg.c \
			$(DIR)check_valid_nb.c \
			$(DIR)catch_arg.c \
			$(DIR)printcs.c \
			$(DIR)del_fd.c \
			$(DIR)exit_serv.c \
			$(DIR)close_fd.c \
			$(DIR)elevation.c \
			$(DIR)init_map.c \
			$(DIR)getBox.c \
			$(DIR)req_ppo.c \
			$(DIR)req_pin.c \
			$(DIR)req_plv.c \
			$(DIR)req_pie.c \
			$(DIR)team.c \
			$(DIR)team_check.c \
			$(DIR)req_pic.c \
			$(DIR)write_voir_syntaxe.c \
			$(DIR)voir_up.c \
			$(DIR)voir_down.c \
			$(DIR)voir_right.c \
			$(DIR)voir_left.c \
			$(DIR)eparpille_stone.c \
			$(DIR)assign_stone.c \
			$(DIR)broadcast.c \
			$(DIR)check_way.c \
			$(DIR)check_case.c \
			$(DIR)check_direction.c \
			$(DIR)graphic_info.c \
			$(DIR)team_lvl.c \
			$(DIR)x.c

SRCS2		=	$(DIR2)main.cpp	\
			$(DIR2)client2.cpp \
			$(DIR2)client.cpp \
			$(DIR2)Graphic.cpp \
			$(DIR2)xfuncs.cpp \
			$(DIR2)current_time_unit.cpp \
			$(DIR2)end_game.cpp \
			$(DIR2)get_block.cpp \
			$(DIR2)get_team_name.cpp \
			$(DIR2)incant.cpp \
			$(DIR2)map_size.cpp \
			$(DIR2)new_player.cpp \
			$(DIR2)player_bag.cpp \
			$(DIR2)player_broadcast.cpp \
			$(DIR2)player_dead_food.cpp \
			$(DIR2)player_egg.cpp \
			$(DIR2)player_level.cpp \
			$(DIR2)player_pos.cpp \
			$(DIR2)ressource.cpp \
			$(DIR2)server_cmd.cpp \
			$(DIR2)eject_player.cpp

SRCSIA			= $(DIRIA)client.cpp		\
			$(DIRIA)convertToInt.cpp	\
			$(DIRIA)main.cpp		\
			$(DIRIA)s_case.cpp		\
			$(DIRIA)drone.cpp		\
			$(DIRIA)epur_str.cpp		\
			$(DIRIA)s_stone.cpp		\
			$(DIRIA)requirLvl.cpp		\
			$(DIRIA)check_string.cpp

OBJS		=	$(SRCS:.c=.o)

OBJS2		=	$(SRCS2:.cpp=.o)

OBJSIA		=	$(SRCSIA:.cpp=.o)

RM		=	/bin/rm -f

CFLAGS		=	-W -Wall -Werror

all	: $(NAME) $(NAME2) $(NAMEIA)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lm

$(NAME2): $(OBJS2)
	$(CPP) $(OBJS2) -o $(NAME2) -lX11 -lsfml-graphics -lsfml-window -lsfml-system -lm -L./client_v3/cpGUI/lib

$(NAMEIA): $(OBJSIA)
	$(CPP) -o $(NAMEIA) $(OBJSIA)
clean	:
	$(RM) $(OBJS) $(OBJS2) $(OBJSIA) *~ \#*\#

fclean	: clean
	$(RM) $(NAME) $(NAME2) $(NAMEIA)

re	: fclean all

.c.o	:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY	: all clean fclean re