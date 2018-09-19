/*
** update_radar.c for dante in /home/amaury/delivery/dante/generator
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sat May 13 16:52:25 2017 Amaury Bernard
** Last update Sat May 13 16:52:25 2017 Amaury Bernard
*/

#include <stdlib.h>
#include "generator.h"

static void	up_free_place(int x, int y, int *idx, t_co *free_place)
{
  free_place[*idx].x = x;
  free_place[*idx].y = y;
  *idx += 1;
}

void		update_radar(t_radar *to_up, const int x,
			     const int y, char **map)
{
  to_up->nb_free = 0;
  if (!to_up->free_place
      && !(to_up->free_place = malloc(sizeof(t_co) * (MAX_PLACE + 1))))
    exit(ERR_FATAL);
  if ((x - 1 >= 0 && map[x - 1][y] == 'X')
      && ((x - 2 <= 0 || map[x - 2][y] == 'X')
	  && (y - 1 <= 0 || map[x - 1][y - 1] == 'X')
	  && (map[x - 1][y + 1] == 0 || map[x - 1][y + 1] == 'X')))
    up_free_place(x - 1, y, &(to_up->nb_free), to_up->free_place);
  if ((map[x + 1] != NULL && map[x + 1][y] == 'X')
      && ((map[x + 2] == NULL || map[x + 2][y] == 'X')
	  && (y - 1 <= 0 || map[x + 1][y - 1] == 'X')
	  && (map[x + 1][y + 1] == 0 || map[x + 1][y + 1] == 'X')))
    up_free_place(x + 1, y, &(to_up->nb_free), to_up->free_place);
  if ((y - 1 >= 0 && map[x][y - 1] == 'X')
      && ((y - 2 <= 0 || map[x][y - 2] == 'X')
	  && (x - 1 <= 0 || map[x - 1][y - 1] == 'X')
	  && (map[x][y - 1] == 0 || map[x][y - 1] == 'X')))
    up_free_place(x, y - 1, &(to_up->nb_free), to_up->free_place);
  if (map[x][y + 1] == 'X'
      && ((map[x][y + 2] == '\0' || map[x][y + 2] == 'X')
	  && (x - 1 <= 0 || map[x - 1][y + 1] == 'X')
	  && (map[x + 1] == NULL || map[x + 1][y + 1] == 'X')))
    up_free_place(x, y + 1, &(to_up->nb_free), to_up->free_place);
}
