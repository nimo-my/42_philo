# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 18:14:43 by jisookim          #+#    #+#              #
#    Updated: 2022/07/31 20:10:37 by jisookim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
RM			:=	rm -f
AR			:=	ar
ARFLAGS		:=	rcus
SANITIZE	:=	-fsanitize=address -g3

NAME		:=	philo

# srcs
SRCS_DIR	:=	./src
SRCS		:=	main.c
SRCS		:=	$(addprefix $(SRCS_DIR)/, $(SRCS))

# objs
OBJS_DIR	:=	./
OBJS		:=	$(SRCS:.c=.o)

# header
INCLUDE_DIR	:=	./include
INCLUDE	:=	philo.h

INCLUDE	:=	$(addprefix $(INCLUDE_DIR)/, $(INCLUDE))


$(NAME)		:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o			: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

# make commands
.PHONY		:	all
all			:	$(NAME)

.PHONY		:	clean
clean		:
	$(RM) $(OBJS)

.PHONY		:	fclean
fclean		:	clean
	$(RM) $(NAME)

.PHONY		:	re
re			:
	$(MAKE) fclean
	$(MAKE) all