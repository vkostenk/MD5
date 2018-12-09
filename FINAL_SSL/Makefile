# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 12:14:43 by vkostenk          #+#    #+#              #
#    Updated: 2018/09/13 12:54:22 by vkostenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ssl
COMP		= gcc
RM			= rm -rf
FLAGS		= -Wall -Wextra -Werror
FILES		= ft_sha256.c\
					ft_md5.c\
					ft_message.c\
					ft_swap.c\
					ft_help.c\
					ft_main.c\
					ft_cases.c



HEADER	= -I heder/ft_ssl.h
LIB			= lib/libftprintf.a

$(NAME): $(FILES)
	$(COMP) $(FLAGS) -o $(NAME) $(FILES) $(HEADER) $(LIB)

all: $(NAME)

clean:
	$(RM) $(NAME)*

fclean: clean

re: fclean $(NAME)
