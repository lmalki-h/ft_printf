# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 17:25:27 by lmalki-h          #+#    #+#              #
#    Updated: 2020/02/06 16:24:31 by lmalki-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB_DIR = libft/
LIBFT = $(addprefix $(LIB_DIR), libft.a)

EXT = c
CC = gcc
CFLAGS = -Wall -Wextra -Werror 

SRC_NAME =  ft_printf.c \
			parser.c \
		   	format_c.c \
			format_s.c \
		   	ft_printf_utils.c \
		   	ft_printf_utils2.c \
			formatting.c \
			format_x.c \
			format_u.c \
			format_di.c \
			format_p.c \
			flag_bonus.c \

OBJS = $(SRC_NAME:.$(EXT)=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	ar rcs $@ $(OBJS)
	ranlib $@

$(LIBFT):
	make -C $(LIB_DIR)
	cp $(LIBFT) ./$(NAME)

clean:
	/bin/rm -rf $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)
	@make fclean -C $(LIB_DIR)

re: fclean
	make

bonus: $(NAME)

norm:
	norminette

.PHONY: all clean fclean norm
