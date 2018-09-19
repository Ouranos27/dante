##
## Makefile for  in /home/amaury/delivery/dante
## 
## Made by Amaury Bernard
## Login   <amaury.bernard@epitech.eu>
## 
## Started on  Tue May  9 17:38:38 2017 Amaury Bernard
## Last update Tue May  9 17:38:38 2017 Amaury Bernard
##

MAKE	=	make -s -C

all: generator astar

generator:
	$(MAKE) generator

astar:
	$(MAKE) astar

re:
	$(MAKE) generator re
	$(MAKE) astar re

clean:
	$(MAKE) generator clean
	$(MAKE) astar clean

fclean:
	$(MAKE) generator fclean
	$(MAKE) astar fclean

.PHONY: all clean fclean re generator astar
