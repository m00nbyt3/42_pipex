# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycarro <ycarro@student.42.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 12:26:21 by ycarro            #+#    #+#              #
#    Updated: 2022/01/13 15:48:52 by ycarro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

CC := gcc

HDIR := include/
INCLUDE :=  -I $(HDIR)
HEADERFILES := include/pipex.h

SRCFILES := errors.c \
			utils.c \
			utils2.c \
			free_matrix.c \
			paths.c \
			assign.c \
			pipex.c \
			main.c

OBJFILES := $(SRCFILES:%.c=obj/%.o)

CFLAGS := -Wall -Wextra -Werror $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJFILES)
	$(CC) $(OBJFILES) -o $@

obj/%.o: src/%.c $(HEADERFILES)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
		rm -f $(OBJFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re