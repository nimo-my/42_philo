# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 18:14:43 by jisookim          #+#    #+#              #
#    Updated: 2022/08/06 20:36:39 by jisookim         ###   ########.fr        #
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
SRCS		:=	main.c \
				fork.c \
				init_info.c \
				philo_init.c \
				philo_do.c \
				print.c
SRCS		:=	$(addprefix $(SRCS_DIR)/, $(SRCS))

# p_func
FSRCS_DIR	:=	./p_func
FSRCS		:=	p_atoi.c \
				p_malloc.c \
				p_memset.c \
				p_memcpy.c \
				p_error.c \
				p_strlen.c
FSRCS		:=	$(addprefix $(FSRCS_DIR)/, $(FSRCS))

# objs
OBJS_DIR	:=	./
OBJS		:=	$(SRCS:.c=.o)
OBJS		+=	$(FSRCS:.c=.o)

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
