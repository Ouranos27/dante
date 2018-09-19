/*
** main.c for dante in /home/amaury/delivery/dante/solver
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sat May 13 18:37:19 2017 Amaury Bernard
** Last update Sat May 13 18:37:19 2017 Amaury Bernard
*/

#include <unistd.h>
#include <stdlib.h>
#include "solver.h"

static void	draw_map(t_map *map)
{
  write(1, map->tab[0], map->max.x * map->max.y + map->max.x - 1);
  write(1, "\n", 1);
}

int		main(int ac, char **av)
{
  t_map		*map;

  if (ac != 2
      || !(map = map_filling(av[1])))
    return (ERR_FATAL);
  if (solver(map) == ERR_NO_SOL)
    {
      write(1, "no solution found\n", 19);
      return (0);
    }
  draw_map(map);
  return (0);
}
