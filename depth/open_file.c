/*
** open_file.c for dante.c in /home/ouranos27/my_desktop/dante/astar
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Tue May  9 16:14:54 2017 philippe kam
** Last update Tue May  9 16:14:54 2017 philippe kam
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "dfs.h"

static int	count_height(char *buffer)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  j = 0;
  while (i < strlen(buffer))
    {
      if (buffer[i] == '\n')
	++j;
      ++i;
    }
  if (buffer[i] == '\0')
    ++j;
  return (j);
}

static int	count_width(char *buffer)
{
  int		i;

  i = 0;
  while (buffer[i] != '\n' && buffer[i] != '\0')
    ++i;
  return (i);
}

static char	*open_file(char *path)
{
  int		fd;
  char		*buffer;
  struct stat	file;

  if ((stat(path, &file) == -1)
      || (fd = open(path, O_RDONLY)) == -1
      || ((buffer = malloc(sizeof(char) * (file.st_size + 1))) == NULL)
      || read(fd, buffer, file.st_size) == -1
      || close(fd) == -1)
    return (NULL);
  buffer[file.st_size] = '\0';
  return (buffer);
}

static int	fill_tab(char *buffer, t_map *map)
{
  char		**tab;
  int		i;
  int		i_tab;

  i = 0;
  i_tab = 0;
  if ((tab = malloc(sizeof(char *) * (map->max.x + 1))) == NULL)
    return (ERR_FATAL);
  tab[i_tab++] = buffer;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n' && buffer[i + 1] != 0)
	tab[i_tab++] = &buffer[i + 1];
      ++i;
    }
  tab[i_tab] = NULL;
  map->tab = tab;
  return (0);
}

t_map		*map_filling(char *path)
{
  char		*buffer;
  t_map		*map;

  if ((buffer = open_file(path)) == NULL
      || (map = malloc(sizeof(t_map))) == NULL)
    return (NULL);
  map->max.x = count_height(buffer);
  map->max.y = count_width(buffer);
  if (fill_tab(buffer, map) == ERR_FATAL)
    return (NULL);
  return (map);
}
