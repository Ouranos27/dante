/*
** generators.c for dante in /home/amaury/delivery/dante/generator
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Tue May  9 14:20:18 2017 Amaury Bernard
** Last update Tue May  9 14:20:18 2017 Amaury Bernard
*/

#include <time.h>
#include <stdlib.h>
#include "generator.h"

static int	get_rand_nb(int nb_min, int nb_max)
{
  int		nb_rand;
  static int	srand_seed = 0;

  if (nb_max - nb_min <= 0)
    return (0);
  srand_seed += 1;
  srand(time(NULL) + srand_seed);
  ++nb_max;
  nb_rand = rand() % (nb_max - nb_min) + nb_min;
  return (nb_rand);
}

static void	get_n_mark_new_cell(t_co *cell, t_radar *around_cell, char **map)
{
  int		rand;

  rand = get_rand_nb(0, around_cell->nb_free - 1);
  cell->x = around_cell->free_place[rand].x;
  cell->y = around_cell->free_place[rand].y;
  map[cell->x][cell->y] = '*';
}

static char	**map_reg(char **map)
{
  t_co		pos;

  pos.x = 0;
  while (map[pos.x] != NULL)
    {
      pos.y = 0;
      while (map[pos.x][pos.y] != 0)
	{
	  map[pos.x][pos.y] = 'X';
	  ++pos.y;
	}
      ++pos.x;
    }
  return (map);
}

int		generator_imperfect(int x, int y, char **map)
{
  return (generator_perfect(x, y, map));
}

int		generator_perfect(int max_x, int max_y, char **map)
{
  t_radar	around_me;
  t_co		here;
  t_lst_co	*stack;

  stack = NULL;
  here.x = 0;
  here.y = 0;
  map[here.x][here.y] = '*';
  around_me.free_place = NULL;
  while (map[max_x - 1][max_y - 1] == 'X')
    {
      if (!(stack = add_to_stack(here.x, here.y, stack)))
	return (ERR_FATAL);
      update_radar(&around_me, here.x, here.y, map);
      if (around_me.nb_free == 0)
	{
	  if (!(stack = back_in_stack(&here, stack)))
	    return (generator_perfect(max_x, max_y, map_reg(map)));
	}
      else
	get_n_mark_new_cell(&here, &around_me, map);
    }
  free_stack(stack);
  return (0);
}
