##
## Makefile for dante in /home/ouranos27/my_desktop/dante/astar
## 
## Made by philippe kam
## Login   <philippe.kam@epitech.eu>
## 
## Started on  Tue May  9 14:09:05 2017 philippe kam
## Last update Tue May  9 14:09:05 2017 philippe kam
##

CC	=	gcc

CFLAGS	+=	-Wall -Wextra

SRC	=	dfs.c		\
		open_file.c

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

debug: CFLAGS += -g -g3
debug:	fclean $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all


.PHONY: all clean fclean re
