# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkrief  <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 09:33:30 by alecott           #+#    #+#              #
#    Updated: 2018/02/20 11:15:22 by Raphael          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = libft.a

LIB_PATH = ./libft/

LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

NAME = fdf

CFLAGS = -Wall -Werror -Wextra -I /usr/local/include

FLAGS = -L /usr/local/lib/ -lmlx -framework OpenGl -framework Appkit

INC = fdf.h

SRCS_PATH = ./srcs

ALL_SRCS = 	main.c key_hook.c handlekc.c ft_get_coef.c ft_checkgrid.c \
			ft_take_doc.c ft_parsing.c ft_all.c ft_graph.c ft_next.c

SRCS = $(addprefix $(SRCS_PATH)/, $(ALL_SRCS))

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@$(MAKE) -C libft
	gcc $(CFLAGS) $(OBJ) $(FLAGS) -L libft -lft -o $(NAME)

$(SRCS_PATH)/%.o: $(SRCS_PATH)/%.c
	gcc -c $< -o $@ $(CFLAGS)

clean:
	$(MAKE) -C libft $@
	/bin/rm -f $(LIB_OBJ)
	/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft $@
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

run: re
	$(MAKE) clean

.PHONY: all clean fclean re
