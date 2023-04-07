# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 18:57:30 by dgarizad          #+#    #+#              #
#    Updated: 2023/04/05 22:18:01 by dgarizad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = server.c 
SRC_CLIENT = client.c 

OBJS_SERVER = $(SRC_SERVER:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
  
all: $(NAME_SERVER) $(NAME_CLIENT)

%.o: %.c
	@$(CC) -c $< -o $@ -Wall -Wextra -Werror

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	@$(CC) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER) -Wall -Wextra -Werror

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	@$(CC) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT) -Wall -Wextra -Werror

$(LIBFT):
	@make -C ./libft

# start:
# 	@clear
# 	@echo "Starting compilation..."
# 	@sleep 0.2
# 	@echo "3"
# 	@sleep 0.2
# 	@echo "2"
# 	@sleep 0.2
# 	@echo "1"
# 	@sleep 0.2
clean :
	rm  -f *.o
fclean: clean
		rm -f $(NAME_SERVER)
		make fclean -C ./libft
re: fclean all
.PHONY : all clean fclean re 