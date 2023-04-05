# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 13:45:36 by zvandeven         #+#    #+#              #
#    Updated: 2023/04/05 11:57:04 by zvan-de-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RT	= \033[0m
G	= \033[0;32m

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Program name
NAME 			= minitalk
SERVER 			= server
CLIENT 			= client

# Compiler and flags
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g 

# others
RM				= rm -f
MAKE			= make

# Objects are all .o files
OBJS 			= $(addprefix $(BINDIR), $(SERVER_S:.c=.o))
BINDIR			= bin/

# library and source files
LIBFT			= libft/libft.a
SERVER_S		= server.c minitalk_utils.c 
CLIENT_S  		= client.c minitalk_utils.c 
CLIENT_BONUS	= client_bonus.c minitalk_utils.c
SERVER_BONUS	= server_bonus.c minitalk_utils.c

#------------------------------------------------------------------------------#
#                                 RULES                                        #
#------------------------------------------------------------------------------#

all: $(SERVER) $(CLIENT)

$(SERVER): $(BINDIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) -o $@ $(SERVER_S)
		@echo "$(G)\n -- $(SERVER) made 🐙 --$(RT)"

$(BINDIR) :
	mkdir $(BINDIR)
	
$(BINDIR)%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
$(LIBFT):
	@$(MAKE) -C libft

$(CLIENT): $(CLIENT_S)
	$(CC) $(CFLAGS) $(LIBFT) -o $@ $(CLIENT_S)
		@echo "$(G)\n -- $(CLIENT) made 🐙 --$(RT)"
	
bonus: 
	@$(MAKE) "CLIENT_S=$(CLIENT_BONUS)" "SERVER_S=$(SERVER_BONUS)" "SERVER = server_bonus" "CLIENT = client_bonus"
	
clean:
	@$(RM) $(OBJS)
	@$(RM) $(BINDIR)client.o
	@$(RM) -r $(BINDIR)
	@$(MAKE) -C libft clean

fclean: clean
	@$(RM) $(SERVER)
	@$(RM) $(CLIENT) 
	@$(RM) server_bonus
	@$(RM) client_bonus
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY:		all bonus clean fclean re