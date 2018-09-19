/*
** dfs.h for dante in /home/ouranos27/my_desktop/dante/depth
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Thu May 11 17:21:07 2017 philippe kam
** Last update Thu May 11 17:21:07 2017 philippe kam
*/

#ifndef DFS_H_
# define DFS_H_

# define ERR_FATAL	84
# define SUCCESS	0
# define STAR		'*'
# define CROSSED	'o'

typedef struct		s_co
{
  int			x;
  int			y;
}			t_co;

typedef struct		s_lst_co
{
  t_co			co;
  struct s_lst_co	*prev;
}			t_lst_co;

typedef struct		s_map
{
  char			**tab;
  t_co			max;
}			t_map;

t_map		*map_filling(char *);
int		solver(t_map *, t_co);
void		print_map(char **);

#endif /* !DFS */
