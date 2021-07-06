# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 14:31:43 by aalcara-          #+#    #+#              #
#    Updated: 2021/07/06 18:11:06 by aalcara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
FLAGS = -Wall -Werror -Wextra
LIBFT = libft.a
LIBS = -L./libft -lft

all: $(LIBFT) $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(LIBFT):
	@printf "** Make libft ...\n"
	@make --no-print-directory -C libft
	@printf "... libft made **\n"

$(SERVER): obj/server.o inc/minitalk.h
	@gcc $^ $(LIBS) -o $@
	@printf "** server made **\n"

$(CLIENT): obj/client.o inc/minitalk.h
	@gcc $^ $(LIBS) -o $@
	@printf "** client made **\n"

obj/%.o: src/%.c
	@mkdir -p obj
	@gcc $(FLAGS) $< -c -I inc -o $@

clean:
	@make clean --no-print-directory -C libft
	@rm -fr obj
	@printf "!! .o files deleted !!\n"

fclean: clean
	@make fclean --no-print-directory -C libft
	@rm -f $(SERVER) $(CLIENT)
	@printf "!! server and client files deleted !!\n"

re: fclean all
