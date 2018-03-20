##
## Makefile for malloc in /home/chouik_e/Tek/Tek2/PSU_2016_malloc
##
## Made by Eddy Chouikha
## Login   <chouik_e@epitech.net>
##
## Started on  Wed Jan 25 17:06:48 2017 Eddy Chouikha
## Last update Sun Feb 12 05:07:15 2017 Loïs Antoine

CC		= gcc

RM		= rm -rf

CFLAGS		+= -Wextra -Wall -Werror -Iinclude -fpic

NAME		= libmy_malloc.so

SRCS		= srcs/malloc.c \
		  srcs/realloc.c \
		  srcs/free.c \
		  srcs/tools.c \
		  srcs/utils.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -shared -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
