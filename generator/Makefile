##
## Makefile for usefull  in /home/amaury/delivery/usefull
## 
## Made by Amaury Bernard
## Login   <amaury.bernard@epitech.eu>
## 
## Started on  Tue May  9 13:53:34 2017 Amaury Bernard
## Last update Tue May  9 13:53:34 2017 Amaury Bernard
##

CC	=	gcc

RM	=	rm -f

INFLAGS	=	-Iincludes

CFLAGS	+=	-Wextra -Wall $(INFLAGS)

SRCS	=	srcs/main.c	\
		srcs/generators.c	\
		srcs/stack.c	\
		srcs/update_radar.c	\
		srcs/my_str_isnum.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	generator

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(INFLAGS)

debug: CFLAGS += -g -g3
debug: fclean $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
