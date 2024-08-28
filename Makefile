# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 13:45:36 by zvandeven         #+#    #+#              #
#    Updated: 2024/08/13 13:59:37 by zvandeven        ###   ########.fr        #
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
OBJSCLIENT		= $(addprefix $(BINDIR), $(CLIENT_S:.c=.o))
OBJSSERVER		= $(addprefix $(BINDIR), $(SERVER_S:.c=.o))

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

$(SERVER): $(BINDIR) $(OBJSSERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJSSERVER) $(LIBFT)
		@echo "$(G)\n -- $(SERVER) made 🐙 --$(RT)"

$(CLIENT): $(OBJSCLIENT) $(LIBFT) 
	$(CC) $(CFLAGS)  -o $@ $(OBJSCLIENT) $(LIBFT)
		@echo "$(G)\n -- $(CLIENT) made 🐙 --$(RT)"
		
$(BINDIR) :
	mkdir $(BINDIR)
	
$(BINDIR)%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
$(LIBFT):
	@$(MAKE) -C libft

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