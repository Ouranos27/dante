/*
** dfs.c for dante in /home/ouranos27/my_desktop/dante/depth
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Thu May 11 17:19:07 2017 philippe kam
** Last update Thu May 11 17:19:07 2017 philippe kam
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "dfs.h"

int		solver(t_map *map, /*t_list_co *stack,*/ t_co pos)
{
  while (map->tab[map->max.x - 1][map->max.y - 1] != 'o')
    {

      //map->tab[pos.x][pos.y] = 'a';
    }
  return (SUCCESS);
}

void		bttf(t_map *map)
{
  int		i;
  int		j;

  i = 0;
  while (map->tab[i])
    {
      j = 0;
      while (map->tab[i][j])
	{
	  if (map->tab[i][j] == 'a')
	    map->tab[i][j] = '*';
	  ++j;
	}
      ++i;
    }
}

void		print_map(char **map)
{
  write(1, *map, strlen(*map));
}

int		dfs(char *path)
{
  t_map		*map;
  //t_lst_co	*stack;
  t_co		pos;

  //stack = NULL;
  pos.x = 0;
  pos.y = 0;
  if (!(map = map_filling(path)))
    return (ERR_FATAL);
  if (solver(map, pos) == ERR_FATAL)
    {
      printf("Ehhhhh nique ta mere\n");
      return (ERR_FATAL);
    }
  bttf(map);
  print_map(map->tab);
  return (SUCCESS);
}

int	main(int ac, char **av)
{
  if (ac != 2)
    return (0);
  if (dfs(av[1]) == ERR_FATAL)
    return (ERR_FATAL);
  return (0);
}
