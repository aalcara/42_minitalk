# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 14:31:43 by aalcara-          #+#    #+#              #
#    Updated: 2021/07/09 11:34:45 by aalcara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
FLAGS = -Wall -Werror -Wextra -fsanitize=address
LIBFT = libft.a
LIBS = -Llibft -lft
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
CC = clang

all: $(LIBFT) $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(LIBFT):
	@make --no-print-directory -C libft

$(SERVER): obj/$(SERVER).o
	@$(CC) $(FLAGS) $^ $(LIBS) -o $@
	@printf "** server made **\n"

$(CLIENT): obj/$(CLIENT).o
	@$(CC) $(FLAGS) $^ $(LIBS) -o $@
	@printf "** client made **\n"

bonus: $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): obj/$(SERVER_BONUS).o
	@$(CC) $(FLAGS) $^ $(LIBS) -o $(SERVER)
	@printf "** bonus server made **\n"

$(CLIENT_BONUS): obj/$(CLIENT_BONUS).o
	@$(CC) $(FLAGS) $^ $(LIBS) -o $(CLIENT)
	@printf "** bonus client made **\n"

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(FLAGS) $< -c -I inc -o $@

clean:
	@make clean --no-print-directory -C libft
	@rm -fr obj
	@printf "!! .o files deleted !!\n"

fclean: clean
	@make fclean --no-print-directory -C libft
	@rm -f $(SERVER) $(CLIENT)
	@printf "!! server and client files deleted !!\n"

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus