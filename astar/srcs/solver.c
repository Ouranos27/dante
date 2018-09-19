/*
** solver.c for  in /home/amaury/delivery/dante/astar
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sun May 14 16:50:30 2017 Amaury Bernard
** Last update Sun May 14 16:50:30 2017 Amaury Bernard
*/

#include <math.h>
#include <stdlib.h>
#include "solver.h"

static void	get_new_cell(t_co *cell, t_radar *around_cell, t_map *map)
{
  int		i_place;
  int		low;
  int		calc;
  int		i_save;

  low = - 1;
  i_place = 0;
  while (i_place < around_cell->nb_free)
    {
      calc = pow(map->max.x - around_cell->free_place[i_place].x, 2)
	+ pow(map->max.y - around_cell->free_place[i_place].y, 2);
      if (low == -1 || low > calc)
	{
	  i_save = i_place;
	  low = calc;
	}
      ++i_place;
    }
  cell->x = around_cell->free_place[i_save].x;
  cell->y = around_cell->free_place[i_save].y;
}

int		solver(t_map *map)
{
  t_lst_co	*stack;
  t_co		cell;
  t_radar	around_cell;

  cell.x = 0;
  cell.y = 0;
  around_cell.free_place = NULL;
  stack = NULL;
  while (map->tab[map->max.x - 1][map->max.y - 1] != 'o')
    {
      map->tab[cell.x][cell.y] = 'o';
      update_radar(&around_cell, cell.x, cell.y, map->tab);
      if (around_cell.nb_free == 0
	  && (!(stack = back_in_stack(&cell, stack))))
	return (ERR_NO_SOL);
      if (around_cell.nb_free > 0)
	{
	  if (around_cell.nb_free >= 2
	      && !(stack = add_to_stack(cell.x, cell.y, stack)))
	    return (ERR_FATAL);
	  get_new_cell(&cell, &around_cell, map);
	}
    }
  return (0);
}
