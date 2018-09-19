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
		srcs/open_file.c	\
		srcs/solver.c	\
		srcs/stack.c	\
		srcs/update_radar.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	solver

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(INFLAGS) -lm

debug: CFLAGS += -g -g3
debug: fclean $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
