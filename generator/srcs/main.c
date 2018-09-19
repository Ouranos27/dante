/*
** main.c for dante in /home/amaury/delivery/dante/generator
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Tue May  9 14:03:52 2017 Amaury Bernard
** Last update Tue May  9 14:03:52 2017 Amaury Bernard
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "generator.h"

static char	**map_malloc(int x, int y)
{
  char		**map;
  int		use_y;

  if (!(map = malloc(sizeof(char *) * (x + 1))))
    return (NULL);
  map[x] = NULL;
  while (--x >= 0)
    {
      use_y = -1;
      if (!(map[x] = malloc(sizeof(char) * (y + 1))))
	return (NULL);
      while (++use_y < y)
	map[x][use_y] = 'X';
      map[x][y] = 0;
    }
  return (map);
}

int		draw_map(char **map)
{
  int		i;

  i = 0;
  while (map[i] != NULL)
    {
      if (printf("%s\n", map[i]) == -1)
	return (ERR_FATAL);
      wait(100);
      ++i;
    }
  return (0);
}

int		main(int ac, char **av)
{
  char		**map;
  t_co		max;

  if (ac < 3 || ac > 4
      || my_str_isnum(av[1]) == FALSE
      || my_str_isnum(av[2]) == FALSE)
    return (ERR_FATAL);
  max.x = atoi(av[1]);
  max.y = atoi(av[2]);
  if ((max.x <= 0) || (max.y <= 0) || !(map = map_malloc(max.x, max.y)))
    return (ERR_FATAL);
  if (ac == 3)
    {
      if (generator_imperfect(max.x, max.y, map) == ERR_FATAL)
	return (ERR_FATAL);
    }
  else if (ac == 4 && strcmp(av[3], "perfect") == 0)
    {
      if (generator_perfect(max.x, max.y, map) == ERR_FATAL)
	return (ERR_FATAL);
    }
  else
    return (ERR_FATAL);
  draw_map(map);
  return (0);
}
